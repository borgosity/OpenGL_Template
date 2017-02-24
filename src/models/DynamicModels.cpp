#include "DynamicModels.h"



DynamicModels::DynamicModels()
{
	
}


DynamicModels::~DynamicModels()
{
}

RawModel * DynamicModels::grid(unsigned int a_rows, unsigned int a_columns)
{
	return nullptr;
}

RawModel * DynamicModels::cube()
{
	Loader * loader = new Loader();

	//GLfloat vertices[] = {
	//	-0.500000, -0.500000,  0.500000,
	//	0.500000, -0.500000,  0.500000,
	//	-0.500000,  0.500000,  0.500000,
	//	0.500000,  0.500000,  0.500000,
	//	-0.500000,  0.500000, -0.500000,
	//	0.500000,  0.500000, -0.500000,
	//	-0.500000, -0.500000, -0.500000,
	//	0.500000, -0.500000, -0.500000
	//};

	//GLuint indices[] = {
	//	1, 2, 3,
	//	3, 2, 4,
	//	3, 4, 5,
	//	5, 4, 6,
	//	5, 6, 7,
	//	7, 6, 8,
	//	7, 8, 1,
	//	1, 8, 2,
	//	2, 8, 4,
	//	4, 8, 6,
	//	7, 1, 5,
	//	5, 1, 3
	//};
	
	//return loader->loadToVAO(vertices, sizeof(vertices), 3, indices, sizeof(indices) );

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

	return loader->loadToVAO(vertices, sizeof(vertices), 5);
}
