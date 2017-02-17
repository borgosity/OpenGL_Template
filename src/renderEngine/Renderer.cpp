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

/// render model
void Renderer::render(RawModel * model)
{
	// Draw model
	glBindVertexArray(model->vaoID());
	glDrawArrays(GL_TRIANGLES, 0, model->vertexCount());
	glBindVertexArray(0);
}

/// render model using specific shader program
void Renderer::render(RawModel * model, GLuint shaderProgram)
{
	// Draw model
	glUseProgram(shaderProgram);
	glBindVertexArray(model->vaoID());
	glDrawArrays(GL_TRIANGLES, 0, model->vertexCount());
	glBindVertexArray(0);
}

/// render model with indicies
void Renderer::renderInd(RawModel * model)
{
	// Draw model
	glBindVertexArray(model->vaoID());
	glDrawElements(GL_TRIANGLES, model->vertexCount(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Renderer::renderTexture(TexturedModel * a_texturedModel)
{
	RawModel model = a_texturedModel->rawModel();
	glBindVertexArray(model.vaoID());
	glDrawElements(GL_TRIANGLES, model.vertexCount(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
