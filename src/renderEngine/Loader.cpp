#include "Loader.h"



Loader::Loader()
{
	m_vVAOs = {};
	m_vVBOs = {};
	m_vTextures = {};
}


Loader::~Loader()
{
}
/// default VAO loader
RawModel * Loader::loadToVAO(GLfloat positions[], int size)
{
	GLuint vaoID = createVAO();
	createVBO(positions, size);
	storePositionDataInAttributeList(0);
	return new RawModel(vaoID, size/3);
}
/// VAO loader that includes indicies
RawModel * Loader::loadToVAO(GLfloat a_positions[], int a_posSize, GLuint a_indicies[], int a_indSize)
{
	GLuint vaoID = createVAO();
	createVBO(a_positions, a_posSize);			// create and bind VBOs
	bindIndicesBuffer(a_indicies, a_indSize);	// bind indicies
	storePositionDataInAttributeList(0);
	return new RawModel(vaoID, a_indSize);
}
/// VAO loader for more than one attribute (1-3)
RawModel * Loader::loadToVAO(GLfloat a_positions[], int a_size, int a_attribNum)
{
	GLuint vaoID = createVAO();
	createVBO(a_positions, a_size);
	if (a_attribNum == 1) storePositionDataInAttributeList(0);
	if (a_attribNum == 2) storeColourDataInAttributeList(0);
	if (a_attribNum == 3) storeTextureDataInAttributeList(0);
	
	return new RawModel(vaoID, a_size / (3 * a_attribNum));
}
RawModel * Loader::loadTextureVAO(GLfloat a_positions[], int a_size, GLuint a_indicies[], int a_indSize)
{
	GLuint vaoID = createVAO();
	createVBO(a_positions, a_size);
	bindIndicesBuffer(a_indicies, a_indSize);	// bind indicies
	storeTextureDataInAttributeList(0);

	return new RawModel(vaoID, 6);
}
GLuint Loader::loadTexture(std::string a_fileName, int a_width, int a_height)
{

	GLuint textureID = 0;
	glGenTextures(1, &textureID);
	// bind texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	// All upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// read in the texture file
	unsigned char* image = SOIL_load_image(a_fileName.c_str(), &a_width, &a_height, 0, SOIL_LOAD_RGB);
	// generate texture from the image
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, a_width, a_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	// clear image memory and unbind the texture
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	return textureID;
}

GLuint Loader::createVAO()
{
	GLuint vaoID = 0;
	glGenVertexArrays(1, &vaoID);
	m_vVAOs.push_back(vaoID);
	// Bind the Vertex Array Object first
	glBindVertexArray(vaoID);

	return vaoID;
}

void Loader::createVBO(GLfloat data[], int size)
{
	GLuint vboID = 0;
	// bind and set vertex buffer(s) and attribute pointer(s).
	glGenBuffers(1, &vboID);
	m_vVBOs.push_back(vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Loader::bindIndicesBuffer(GLuint indices[], int size)
{
	GLuint eboID = 0;
	// bind and set vertex buffer(s) and attribute pointer(s).
	glGenBuffers(1, &eboID);
	m_vVBOs.push_back(eboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);

}

void Loader::storePositionDataInAttributeList(int attributeNumber)
{
	// Position attribute
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(attributeNumber);
	glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind current VBO
	glBindVertexArray(0);			  // unbind current VAO
}

void Loader::storeColourDataInAttributeList(int attributeNumber)
{
	// Position attribute
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(attributeNumber);
	// Color attribute
	glVertexAttribPointer(attributeNumber + 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(attributeNumber + 1);
	// unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind current VBO
	glBindVertexArray(0);			  // unbind current VAO
}

void Loader::storeTextureDataInAttributeList(int attributeNumber)
{
	// Position attribute
	glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(attributeNumber);
	// Color attribute
	glVertexAttribPointer(attributeNumber + 1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(attributeNumber + 1);
	// Texture attribute
	glVertexAttribPointer(attributeNumber + 2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	// unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind current VBO
	glBindVertexArray(0);			  // unbind current VAO
}

void Loader::cleanUp()
{
	// clean up VAOs
	for each (auto var in m_vVAOs)
	{
		glDeleteVertexArrays(1, &var);
	}
	// clean up VBOs
	for each (auto var in m_vVBOs)
	{
		glDeleteBuffers(1, &var);
	}
	// clean up textures
	for each (auto var in m_vTextures)
	{
		glDeleteTextures(1, &var);
	}
}

