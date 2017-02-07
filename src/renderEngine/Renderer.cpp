#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::prepare(GLfloat red, GLfloat green, GLfloat blue)
{
	// Clear the colorbuffer
	glClearColor(red, green, blue, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(RawModel * model, GLuint shaderProgram)
{
	// Draw our first triangle
	glUseProgram(shaderProgram);
	glBindVertexArray(model->vaoID());
	glDrawArrays(GL_TRIANGLES, 0, model->vertexCount());
	glBindVertexArray(0);
}
