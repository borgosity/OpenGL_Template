#include "ModelApp.h"



ModelApp::ModelApp()
{
}


ModelApp::~ModelApp()
{
	// display
	deallocate(m_display);
	deallocate(m_loader);
	deallocate(m_renderer);
	deallocate(m_camera);
	deallocate(m_cameraController);
	// shaders
	deallocate(m_meshSP);

	// textures


	// models
	deallocate(m_crisisModel);
	deallocate(m_dragonModel);
	deallocate(m_bunnyModel);
	deallocate(m_buddhaModel);
	deallocate(m_lucyModel);
	// fbx
	deallocate(m_duckModel);
	deallocate(m_robotModel);
	// textured models
	
	// entities 

	// lights


}

bool ModelApp::start()
{
	std::cout << "\n### --> Start ModelApp" << std::endl;

	// camera
	m_camera = new Camera(glm::vec3(0, 3, 10), CAM_SPEED, FOV, NEAR_PLANE, FAR_PLANE);
	m_cameraController = new CameraController();

	// initialise display
	m_display = new DisplayManager("Example App", SCREEN_W, SCREEN_H);
	m_display->createDisplay();

	// Set the required callback functions for user input
	glfwSetKeyCallback(m_display->window(), Controller::keyCallback);
	glfwSetCursorPosCallback(m_display->window(), Controller::mouseCallback);
	glfwSetScrollCallback(m_display->window(), Controller::scrollCallback);

	// Build and compile our shader program
	// initialise shader program

	m_staticShader = new StaticShader(Shader::phongShader);
	m_meshSP = new ShaderProgram(Shader::meshShader);

	// load model to VAO
	m_loader = new Loader();
	m_renderer = new Renderer();

	// load model
	m_crisisModel = new MeshModel("res/models/nanosuit/nanosuit.obj");
	m_crisisModel->transform = Maths::createTransormationMatrix(glm::vec3(0.0f, -1.75f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.2f);
	m_dragonModel = new MeshModel("res/models/stanford/Dragon.obj");
	m_dragonModel->transform = Maths::createTransormationMatrix(glm::vec3(2.5f, -1.75f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.2f);
	m_bunnyModel = new MeshModel("res/models/stanford/Bunny.obj");
	m_bunnyModel->transform = Maths::createTransormationMatrix(glm::vec3(-4.0f, -1.75f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.2f);
	m_lucyModel = new MeshModel("res/models/stanford/Lucy.obj");
	m_lucyModel->transform = Maths::createTransormationMatrix(glm::vec3(-2.0f, -1.75f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.2f);
	m_buddhaModel = new MeshModel("res/models/stanford/Buddha.obj");
	m_buddhaModel->transform = Maths::createTransormationMatrix(glm::vec3(4.5f, -1.75f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.2f);
	// fbx models
	m_duckModel = new MeshModel("res/models/fbx/duck/duck_ascii.fbx");
	m_duckModel->transform = Maths::createTransormationMatrix(glm::vec3(6.0f, -1.75f, 0.0f), glm::vec3(0.0f, 180.0f, 0.0f), 0.01f);
	m_robotModel = new MeshModel("res/models/fbx/robot/Robot_01_Playermodel_Animations_v06.fbx");
	m_robotModel->transform = Maths::createTransormationMatrix(glm::vec3(-6.0f, -1.75f, 0.0f), glm::vec3(0.0f, 90.0f, 0.0f), 0.03f);


	return true;
}

bool ModelApp::update(GLfloat a_deltaTime)
{

	m_cameraController->update(*m_camera, a_deltaTime);
	
	return true;
}

bool ModelApp::fixedUpdate(GLfloat a_deltaTime)
{
	return true;
}

bool ModelApp::draw(GLfloat a_deltaTime)
{
	GLdouble time = glfwGetTime();
	// Render
	// Clear the colorbuffer
	m_renderer->prepare(0.0f, 0.3f, 0.2f);
	// ###############################> START DRAW CODE <#########################################################
	// Activate shader
	m_meshSP->start();

	// pass camera position to shader 
	m_meshSP->uniformMat4("view", m_camera->viewMatrix());
	// pass camera projection to shader
	m_meshSP->uniformMat4("projection", m_camera->projection());
	// pass transform to shader
	m_meshSP->uniformMat4("model", m_crisisModel->transform);
	
	// draw model
	m_crisisModel->draw(*m_meshSP);
	m_meshSP->uniformMat4("model", m_dragonModel->transform);
	m_dragonModel->draw(*m_meshSP);
	m_meshSP->uniformMat4("model", m_bunnyModel->transform);
	m_bunnyModel->draw(*m_meshSP);
	m_meshSP->uniformMat4("model", m_buddhaModel->transform);
	m_buddhaModel->draw(*m_meshSP);
	m_meshSP->uniformMat4("model", m_lucyModel->transform);
	m_lucyModel->draw(*m_meshSP);
	
	// fbx
	m_meshSP->uniformMat4("model", m_duckModel->transform);
	m_duckModel->draw(*m_meshSP);
	m_meshSP->uniformMat4("model", m_robotModel->transform);
	m_robotModel->draw(*m_meshSP);
	// stop shader
	m_meshSP->stop();


	// ##############################> END DRAW STUFF <###########################################################
	// Swap the screen buffers
	m_display->updateDisplay();
	return true;
}

bool ModelApp::stop()
{
	// Properly de-allocate all resources once they've outlived their purpose

	m_loader->cleanUp();
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return true;
}

