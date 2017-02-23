#include "TexturedModel.h"


TexturedModel::TexturedModel(RawModel & a_model, Texture & a_texture)
{
	m_rawModel = &a_model;
	m_textureA = &a_texture;
	m_textureB = nullptr;
}

TexturedModel::TexturedModel(RawModel & a_model, Texture & a_textureA, Texture & a_textureB)
{
	m_rawModel = &a_model;
	m_textureA = &a_textureA;
	m_textureB = &a_textureB;
}

TexturedModel::TexturedModel(RawModel & a_model, Texture & a_textureA, Texture & a_textureB, GLuint a_shaderProgramID)
{
	m_rawModel = &a_model;
	m_textureA = &a_textureA;
	m_textureB = &a_textureB;
	m_shaderProgramID = a_shaderProgramID;
	bindTextures();
}

TexturedModel::~TexturedModel()
{
}

void TexturedModel::bindTextures()
{
	// Bind Textures using texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_textureA->ID());
	glUniform1i(glGetUniformLocation(m_shaderProgramID, "ourTexture1"), 0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_textureB->ID());
	glUniform1i(glGetUniformLocation(m_shaderProgramID, "ourTexture2"), 1);
}
