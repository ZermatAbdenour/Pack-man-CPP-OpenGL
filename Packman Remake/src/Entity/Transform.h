#pragma once
#include <glm/glm.hpp>
class Transform {
public:
	glm::vec3 Position = glm::vec3(0.1f,0,0);
	glm::mat4 GetModel();
};