#pragma once
#include <iostream>
#include <glew.h>
#include <glm.hpp>

class ShaderProgram
{
public:
	ShaderProgram();
	ShaderProgram(const GLchar * a_vertexShaderPath, const GLchar * a_fragmentShaderPath);
	virtual ~ShaderProgram();

	void start();
	void stop();
	void cleanUp();
	GLuint spID() { return m_uiProgramID; };

	// this function must be implemented by the derived class
	virtual void bindAttributes() = 0;
	void bindAttribute(GLuint a_attribute, const GLchar * a_variableName);
	
protected:
	GLuint m_uiProgramID;

private:
	GLuint m_uiVertexShaderID;
	GLuint m_uiFragmentShaderID;
	GLint m_iSuccess;
	GLchar m_iInfoLog[512];

	// Shaders
	std::string m_spShaderSourceTemp;
	const GLchar * m_cpVertexShaderSource;
	const GLchar * m_cpFragmentShaderSource;

	// private functions
	std::string & readFile(const GLchar * a_filePath);
	void readFiles(const GLchar * a_vsFilePath, const GLchar * a_fsFilePath);
	GLuint loadShader(const GLchar * a_shaderSource, GLuint a_shaderType);
	void linkShaders(GLuint a_vertexShader, GLuint a_fragmentShader);

};

