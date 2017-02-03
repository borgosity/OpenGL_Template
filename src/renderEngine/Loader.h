#pragma once
#include <glew.h>
#include <vector>

#include "RawModel.h"

class Loader
{
public:
	Loader();
	~Loader();

	RawModel * loadToVAO(GLfloat positions[], int size);
	void cleanUp();

private:
	void createVAO();
	void storeDataInAttributeList(int attributeNumber, GLfloat data[], int size);
	void unbindVAO();
	GLuint m_iVBO, m_iVAO;

};

