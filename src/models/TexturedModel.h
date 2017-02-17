#pragma once
#include "RawModel.h"
#include "ModelTexture.h"

class TexturedModel
{
public:
	TexturedModel(RawModel & a_model, ModelTexture & a_texture);
	~TexturedModel();

	RawModel & rawModel() { return *m_rawModel; }
	ModelTexture & texture() { return *m_texture; }

private:
	RawModel * m_rawModel;
	ModelTexture * m_texture;
};

