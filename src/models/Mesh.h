#pragma once
#include <sstream>
#include <vector>

// gl includes
#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

// source includes
#include "Loader.h"
#include "ShaderProgram.h"

class Mesh
{
public:
	Mesh(std::vector<Vertex> a_vertices, std::vector<GLuint> a_indices, std::vector<MeshTexture> a_textures, float a_shininess);
	~Mesh();

	void draw(ShaderProgram & a_shaderProgram);

private:
	// mesh data
	std::vector<Vertex> m_vVertices;
	std::vector<GLuint> m_vIndices;
	std::vector<MeshTexture> m_vTextures;
	
	// Buffers
	GLuint VAO, VBO, EBO;

	// attributes
	GLfloat m_fShininess;

	void setupMesh();
};

