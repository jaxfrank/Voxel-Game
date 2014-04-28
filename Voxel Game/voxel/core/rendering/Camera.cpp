#include "Camera.h"

#include <glm\gtc\matrix_transform.hpp>

using glm::vec3;

Camera::Camera(void):
	position(0.0f, 0.0f, 0.0f),
	forward(0.0f, 0.0f, -1.0f),
	up(0.0f, 1.0f, 0.0f)
{}

Camera::Camera(const vec3 position, const vec3 forward, const vec3 up) :
	position(position),
	forward(forward),
	up(up)
{}

glm::mat4 Camera::getWorldToViewMatrix() const {
	return glm::lookAt(position, position + forward, up);
}

vec3 Camera::getPosition() const {
	return position;
}

void Camera::setPosition(const vec3 position) {
	this->position = position;
}

vec3 Camera::getForward() const {
	return forward;
}

void Camera::setForward(const vec3 forward){
	this->forward = forward;
}

vec3 Camera::getUp() const {
	return up;
}

void Camera::setUp(const vec3 up){
	this->up = up;
}