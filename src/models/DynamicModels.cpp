#include "DynamicModels.h"

Loader * DynamicModels::m_loader = new Loader();

DynamicModels::DynamicModels()
{
	
}


DynamicModels::~DynamicModels()
{
}

void DynamicModels::grid(RawModel & a_rawmodel, unsigned int a_rows, unsigned int a_columns)
{
	Vertex * vertices = new Vertex[a_rows * a_columns];
	unsigned int* indices = new unsigned int[(a_rows - 1) * (a_columns - 1) *6];

	for (unsigned int r = 0; r < a_rows; ++r) {
		for (unsigned int c = 0; c < a_columns; ++c) {
			vertices[r * a_columns + c].position = glm::vec3((float)c, 0, (float)r);
			// create some arbitrary colour based off something
			// that might not be related to tiling a texture
			GLfloat gradient = sinf((c / (float)(a_columns)) * (r / (float)(a_rows)));
			glm::vec3 colour = glm::vec3(gradient);
			vertices[r * a_columns + c].colour = colour;
		}
	}
	// defining index count based off quad count (2 triangles per quad)
	unsigned int index = 0;
	for (unsigned int r = 0; r < (a_rows - 1); ++r) {
		for (unsigned int c = 0; c < (a_columns - 1); ++c) {
			// triangle 1
			indices[index++] = r * a_columns + c;
			indices[index++] = (r + 1) * a_columns + c;
			indices[index++] = (r + 1) * a_columns + (c + 1);
			// triangle 2
			indices[index++] = r * a_columns + c;
			indices[index++] = (r + 1) * a_columns + (c + 1);
			indices[index++] = r * a_columns + (c + 1);
		}
	}
	// create raw model from vertices and indices
	a_rawmodel =  m_loader->loadToVAO(vertices, (a_rows * a_columns) * sizeof(Vertex), 6,
									  indices, (a_rows - 1) * (a_columns - 1) * 6 * sizeof(unsigned int));
	
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
