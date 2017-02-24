#pragma once
#include "RawModel.h"
#include "Texture.h"

class TexturedModel
{
public:
	TexturedModel(RawModel & a_model, Texture & a_texture);
	TexturedModel(RawModel & a_model, Texture & a_textureA, Texture & a_textureB);
	TexturedModel(RawModel & a_model, Texture & a_textureA, Texture & a_textureB, GLuint a_shaderProgramID);
	~TexturedModel();

	RawModel & rawModel() { return *m_rawModel; }
	Texture & texture(unsigned int a_value) { return (a_value == 0 ? *m_textureA : *m_textureB); }
	// access raw model values
	GLuint vaoID() { return m_rawModel->vaoID(); }
	GLuint vertexCount() { return m_rawModel->vertexCount(); };
	// bind textures to shader uniforms
	void bindTextures(const GLchar * a_uniformA, const GLchar * a_uniformB);
	// does the model use indeces
	bool hasIndices() { return rawModel().hasIndecies(); };

private:
	RawModel *	m_rawModel;
	Texture *	m_textureA;
	Texture *	m_textureB;
	GLuint		m_shaderProgramID;
	// private functions
};

