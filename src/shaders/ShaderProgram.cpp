#include "ShaderProgram.h"



ShaderProgram::ShaderProgram()
{
	// Shaders
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

/// load shader from file
GLuint ShaderProgram::loadShader(const GLchar * a_shaderFile, GLuint a_shaderType)
{
	// Vertex shader
	GLuint shaderID = glCreateShader(a_shaderType);
	glShaderSource(shaderID, 1, &a_shaderFile, NULL);
	glCompileShader(shaderID);
	// Check for compile time errors
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &m_iSuccess);
	// log failure
	if (!m_iSuccess) {
		glGetShaderInfoLog(shaderID, 512, NULL, m_iInfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << m_iInfoLog << std::endl;
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
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << m_iInfoLog << std::endl;
	}
	return programID;
}


