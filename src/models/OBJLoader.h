#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <glew.h>
#include <tiny_obj_loader.h>
// source includes
#include "RawModel.h"
#include "Loader.h"

class OBJLoader
{
public:
	OBJLoader();
	~OBJLoader();

	static void loadObjModel(std::string a_filePath, RawModel & a_rawModel, Loader & a_loader );
};

