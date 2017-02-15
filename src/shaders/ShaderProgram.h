#pragma once
#include <iostream>
#include <glew.h>

class ShaderProgram
{
public:
	ShaderProgram();
	virtual ~ShaderProgram();

	void start();
	void stop();
	void cleanUp();

	// this function must be implemented by the derived class
	virtual void bindAttributes() = 0;
	void bindAttribute(GLuint a_attribute, const GLchar * a_variableName);

private:
	GLuint m_uiProgramID;
	GLuint m_uiVertexShaderID;
	GLuint m_uiFragmentShaderID;
	GLint m_iSuccess;
	GLchar m_iInfoLog[512];

	// Shaders
	const GLchar * m_cpVertexShaderSource;
	const GLchar * m_cpFragmentShaderSource;

	// private functions
	GLuint loadShader(const GLchar * a_shaderFile, GLuint a_shaderType);
	GLuint linkShaders(GLuint a_vertexShader, GLuint a_fragmentShader);

};

