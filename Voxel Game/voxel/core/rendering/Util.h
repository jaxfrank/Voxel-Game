#pragma once

#include <glm/glm.hpp>
#include "Vertex.h"
#include "..\math\Transform.h"
#include "Mesh.h"

class Util {
public:
	static Mesh* createRectangularPrism(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, glm::vec4 color);

private:
	Util();
	~Util();
};

