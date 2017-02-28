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
	// collect triangle vertices
	std::vector<ObjVertex> vertices;
	for (auto shape : shapes)
	{
		int index = 0;

		for (auto face : shape.mesh.num_face_vertices)
		{
			for (int i = 0; i < 3; ++i) {
				tinyobj::index_t idx = shape.mesh.indices[index + i];
				ObjVertex v = { 0 };
				// positions
				v.x = attribs.vertices[3 * idx.vertex_index + 0];
				v.y = attribs.vertices[3 * idx.vertex_index + 1];
				v.z = attribs.vertices[3 * idx.vertex_index + 2];
				// normals
				if (attribs.normals.size() > 0) {
					v.nx = attribs.normals[3 * idx.normal_index + 0];
					v.ny = attribs.normals[3 * idx.normal_index + 1];
					v.nz = attribs.normals[3 * idx.normal_index + 2];
				}
				// texture coordinates
				if (attribs.texcoords.size() > 0) {
					v.u = attribs.texcoords[2 * idx.texcoord_index + 0];
					v.v = attribs.texcoords[2 * idx.texcoord_index + 1];
				}
				vertices.push_back(v);
			}
			index += face;
		}

	}


}
