#pragma once
class RawModel
{
public:
	RawModel(int vaoID, int vertextCount);
	~RawModel();

	int vaoID() { return m_iVaoID; };
	int vertexCount() { return m_iVertexCount; };

private:
	int m_iVaoID;
	int m_iVertexCount;

};

