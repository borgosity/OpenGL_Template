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

void Renderer::bindRenderTexture(TexturedModel * a_texturedModel)
{
	// Bind Texture
	glBindTexture(GL_TEXTURE_2D, a_texturedModel->rawModel().vaoID());
	glBindVertexArray(a_texturedModel->rawModel().vaoID());
	glDrawElements(GL_TRIANGLES, a_texturedModel->rawModel().vertexCount(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Renderer::bindTexture(TexturedModel * a_texturedModel, ShaderProgram * a_shader, const char * a_uniformName, int a_texNumber )
{
	glBindTexture(GL_TEXTURE_2D, a_texturedModel->rawModel().vaoID());
	glUniform1i(glGetUniformLocation(a_shader->spID(), a_uniformName), a_texNumber);
}

void Renderer::renderTexture(TexturedModel * a_texturedModel)
{
	glBindVertexArray(a_texturedModel->rawModel().vaoID());
	glDrawElements(GL_TRIANGLES, a_texturedModel->rawModel().vertexCount(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}