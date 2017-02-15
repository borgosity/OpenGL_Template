#include "StaticShader.h"
#include "ShaderFileList.h"



StaticShader::StaticShader() : ShaderProgram(STATIC_VERTEX_FILE, STATIC_FRAGMENT_FILE)
{
	std::cout << "Derived Class" << std::endl;

	bindAttributes();
}


StaticShader::~StaticShader()
{
}

void StaticShader::bindAttributes()
{
	bindAttribute(0, "position");
}


