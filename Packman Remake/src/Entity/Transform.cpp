#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"

glm::mat4 Transform::GetModel()
{
    return glm::translate(glm::mat4(1.0f),Position);
}
