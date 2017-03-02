#pragma once
#include "Application.h"
#include "OBJLoader.h"

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
	ShaderProgram * m_phongSP = nullptr;
	ShaderProgram * m_modelSP = nullptr;
	ShaderProgram * m_rippleSP = nullptr;

	// textures
	Texture *		m_groundTexture = nullptr;
	Texture *		m_duckTexture = nullptr;
	Texture *		m_duckNormal = nullptr;
	Texture *		m_rocksTexture = nullptr;
	Texture *		m_rocksNormalMap = nullptr;
	// models
	RawModel *		m_gridModel = nullptr;
	RawModel *		m_cubeModel = nullptr;
	RawModel *		m_objModel = nullptr;
	RawModel *		m_rocksModel = nullptr;

	// textured models
	TexturedModel * m_groundModel = nullptr;
	TexturedModel * m_duckModel = nullptr;
	TexturedModel * m_rocksTM = nullptr;
	// planetary entities 
	Entity * m_ground = nullptr;
	Entity * m_rubberDuck = nullptr;
	Entity * m_rocksE = nullptr;


};

