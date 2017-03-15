#pragma once
#include "ShaderProgram.h"


class AnimeShader :
	public ShaderProgram
{
public:
	AnimeShader();
	AnimeShader(ShaderPath a_shaderPath);
	virtual ~AnimeShader();

	// load
	void update(Camera & camera, Light & a_light);

private:

};

