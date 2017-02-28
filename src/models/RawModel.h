#pragma once
#include <glew.h>

class RawModel
{
public:
	RawModel();
	RawModel(int vaoID, int vertextCount);
	RawModel(int a_vaoID, int a_vertextCount, bool a_indices);
	~RawModel();

	GLuint vaoID() { return m_iVaoID; };
	GLuint vertexCount() { return m_iVertexCount; };
	bool hasIndecies() { return m_bIndices; };
	bool hasIndecies(bool a_value) { m_bIndices = a_value; return m_bIndices; };;

private:
	GLuint		m_iVaoID;
	GLuint		m_iVertexCount;
	bool		m_bIndices; // does the model use indices

};

