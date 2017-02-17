#pragma once
#include "RawModel.h"
#include <glew.h>
#include "TexturedModel.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void prepare(GLfloat red, GLfloat green, GLfloat blue);
	void render(RawModel * model);
	void render(RawModel * model, GLuint shaderProgram);
	void renderInd(RawModel * model);
	void renderTexture(TexturedModel * a_texturedModel);
};

