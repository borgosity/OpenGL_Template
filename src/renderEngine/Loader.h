#pragma once
// std includes
#include <iostream>
#include <vector>
#include <list>
// gl includes
#include <glew.h>
#include <SOIL.h>   // texturing
// local includes
#include "RawModel.h"

class Loader
{
public:
	Loader();
	~Loader();

	RawModel * loadToVAO(GLfloat positions[], int size);
	RawModel * loadToVAO(GLfloat a_positions[], int a_posSize, int a_vertexSize);
	RawModel * loadToVAO(GLfloat a_positions[], int a_posSize, int a_vertexSize, GLuint a_indicies[], int a_indSize);
	RawModel * loadToVAO(GLfloat a_positions[], int a_posSize, GLuint a_indicies[], int a_indSize);
	RawModel * loadToVAO(GLfloat a_positions[], int a_pSize, GLfloat a_colours[], int a_cSize, GLfloat a_textures[], int a_tSize, GLuint a_indicies[], int a_iSize);
	RawModel * loadTextureVAO(GLfloat a_positions[], int a_size, GLuint a_indicies[], int a_indSize);
	GLuint loadTexture(std::string a_fileName);
	void cleanUp();

private:
	
	std::list<GLuint> m_vVAOs;
	std::list<GLuint> m_vVBOs;
	std::list<GLuint> m_vTextures; // list of textures
	
	// private functions
	GLuint createVAO();
	void createVBO(GLfloat data[], int size);
	void bindIndicesBuffer(GLuint indices[], int size);
	void storePositionDataInAttributeList(int attributeNumber);
	void storeColourDataInAttributeList(int attributeNumber);
	void storeTextureDataInAttributeList(int attributeNumber);
	void storeTextureDataInAttributeList(int attributeNumber, int coordinateSize, GLfloat data[], int dataSize);
	void storeTextureDataInAttributeList(int attributeNumber, int coordinateSize);

	// refactor
	// single verticies functions
	void storePositionData(int attributeNumber, int vertSize);
	void storeColourData(int attributeNumber, int vertSize);
	void storeTextureData(int attributeNumber, int vertSize);
	// split verticies functions
	void storePositionData(int attributeNumber, GLfloat data[], int size);
	void storeColourData(int attributeNumber, GLfloat data[], int size);
	void storeTextureData(int attributeNumber, GLfloat data[], int size);

	void unbind();
};

