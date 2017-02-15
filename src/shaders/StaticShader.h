#pragma once
#include "ShaderProgram.h"
class StaticShader :
	public ShaderProgram
{
public:
	StaticShader();
	virtual ~StaticShader();

	virtual void bindAttributes();

private:

	const GLchar * m_cVertexFile = "src/shaders/vertexShader.txt";
	const GLchar * m_cFragmentFile= "src/shaders/fragementShader.txt";

};

