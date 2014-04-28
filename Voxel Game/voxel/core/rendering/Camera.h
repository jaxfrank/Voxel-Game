#pragma once

#include <glm\glm.hpp>

class Camera {
public:
	Camera(void);
	Camera(const glm::vec3 position, const glm::vec3 forward, const glm::vec3 up);

	glm::mat4 getWorldToViewMatrix() const;

	glm::vec3 getPosition() const;
	void setPosition(const glm::vec3 position);
	glm::vec3 getForward() const;
	void setForward(const glm::vec3 forward);
	glm::vec3 getUp() const;
	void setUp(const glm::vec3 up);

private:
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
};

