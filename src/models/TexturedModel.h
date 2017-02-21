#pragma once
#include "RawModel.h"
#include "Texture.h"

class TexturedModel
{
public:
	TexturedModel(RawModel & a_model, Texture & a_texture);
	TexturedModel(RawModel & a_model, Texture & a_textureA, Texture & a_textureB);
	~TexturedModel();

	RawModel & rawModel() { return *m_rawModel; }
	Texture & texture(unsigned int a_value) { return (a_value == 0 ? *m_textureA : *m_textureB); }

private:
	RawModel * m_rawModel;
	Texture * m_textureA;
	Texture * m_textureB;
};

