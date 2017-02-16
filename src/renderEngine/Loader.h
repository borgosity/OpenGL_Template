#pragma once
#include <iostream>
#include <glew.h>
#include <vector>

#include "RawModel.h"

class Loader
{
public:
	Loader();
	~Loader();

	RawModel * loadToVAO(GLfloat positions[], int size);
	RawModel * loadToVAO(GLfloat a_positions[], int a_size, int a_attribNum);
	void cleanUp();

private:
	void createVAO();
	void storePositionDataInAttributeList(int attributeNumber, GLfloat data[], int size);
	void storeColourDataInAttributeList(int attributeNumber, GLfloat data[], int size);
	GLuint m_iVBO, m_iVAO;

};

