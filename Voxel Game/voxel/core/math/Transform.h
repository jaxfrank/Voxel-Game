#pragma once
#include <glm\glm.hpp>

#include "..\rendering\Camera.h"

class Transform
{
public:
	static void setProjection(const float fieldOfView, const float aspectRation, const float zNear, const float zFar);

	static void setCamera(Camera* camera);
	static Camera& getCamera();

	Transform(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);
	Transform(void);

	glm::mat4 getTransformationMatrix() const;
	glm::mat4 getProjectedTransforationMatrix() const;
	glm::mat4 getProjectedTransforationMatrix(const glm::mat4 tranformationMatrix) const;

	glm::vec3 getTranslation() const;
	void setTranslation(glm::vec3 translation);
	void setTranslation(const float x, const float y, const float z);
	glm::vec3 getRotation() const;
	void setRotation(const glm::vec3 rotation);
	void setRotation(const float x, const float y, const float z);
	glm::vec3 getScale() const;
	void setScale(const glm::vec3 scale);
	void setScale(const float x, const float y, const float z);

private:
	static Camera* camera;
	static float fov;
	static float aspectRatio;
	static float nearClippingPlane;
	static float farClippingPlane;

	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
};

