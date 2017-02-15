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
	storeDataInAttributeList(0, positions, size);
	return new RawModel(m_iVAO, size/3);
}

void Loader::createVAO()
{
	glGenVertexArrays(1, &m_iVAO);
	glGenBuffers(1, &m_iVBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(m_iVAO);
}

void Loader::storeDataInAttributeList(int attributeNumber, GLfloat data[], int size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_iVBO);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Loader::cleanUp()
{
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &m_iVAO);
	glDeleteBuffers(1, &m_iVBO);
}

