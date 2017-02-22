
#pragma once
#include <string>
#include <glew.h>

struct ShaderPath
{
	const GLchar * vertexShader;
	const GLchar * fragmentShader;
};

struct Shader
{
	static ShaderPath cameraShader;
	static ShaderPath staticShader;
	static ShaderPath indexShader;
	static ShaderPath textureShader;
	static ShaderPath transformShader;
	static ShaderPath dualTextureShader;
	static ShaderPath uniformShader;
};




