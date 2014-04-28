#include "Util.h"

#include <glm\gtx\random.hpp>

Util::Util() {}
Util::~Util() {}

//vec4 * matrix
Mesh* Util::createRectangularPrism(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale, glm::vec4 color){
	Transform transform(translation, rotation, scale);
	glm::mat4 transfromationMatrix = transform.getTransformationMatrix();
	
	float size = 0.5f;
	Vertex verts[] = {
		Vertex(glm::vec3(glm::vec4(-size, -size, -size, 1) * transfromationMatrix), color),
		Vertex(glm::vec3(glm::vec4(-size, -size, size, 1) * transfromationMatrix), color),
		Vertex(glm::vec3(glm::vec4(size, -size, size, 1) * transfromationMatrix), color),
		Vertex(glm::vec3(glm::vec4(size, -size, -size, 1) * transfromationMatrix), color),

		Vertex(glm::vec3(glm::vec4(-size, size, -size, 1) * transfromationMatrix), color),
		Vertex(glm::vec3(glm::vec4(-size, size, size, 1) * transfromationMatrix), color),
		Vertex(glm::vec3(glm::vec4(size, size, size, 1) * transfromationMatrix), color),
		Vertex(glm::vec3(glm::vec4(size, size, -size, 1) * transfromationMatrix), color),
	};

	GLuint indexes[] = {
		//Bottom
		0, 1, 2,
		2, 3, 0,
		//Top
		4, 6, 5,
		6, 4, 7,
		//Left
		0, 4, 1,
		4, 5, 1,
		//Front
		5, 6, 2,
		2, 1, 5,
		//Right
		2, 6, 7,
		7, 3, 2,
		//Back
		3, 4, 0,
		3, 7, 4,
	};

	Vertex* vertices = new Vertex[8];
	GLuint* indices = new GLuint[36];

	memcpy(vertices, verts, sizeof(verts));
	memcpy(indices, indexes, sizeof(indexes));

	Mesh* mesh = new Mesh();
	mesh->addVertices(vertices, 8, indices, 36);

	return mesh;
}