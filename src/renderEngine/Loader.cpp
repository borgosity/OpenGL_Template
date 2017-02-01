#include "Loader.h"



Loader::Loader()
{
}


Loader::~Loader()
{
}

RawModel * Loader::loadToVAO(float positions[])
{
	createVAO();
	storeDataInAttributeList(0, positions);
	unbindVAO();
	return new RawModel(m_iVAO, sizeof(positions)/3);
}

void Loader::cleanUp()
{
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &m_iVAO);
	glDeleteBuffers(1, &m_iVBO);
}

void Loader::createVAO()
{
	glGenVertexArrays(1, &m_iVAO);
	glBindVertexArray(m_iVAO);
}

void Loader::storeDataInAttributeList(int attributeNumber, float data[])
{
	glGenBuffers(1, &m_iVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVAO()
{
	glBindVertexArray(0);
}
