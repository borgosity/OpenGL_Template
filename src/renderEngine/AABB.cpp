#include "AABB.h"



AABB::AABB()
{
	reset();
}


AABB::~AABB()
{
}
///
/// Reset minimum and maximum vec3's
///
void AABB::reset()
{
	m_vMin = glm::vec3(1e37f);
	m_vMax = glm::vec3(-1e37f);
}
///
/// Set minimum and maximum edges
///
void AABB::set(const std::vector<glm::vec3>& a_points)
{
	for (auto& p : a_points)
	{
		if (p.x < m_vMin.x) m_vMin.x = p.x;
		if (p.y < m_vMin.y) m_vMin.y = p.y;
		if (p.z < m_vMin.z) m_vMin.z = p.z;
		if (p.x > m_vMax.x) m_vMax.x = p.x;
		if (p.y > m_vMax.y) m_vMax.y = p.y;
		if (p.z > m_vMax.z) m_vMax.z = p.z;
	}
		
}
