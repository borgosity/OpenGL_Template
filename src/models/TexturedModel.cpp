#include "TexturedModel.h"


TexturedModel::TexturedModel(RawModel & a_model, ModelTexture & a_texture)
{
	m_rawModel = &a_model;
	m_texture = &a_texture;
}

TexturedModel::~TexturedModel()
{
}
