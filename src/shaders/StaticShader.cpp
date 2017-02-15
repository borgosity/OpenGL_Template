#include "StaticShader.h"



StaticShader::StaticShader()
{
	bindAttributes();
}


StaticShader::~StaticShader()
{
}

void StaticShader::bindAttributes()
{
	bindAttribute(0, "position");
}


