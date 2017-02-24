/***************************************************************************************************************
  OpenGL C++ Tutorial followed from https://learnopengl.com/
  OpenGL 3D Game Tutorial was also use https://www.youtube.com/playlist?list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
  - the youtube tutorial is written in Java but has some good explanations
  - the class structure for this project was also taken from that tutorial
****************************************************************************************************************/

#include <iostream>
#include "tests\tests.h"
#include "Application.h"


/// main function
int main()
{
	
	//helloWorld(); 
	//helloTriangle();
	//renderEngineTest(); 
	//indexBuffer();
	//greenTriangleChange();
	//gtShaderTest();
	//rainbowTri();
	//multipleShaders();
	//textures();
	//texturesTute();
	// texturesSplitData(); //## not working
	//dualTextures();
	//dualTextTute();
	//transformsTute();
	//transformsTuteRotation();
	//transformsRotationPlanets();
	//quaterionsTute();
	//threeDeeObjects();
	//camera();

	Application * app = new Application();

	if (app != nullptr)
	{
		app->run();
	}

	delete app;

	return 0;
}

