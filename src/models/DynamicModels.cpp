#include "DynamicModels.h"

Loader * DynamicModels::m_loader = new Loader();

DynamicModels::DynamicModels()
{
	
}


DynamicModels::~DynamicModels()
{
}

void DynamicModels::grid(RawModel & a_rawmodel, unsigned int a_size, unsigned int a_vertCount)
{
	Vertex * vertices = new Vertex[a_vertCount * a_vertCount];
	unsigned int* indices = new unsigned int[(a_vertCount - 1) * (a_vertCount - 1) * 6];

	for (unsigned int r = 0; r < a_vertCount; ++r) {
		for (unsigned int c = 0; c < a_vertCount; ++c) {
			//vertices[r * a_vertCount + c].position = glm::vec3((float)c * a_size, 0, (float)r * a_size);
			vertices[r * a_vertCount + c].position = glm::vec3((float)c / ((float)(a_vertCount) - 1 ) * a_size, 
																0, 
																(float)r / ((float)(a_vertCount) - 1 ) * a_size);
			vertices[r * a_vertCount + c].normal = glm::vec3(0, 1, 0);
			vertices[r * a_vertCount + c].texCoords = glm::vec2((c / (float)(a_vertCount - 1)), 
																(r / (float)(a_vertCount - 1)));
		}
	}
	// defining index count based off quad count (2 triangles per quad)
	unsigned int index = 0;
	for (unsigned int r = 0; r < (a_vertCount - 1); ++r) {
		for (unsigned int c = 0; c < (a_vertCount - 1); ++c) {
			// triangle 1
			indices[index++] = r * a_vertCount + c;
			indices[index++] = (r + 1) * a_vertCount + c;
			indices[index++] = (r + 1) * a_vertCount + (c + 1);
			// triangle 2
			indices[index++] = r * a_vertCount + c;
			indices[index++] = (r + 1) * a_vertCount + (c + 1);
			indices[index++] = r * a_vertCount + (c + 1);
		}
	}

	// create raw model from vertices and indices
	a_rawmodel =  m_loader->loadToVAO(vertices, (a_vertCount * a_vertCount) * sizeof(Vertex), 8,
									  indices, (a_vertCount - 1) * (a_vertCount - 1) * 8 * sizeof(unsigned int));
	// cleanup
	delete[] vertices;
	delete[] indices;
}

RawModel * DynamicModels::cube()
{
	//GLfloat vertices[] = {			
	//	-0.5f,0.5f,-0.5f,	0,0,
	//	-0.5f,-0.5f,-0.5f,	0,1,
	//	0.5f,-0.5f,-0.5f,	1,1,
	//	0.5f,0.5f,-0.5f,	1,0,

	//	-0.5f,0.5f,0.5f,	0,0,
	//	-0.5f,-0.5f,0.5f,	0,1,
	//	0.5f,-0.5f,0.5f,	1,1,
	//	0.5f,0.5f,0.5f,	    1,0,

	//	0.5f,0.5f,-0.5f,	0,0,
	//	0.5f,-0.5f,-0.5f,	0,1,
	//	0.5f,-0.5f,0.5f,	1,1,
	//	0.5f,0.5f,0.5f,     1,0,

	//	-0.5f,0.5f,-0.5f,	0,0,
	//	-0.5f,-0.5f,-0.5f,	0,1,
	//	-0.5f,-0.5f,0.5f,	1,1,
	//	-0.5f,0.5f,0.5f,    1,0,

	//	-0.5f,0.5f,0.5f,    0,0,
	//	-0.5f,0.5f,-0.5f,   0,1,
	//	0.5f,0.5f,-0.5f,    1,1,
	//	0.5f,0.5f,0.5f,     1,0,

	//	-0.5f,-0.5f,0.5f,   0,0,
	//	-0.5f,-0.5f,-0.5f,  0,1,
	//	0.5f,-0.5f,-0.5f,   1,1,
	//	0.5f,-0.5f,0.5f,    1,0
	//};

	//GLuint indices[] = {
	//	0, 1, 3,
	//	3, 1, 2,
	//	4, 5, 7,
	//	7, 5, 6,
	//	8, 9, 11,
	//	11, 9, 10,
	//	12, 13, 15,
	//	15, 13, 14,
	//	16, 17, 19,
	//	19, 17, 18,
	//	20, 21, 23,
	//	23, 21, 22

	//};
	////
	//return m_loader->loadToVAO(vertices, sizeof(vertices), 5, indices, sizeof(indices) );

	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	return m_loader->loadToVAO(vertices, sizeof(vertices), 5);
}

RawModel * DynamicModels::square(GLfloat a_size)
{

	GLfloat vertices[] = {
		// Positions          // Colors           // Texture Coords  (Note that we changed them to 'zoom in' on our texture image)
		a_size,  a_size, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,  // Top Right
		a_size, -a_size, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
		-a_size, -a_size, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-a_size,  a_size, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left 
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

	return m_loader->loadToVAO(vertices, sizeof(vertices), 7, indices, sizeof(indices));

}

void DynamicModels::squareTBN(RawModel & a_rawmodel, GLfloat a_size)
{
	Vertex4 vertices[] = {
		{ -5, 0,  5, 0, 1, 0, 1, 0, 0, 0, 1 },
		{ 5, 0,  5, 0, 1, 0, 1, 0, 0, 1, 1 },
		{ 5, 0, -5, 0, 1, 0, 1, 0, 0, 1, 0 },
		{ -5, 0, -5, 0, 1, 0, 1, 0, 0, 0, 0 },
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
	
	a_rawmodel = m_loader->loadToVAO(vertices, sizeof(vertices), 11, indices, sizeof(indices));
}
