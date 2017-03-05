#pragma once
#include "Application.h"
#include "OBJLoader.h"
#include "Light.h"
#include "StaticShader.h"
#include "MeshModel.h"

class ModelApp :
	public Application
{
public:
	ModelApp();
	~ModelApp();

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
	StaticShader * m_staticShader = nullptr;
	ShaderProgram * m_meshSP = nullptr;

	// textures

	// models obj
	MeshModel * m_crisisModel = nullptr;
	MeshModel * m_dragonModel = nullptr;
	MeshModel * m_bunnyModel = nullptr;
	MeshModel * m_buddhaModel = nullptr;
	MeshModel * m_lucyModel = nullptr;

	// models fbx
	MeshModel * m_duckModel = nullptr;
	MeshModel * m_robotModel = nullptr;


	// textured models
	
	// entities 

	// lights



};

