#include "TerrainApp.h"



TerrainApp::TerrainApp()
{
}


TerrainApp::~TerrainApp()
{
	// display
	deallocate(m_display);
	deallocate(m_loader);
	deallocate(m_renderer);
	deallocate(m_camera);
	deallocate(m_cameraController);
	// shaders
	deallocate(m_colourSP);
	deallocate(m_cameraSP);
	deallocate(m_phongSP);
	deallocate(m_modelSP);
	deallocate(m_rippleSP);
	// textures
	deallocate(m_groundTexture);
	deallocate(m_duckTexture);
	deallocate(m_duckNormal);
	deallocate(m_rocksTexture);
	deallocate(m_rocksNormalMap);
	// models
	deallocate(m_gridModel);
	deallocate(m_cubeModel);
	deallocate(m_objModel);
	deallocate(m_rocksModel);
	// textured models
	deallocate(m_groundModel);
	deallocate(m_duckModel);
	deallocate(m_rocksTM);

	
	// entities 
	deallocate(m_ground);
	deallocate(m_rubberDuck);
	deallocate(m_rocksE);

}

bool TerrainApp::start()
{
	std::cout << "\n### --> Start TerrainApp" << std::endl;

	// camera
	m_camera = new Camera(glm::vec3(0, -0.5f, 1.5f), CAM_SPEED, FOV, NEAR_PLANE, FAR_PLANE);
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
	m_colourSP = new ShaderProgram(Shader::dualTextureShader);
	m_cameraSP = new ShaderProgram(Shader::cameraShader);
	m_phongSP = new ShaderProgram(Shader::phongShader);
	m_modelSP = new ShaderProgram(Shader::modelShader);
	m_rippleSP = new ShaderProgram(Shader::rippleShader);

	// load model to VAO
	m_loader = new Loader();
	m_renderer = new Renderer();

	// ============= grid setup =====================
	// create grid model
	m_gridModel = new RawModel();
	DynamicModels::grid(*m_gridModel, 10, 20);
	m_groundTexture = new Texture("res/textures/Sun.png");
	m_groundModel = new TexturedModel(*m_gridModel, *m_groundTexture, *m_groundTexture, m_rippleSP->ID());
	m_ground = new Entity(m_groundModel, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 1.0f);
	
	m_cubeModel = DynamicModels::square(1);

	////============= obj setup ===========================
	m_objModel = new RawModel();
	OBJLoader::loadObjModel("res/models/soulspear/soulspear.obj", *m_objModel, *m_loader);
	m_duckTexture = new Texture("res/models/soulspear/soulspear_diffuse.png");
	m_duckNormal = new Texture("res/models/soulspear/soulspear_specular.png");
	m_duckModel = new TexturedModel(*m_objModel, *m_duckTexture, *m_duckNormal, m_phongSP->ID());
	m_rubberDuck = new Entity(m_duckModel, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 1.0f);

	////================ normal map test ====================

	m_rocksModel = new RawModel();
	DynamicModels::squareTBN(*m_rocksModel, 1);
	m_rocksTexture = new Texture("res/textures/fourShapes/four_diffuse.png");
	m_rocksNormalMap = new Texture("res/textures/fourShapes/four_normal.png");
	m_rocksTM = new TexturedModel(*m_rocksModel, *m_rocksTexture, *m_rocksNormalMap, m_modelSP->ID());
	m_rocksE = new Entity(m_rocksTM, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 1.0f);



	return true;
}

bool TerrainApp::update(GLfloat a_deltaTime)
{

	m_cameraController->update(*m_camera, a_deltaTime);
	
	return true;
}

bool TerrainApp::fixedUpdate(GLfloat a_deltaTime)
{
	return true;
}

bool TerrainApp::draw(GLfloat a_deltaTime)
{
	GLdouble time = glfwGetTime();
	// Render
	// Clear the colorbuffer
	m_renderer->prepare(0.0f, 0.3f, 0.2f);
	//############################### START DRAW CODE ##########################################################

	//==================== ripple grid =============================
	// Activate shader
	m_rippleSP->start();
	// pass uniform data
	m_rippleSP->uniformFloat("time", time * 1.5);
	m_rippleSP->uniformFloat("heightScale", 0.5f);
	// pass camera position to shader 
	m_rippleSP->uniformMat4("view", m_camera->viewMatrix());
	// pass camera projection to shader
	m_rippleSP->uniformMat4("projection", m_camera->projection());

	// ================== water  ================
	// create transform, with rotation changed over time
	m_ground->transform(Maths::createTransormationMatrix(glm::vec3(-7.75, 1, -5), glm::vec3(90, 0, 0), 0.4f));
	m_renderer->renderEntity(m_ground, m_rippleSP);

	// De-activate shader
	m_rippleSP->stop();

	// ================================= obj model =========================
	// Activate shader
	m_phongSP->start();
	// pass camera position to shader 
	m_phongSP->uniformMat4("view", m_camera->viewMatrix());
	// pass camera projection to shader
	m_phongSP->uniformMat4("projection", m_camera->projection());

	// --- generate light source ------
	glm::vec3 light(sin(time), 1, cos(time));
	m_phongSP->uniformVec3("lightDirection", glm::vec3(0, 1, 0));
	m_phongSP->uniformVec3("lightColour", glm::vec3(1, 0, 0));
	m_phongSP->uniformVec3("cameraPos", m_camera->position());
	m_phongSP->uniformFloat("specPow", 1);

	// create transform, with rotation changed over time
	m_rubberDuck->transform(Maths::createTransormationMatrix(glm::vec3(0, 4.25, -5), glm::vec3(0, 0, 180), 1.0f));
	m_renderer->renderEntity(m_rubberDuck, m_phongSP);
	m_phongSP->stop();


	//=========== normals test
	// Activate shader
	m_modelSP->start();
	// pass camera position to shader 
	m_modelSP->uniformMat4("view", m_camera->viewMatrix());
	// pass camera projection to shader
	m_modelSP->uniformMat4("projection", m_camera->projection());

	// --- generate light source ------
	m_modelSP->uniformVec3("lightDirection", light);

	m_rocksE->transform(Maths::createTransormationMatrix(glm::vec3(0, 4.25, -5), glm::vec3(0, 0, 180), 1.0f));
	m_renderer->renderEntity(m_rocksE, m_modelSP);

	// De-activate shader
	m_modelSP->stop();
	// ================================ end obj model ==========================


	// ##################### END DRAW STUFF ###########################################################
	// Swap the screen buffers
	glfwSwapBuffers(m_display->window());
	return true;
}

bool TerrainApp::stop()
{
	// Properly de-allocate all resources once they've outlived their purpose

	m_loader->cleanUp();
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return true;
}

