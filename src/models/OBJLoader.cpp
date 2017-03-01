#include "OBJLoader.h"



OBJLoader::OBJLoader()
{
}


OBJLoader::~OBJLoader()
{
}

void OBJLoader::loadObjModel(std::string a_filePath, RawModel & a_rawModel, Loader & a_loader)
{	
	// file loading variables
	tinyobj::attrib_t attribs;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string err;
	// load file and get result
	bool success = tinyobj::LoadObj(&attribs, &shapes, &materials, &err, a_filePath.c_str());

	if (shapes.size() > 1) {
		std::cout << " LOAD MODEL ERROR -> model has more than one shape in it, use function that supports multiple shapes!" << std::endl;
		return;
	}

	// collect triangle vertices
	auto shape = shapes[0];
	int vertSize = shape.mesh.num_face_vertices.size();
	ObjVertex * vertices = new ObjVertex[vertSize];
	int index = 0;
	int vertIndex = 0;
	for (auto face : shape.mesh.num_face_vertices)
	{
		// each face has vertices
		for (int i = 0; i < 3; ++i) {
			tinyobj::index_t idx = shape.mesh.indices[index + i];
			ObjVertex v = { };
			// positions
			vertices[index + i].position = glm::vec3(
				(GLfloat)attribs.vertices[3 * idx.vertex_index + 0],
				(GLfloat)attribs.vertices[3 * idx.vertex_index + 1],
				(GLfloat)attribs.vertices[3 * idx.vertex_index + 2]
			);
			// normals
			if (attribs.normals.size() > 0) {
				vertices[index + i].normal = glm::vec3(
					(GLfloat)attribs.normals[3 * idx.normal_index + 0],
					(GLfloat)attribs.normals[3 * idx.normal_index + 1],
					(GLfloat)attribs.normals[3 * idx.normal_index + 2]
				);
			}
			// texture coordinates
			if (attribs.texcoords.size() > 0) {
				vertices[index + i].uv = glm::vec2(
					(GLfloat)attribs.texcoords[2 * idx.texcoord_index + 0],
					(GLfloat)attribs.texcoords[2 * idx.texcoord_index + 1]
				);
			}
		}
		index += face;
	}
	// load vertices to VAO and create a raw model
	//a_rawModel = a_loader.loadToVAO(vertices, vertSize * sizeof(ObjVertex), 7, nullptr, 0);
	// clean up
	delete[] vertices;
}
