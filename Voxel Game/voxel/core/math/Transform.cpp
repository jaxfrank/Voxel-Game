#include "Transform.h"

#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using glm::mat4;

Camera *Transform::camera;
float Transform::fov;
float Transform::aspectRatio;
float Transform::nearClippingPlane;
float Transform::farClippingPlane;

Transform::Transform(vec3 translation, vec3 rotation, vec3 scale):
	translation(translation),
	rotation(rotation),
	scale(scale)
{}

Transform::Transform(void):
	translation(),
	rotation(),
	scale()
{}

void Transform::setProjection(const float fieldOfView, const float aspect, const float zNear, const float zFar) {
	Transform::fov = fieldOfView;
	Transform::aspectRatio = aspect;
	Transform::nearClippingPlane = zNear;
	Transform::farClippingPlane = zFar;
}

glm::mat4 Transform::getTransformationMatrix() const {
	mat4 translationMatrix = glm::translate(mat4(), translation);
	mat4 rotationMatrixX = glm::rotate(mat4(), rotation.x, vec3(1.0f, 0.0f, 0.0f));
	mat4 rotationMatrixY = glm::rotate(mat4(), rotation.y, vec3(0.0f, 1.0f, 0.0f));
	mat4 rotationMatrixZ = glm::rotate(mat4(), rotation.z, vec3(0.0f, 0.0f, 1.0f));
	mat4 scaleMatrix = glm::scale(mat4(), scale);

	return translationMatrix * rotationMatrixX * rotationMatrixY * rotationMatrixZ * scaleMatrix;
}

glm::mat4 Transform::getProjectedTransforationMatrix() const {
	mat4 projectionMatrix = glm::perspective(Transform::fov, Transform::aspectRatio, Transform::nearClippingPlane, Transform::farClippingPlane);

	return projectionMatrix * camera->getWorldToViewMatrix() * getTransformationMatrix();
}

glm::vec3 Transform::getTranslation() const{
	return this->translation;
}

void Transform::setTranslation(const glm::vec3 translation){
	this->translation = translation;
}

void Transform::setTranslation(const float x, const float y, const float z){
	this->translation.x = x;
	this->translation.y = y;
	this->translation.z = z;
}

glm::vec3 Transform::getRotation() const{
	return this->rotation;
}

void Transform::setRotation(const glm::vec3 rotation){
	this->rotation = rotation;
}

void Transform::setRotation(const float x, const float y, const float z){
	this->rotation.x = x;
	this->rotation.y = y;
	this->rotation.z = z;
}

glm::vec3 Transform::getScale() const{
	return this->scale;
}

void Transform::setScale(const glm::vec3 scale){
	this->scale = scale;
}

void Transform::setScale(const float x, const float y, const float z){
	this->scale.x = x;
	this->scale.y = y;
	this->scale.z = z;
}

void Transform::setCamera(Camera* camera){
	Transform::camera = camera;
}

Camera& Transform::getCamera() {
	return *camera;
}