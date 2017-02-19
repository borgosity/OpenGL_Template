#pragma once
#include "RawModel.h"
#include <glew.h>
#include "TexturedModel.h"
#include "ShaderProgram.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void prepare(GLfloat red, GLfloat green, GLfloat blue);
	void render(RawModel * model);
	void render(RawModel * model, GLuint shaderProgram);
	void renderInd(RawModel * model);
	void bindRenderTexture(TexturedModel * a_texturedModel);
	void renderTexture(TexturedModel * a_texturedModel);
	void bindTexture(TexturedModel * a_texturedModel, ShaderProgram * a_shader, const char * a_uniformName, int a_texNumber);
};

