#pragma once
#include <glew.h>
#include <glm.hpp>
#include <gtc\noise.hpp>
// source includes
#include "ShaderProgram.h"
#include "DynamicModels.h"
#include "Texture.h"
#include "TexturedModel.h"
#include "Entity.h"

class Terrain
{
public:
	Terrain(glm::vec3 a_position, GLuint a_size);
	~Terrain();

	void draw(Camera & a_camera);
	glm::vec3 position() { return m_vPosition; };
	glm::vec3 position(glm::vec3 a_position) { m_vPosition = a_position; return m_vPosition; };
	glm::mat4 transform() { return m_m4Transform; };
	glm::mat4 transform(glm::mat4 a_transform) { m_m4Transform = a_transform; return m_m4Transform; };

private:
	glm::vec3		m_vPosition;
	glm::mat4		m_m4Transform;
	glm::vec3		m_vTerrainColour;
	GLuint			m_uiSize;
	// default grid settings
	GLuint			m_uiGridSize;
	GLuint			m_uiVertNum;

	RawModel *		m_terrainModel = nullptr;

	GLuint			m_perlinTexture;
	GLfloat			m_fShininess;

	ShaderProgram * m_shaderProgram = nullptr;
	Texture *		m_terrainTexture = nullptr;
	TexturedModel *	m_terrainTM = nullptr;
	Entity *		m_terrain = nullptr;
	
	void setupTerrain();
	void perlinGeneration();

	void perlinRings();
};

