
#pragma once
#include <string>
#include <glew.h>

struct ShaderPath
{
	std::string vertexShader;
	std::string fragmentShader;
};

struct Shader
{
	static ShaderPath cameraShader;
	static ShaderPath colourShader;
	static ShaderPath dualTextureShader;
	static ShaderPath indexShader; 
	static ShaderPath lampShader;
	static ShaderPath lightShader;
	static ShaderPath modelShader;
	static ShaderPath meshShader;
	static ShaderPath phongShader;
	static ShaderPath rippleShader;
	static ShaderPath staticShader;
	static ShaderPath textureShader;
	static ShaderPath transformShader;
	static ShaderPath uniformShader;
};




