#pragma once
#include <iostream>
#include <glew.h>
#include <glm.hpp>

#include "Shaders.h"

class ShaderProgram
{
public:
	ShaderProgram();
	ShaderProgram(ShaderPath a_shaderPath);
	virtual ~ShaderProgram();
	// shader control
	void start();
	void stop();
	void cleanUp();
	// uniform functions
	void uniform4f(const GLchar * a_uniformName, glm::vec4 & a_values);
	void uniform3f(const GLchar * a_uniformName, glm::vec3 & a_values);
	void uniform2f(const GLchar * a_uniformName, glm::vec2 & a_values);
	// variable accessors
	GLuint spID() { return m_uiProgramID; };

	/*
		the below was commented out in favour of attribute binding in shader files
	*/
	// this function must be implemented by the derived class
	// virtual void bindAttributes() = 0;
	// void bindAttribute(GLuint a_attribute, const GLchar * a_variableName);
	
private:
	GLuint m_uiProgramID;
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

