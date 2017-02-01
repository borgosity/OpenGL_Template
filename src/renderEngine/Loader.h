#pragma once
#include <glew.h>

#include "RawModel.h"

class Loader
{
public:
	Loader();
	~Loader();

	RawModel * loadToVAO(float positions[]);
	void cleanUp();

private:
	void createVAO();
	void storeDataInAttributeList(int attributeNumber, float data[]);
	void unbindVAO();
	GLuint m_iVBO, m_iVAO;

};

