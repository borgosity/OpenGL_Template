#include "ShaderProgram.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



ShaderProgram::ShaderProgram(const GLchar * a_vertexShaderPath, const GLchar * a_fragmentShaderPath)
{
	m_iSuccess = 0;
	// Shaders
	m_cpVertexShaderSource = readFile(a_vertexShaderPath).c_str();
	m_cpFragmentShaderSource = readFile(a_fragmentShaderPath).c_str();

	m_uiVertexShaderID = loadShader(m_cpVertexShaderSource, GL_VERTEX_SHADER);
	m_uiFragmentShaderID = loadShader(m_cpFragmentShaderSource, GL_FRAGMENT_SHADER);
	m_uiProgramID = linkShaders(m_uiVertexShaderID, m_uiFragmentShaderID);
	
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
		std::cout << "ERROR -> Failure reading shader file" << std::endl;
	}
	// return shader source 
	m_spShaderSourceTemp = shaderSource;

	return m_spShaderSourceTemp;
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
GLuint ShaderProgram::linkShaders(GLuint a_vertexShader, GLuint a_fragmentShader)
{
	// Link shaders
	GLuint programID = glCreateProgram();
	glAttachShader(programID, a_vertexShader);
	glAttachShader(programID, a_fragmentShader);
	glLinkProgram(programID);
	// Check for linking errors
	glGetProgramiv(programID, GL_LINK_STATUS, &m_iSuccess);
	if (!m_iSuccess) {
		glGetProgramInfoLog(programID, 512, NULL, m_iInfoLog);
		std::cout << "ERROR -> SHADER PROGRAM LINKING_FAILED\n" << m_iInfoLog << std::endl;
	}
	return programID;
}


