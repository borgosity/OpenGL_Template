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

};

