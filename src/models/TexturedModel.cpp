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

TexturedModel::~TexturedModel()
{
}
