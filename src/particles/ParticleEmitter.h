#pragma once
// std library includes

// opengl includes
#include "glew.h"
#include "glm.hpp"
// source includes
#include "ShaderProgram.h"


struct Particle {
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec4 colour;
	GLfloat size;
	GLfloat lifeTime;
	GLfloat lifeSpan;
};

struct ParticleVertex {
	glm::vec4 position;
	glm::vec4 colour;
};

class ParticleEmitter
{
public:
	ParticleEmitter();
	~ParticleEmitter();

	void update(GLfloat a_deltaTime, const glm::mat4 & a_cameraTransform);
	void draw(ShaderProgram & a_shaderProgram);
	void init(GLuint a_maxParticles, GLuint a_emitRate, 
			GLfloat a_lifetimeMin, GLfloat a_lifetimeMax,
			GLfloat a_velocityMin, GLfloat a_velocityMax,
			GLfloat a_startSize, GLfloat a_endSize,
			const glm::vec4 & a_StartColour, const glm::vec4 & a_endColour);

private:
	Particle *		m_particles = nullptr;
	GLuint			m_uiFirstDead;
	GLuint			m_uiMaxParticles; 

	GLuint			 VAO, VBO, EBO;
	ParticleVertex * m_vertexData = nullptr;

	glm::vec3	m_vPosition;
	GLfloat		m_fEmitTimer;
	GLfloat		m_fEmitRate;
	GLfloat		m_fLifespanMin;
	GLfloat		m_fLifespanMax;
	GLfloat		m_fVelocityMin;
	GLfloat		m_fVelocityMax;
	GLfloat		m_fStartSize;
	GLfloat		m_fEndSize;
	glm::vec4	m_vStartColour;
	glm::vec4	m_vEndColour;

	// debug variables
	GLuint m_vertCount;
	GLuint m_indiceCount;

	// private functions

	void emit();
};

