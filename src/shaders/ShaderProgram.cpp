#include "ShaderProgram.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


ShaderProgram::ShaderProgram()
{
	m_cpVertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
	"}\0";
	m_cpFragmentShaderSource = "#version 330 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n\0";

	m_iSuccess = 0;
	m_uiVertexShaderID = loadShader(m_cpVertexShaderSource, GL_VERTEX_SHADER);
	m_uiFragmentShaderID = loadShader(m_cpFragmentShaderSource, GL_FRAGMENT_SHADER);
	linkShaders(m_uiVertexShaderID, m_uiFragmentShaderID);
}

ShaderProgram::ShaderProgram(const GLchar * a_vertexShaderPath, const GLchar * a_fragmentShaderPath)
{
	// Shaders
	readFiles(a_vertexShaderPath, a_fragmentShaderPath);
	m_iSuccess = 0;
	m_uiVertexShaderID = loadShader(m_cpVertexShaderSource, GL_VERTEX_SHADER);
	m_uiFragmentShaderID = loadShader(m_cpFragmentShaderSource, GL_FRAGMENT_SHADER);
	linkShaders(m_uiVertexShaderID, m_uiFragmentShaderID);
	
}


ShaderProgram::~ShaderProgram()
{
}

/// start using shader program
void ShaderProgram::start()
{
	glUseProgram(m_uiProgramID);
}

/// stop using shader program
void ShaderProgram::stop()
{
	glUseProgram(0);
}

/// clean up shaders and shader program
void ShaderProgram::cleanUp()
{
	stop();
	glDetachShader(m_uiProgramID, m_uiVertexShaderID);
	glDetachShader(m_uiProgramID, m_uiFragmentShaderID);
	glDeleteShader(m_uiVertexShaderID);
	glDeleteShader(m_uiFragmentShaderID);
	glDeleteProgram(m_uiProgramID);
}

/// bind attribute to shader program
void ShaderProgram::bindAttribute(GLuint a_attribute, const GLchar * a_variableName)
{
	glBindAttribLocation(m_uiProgramID, a_attribute, a_variableName);
}



/// pull shader code from file
std::string & ShaderProgram::readFile(const GLchar * a_filePath)
{
	m_spShaderSourceTemp = "";
	std::string shaderSource;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::badbit);

	try {
		// open file
		shaderFile.open(a_filePath);
		std::stringstream shaderStream;
		// read file buffer contents into stream
		shaderStream << shaderFile.rdbuf();
		// close file handler
		shaderFile.close();
		// convert stream
		shaderSource = shaderStream.str();
	}
	catch(std::ifstream::failure e) {
		std::cout << "ERROR -> Failure reading shader file: " << std::endl;
	}
	// return shader source 
	m_spShaderSourceTemp = shaderSource;

	return m_spShaderSourceTemp;
}

void ShaderProgram::readFiles(const GLchar * a_vsFilePath, const GLchar * a_fsFilePath)
{
	std::string vsShaderSource;
	std::ifstream vsShaderFile;
	std::string fsShaderSource;
	std::ifstream fsShaderFile;
	// allow throwing of exceptions
	vsShaderFile.exceptions(std::ifstream::badbit);
	fsShaderFile.exceptions(std::ifstream::badbit);

	try {
		// open file
		vsShaderFile.open(a_vsFilePath);
		fsShaderFile.open(a_fsFilePath);
		std::stringstream vsShaderStream;
		std::stringstream fsShaderStream;
		// read file buffer contents into stream
		vsShaderStream << vsShaderFile.rdbuf();
		fsShaderStream << fsShaderFile.rdbuf();
		// close file handler
		vsShaderFile.close();
		fsShaderFile.close();
		// convert stream
		vsShaderSource = vsShaderStream.str();
		fsShaderSource = fsShaderStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR -> Failure reading shader file: " << std::endl;
	}
	// return shader source 
	m_cpVertexShaderSource = new GLchar[vsShaderSource.length() + 1];
	m_cpFragmentShaderSource = new GLchar[fsShaderSource.length() + 1];

	strcpy((char*)m_cpVertexShaderSource, vsShaderSource.c_str());
	strcpy((char*)m_cpFragmentShaderSource, fsShaderSource.c_str());

}

/// load shader from file
GLuint ShaderProgram::loadShader(const GLchar * a_shaderSource, GLuint a_shaderType)
{
	// Vertex shader
	GLuint shaderID = glCreateShader(a_shaderType);
	glShaderSource(shaderID, 1, &a_shaderSource, NULL);
	glCompileShader(shaderID);
	// Check for compile time errors
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &m_iSuccess);
	// log failure
	if (!m_iSuccess) {
		glGetShaderInfoLog(shaderID, 512, NULL, m_iInfoLog);
		std::cout << "ERROR -> SHADER COMPILATION_FAILED\n" << m_iInfoLog << std::endl;
	}
	// return ID
	return shaderID;
}

/// link shaders to a shader program
void ShaderProgram::linkShaders(GLuint a_vertexShader, GLuint a_fragmentShader)
{
	// Link shaders
	m_uiProgramID = glCreateProgram();
	glAttachShader(m_uiProgramID, a_vertexShader);
	glAttachShader(m_uiProgramID, a_fragmentShader);
	glLinkProgram(m_uiProgramID);
	// Check for linking errors
	glGetProgramiv(m_uiProgramID, GL_LINK_STATUS, &m_iSuccess);
	if (!m_iSuccess) {
		glGetProgramInfoLog(m_uiProgramID, 512, NULL, m_iInfoLog);
		std::cout << "ERROR -> SHADER PROGRAM LINKING_FAILED\n" << m_iInfoLog << std::endl;
	}

}


