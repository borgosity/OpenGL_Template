#pragma once
#include "ShaderProgram.h"



class StaticShader :
	public ShaderProgram
{
public:
	StaticShader();
	StaticShader(int a_attribNum);
	virtual ~StaticShader();

	virtual void bindAttributes();

private:

};

