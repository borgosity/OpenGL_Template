#pragma once
// std library includes
#include <vector>
// opengl includes
#include <glm.hpp>

class AABB
{
public:
	AABB();
	~AABB();

	void reset();
	void set(const std::vector<glm::vec3> & points);

private:
	glm::vec3 m_vMin;
	glm::vec3 m_vMax;

};

