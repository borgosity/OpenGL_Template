#include "RawModel.h"


RawModel::RawModel(int vaoID, int vertCount )
{
	m_iVaoID = vaoID;
	m_iVertexCount = vertCount;
	m_bIndices = false;
}

RawModel::RawModel(int a_vaoID, int a_vertCount, bool a_indecies)
{
	m_iVaoID = a_vaoID;
	m_iVertexCount = a_vertCount;
	m_bIndices = a_indecies;
}


RawModel::~RawModel()
{
}

