#pragma once
#include "RawModel.h"
#include <glew.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	void prepare(int red, int green, int blue);
	void render(RawModel * model, GLuint shaderProgram);
};

