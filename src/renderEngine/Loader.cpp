#include "Loader.h"



Loader::Loader()
{
}


Loader::~Loader()
{
}

RawModel * Loader::loadToVAO(GLfloat positions[], int size)
{
	createVAO();
	storePositionDataInAttributeList(0, positions, size);
	return new RawModel(m_iVAO, size/3);
}

RawModel * Loader::loadToVAO(GLfloat a_positions[], int a_size, int a_attribNum)
{
	createVAO();
	storeColourDataInAttributeList(0, a_positions, a_size);
	return new RawModel(m_iVAO, a_size / (3 * a_attribNum));
}

void Loader::createVAO()
{
	glGenVertexArrays(1, &m_iVAO);
	glGenBuffers(1, &m_iVBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(m_iVAO);
}

void Loader::storePositionDataInAttributeList(int attributeNumber, GLfloat data[], int size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(attributeNumber);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Loader::storeColourDataInAttributeList(int attributeNumber, GLfloat data[], int size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(attributeNumber);
	// Color attribute
	glVertexAttribPointer(attributeNumber + 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(attributeNumber + 1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Loader::cleanUp()
{
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &m_iVAO);
	glDeleteBuffers(1, &m_iVBO);
}

