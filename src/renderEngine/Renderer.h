#pragma once
#include "RawModel.h"
#include <glew.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	void prepare(GLfloat red, GLfloat green, GLfloat blue);
	void render(RawModel * model, GLuint shaderProgram);
};

