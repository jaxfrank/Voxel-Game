#pragma once

#include <glm\glm.hpp>

using glm::vec2;
using glm::vec3;
using glm::vec4;

class Vertex
{
public:
	Vertex(const vec3 position, const vec4 color);
	Vertex(const vec3 position);
	Vertex();

	vec3 getPosition() const;
	void setPosition(const vec3 position);
	void setPosition(const float x, const float y, const float z);
	vec4 getColor() const;
	void setColor(const vec4 color);
	void setColor(const float r, const float g, const float b, const float a);

private:
	vec3 position;
	vec4 color;

	void init(const vec3 position, const vec4 color);
};

