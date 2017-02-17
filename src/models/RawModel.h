#pragma once
#include <glew.h>

class RawModel
{
public:
	RawModel(int vaoID, int vertextCount);
	~RawModel();

	GLuint vaoID() { return m_iVaoID; };
	GLuint vertexCount() { return m_iVertexCount; };

private:
	GLuint m_iVaoID;
	GLuint m_iVertexCount;

};

