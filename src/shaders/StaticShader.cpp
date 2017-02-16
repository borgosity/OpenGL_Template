#include "StaticShader.h"

// Static Shader files
const GLchar * STATIC_VERTEX_FILE = "src/shaders/vertexShader.txt";
const GLchar * STATIC_FRAGMENT_FILE = "src/shaders/fragmentShader.txt";


StaticShader::StaticShader()
{
	bindAttributes();
}

StaticShader::StaticShader(int a_attribNum) : ShaderProgram(STATIC_VERTEX_FILE, STATIC_FRAGMENT_FILE)
{
	// attributes bound in shader file
}


StaticShader::~StaticShader()
{
}

void StaticShader::bindAttributes()
{
	//bindAttribute(0, "position");	// bind the 'position' variable to position 0
	//bindAttribute(1, "color");		// bind the 'color' variable to position 1
}


