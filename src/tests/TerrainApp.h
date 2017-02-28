#pragma once
#include "Application.h"
class TerrainApp :
	public Application
{
public:
	TerrainApp();
	~TerrainApp();

	bool start();
	bool update(GLfloat a_deltaTime);
	bool fixedUpdate(GLfloat a_deltaTime);
	bool draw(GLfloat a_deltaTime);
	bool stop();

private:
	// display
	DisplayManager *	m_display = nullptr;
	Loader *			m_loader = nullptr;
	Renderer *			m_renderer = nullptr;
	Camera *			m_camera = nullptr;
	CameraController *	m_cameraController = nullptr;
	// shaders
	ShaderProgram * m_colourSP = nullptr;
	ShaderProgram * m_cameraSP = nullptr;
	ShaderProgram * m_rippleSP = nullptr;
	// textures
	Texture *		m_groundTexture = nullptr;
	// models
	RawModel *		m_gridModel = nullptr;
	RawModel *		m_cubeModel = nullptr;
	TexturedModel * m_groundModel = nullptr;

	// planetary entities 
	Entity * m_ground = nullptr;

};

