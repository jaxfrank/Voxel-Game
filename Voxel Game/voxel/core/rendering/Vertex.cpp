#include "Vertex.h"

Vertex::Vertex(const vec3 position, const vec4 color) {
	init(position, color);
}

Vertex::Vertex(const vec3 position) {
	init(position, vec4(1.0f, 1.0f, 1.0f, 1.0f));
}

Vertex::Vertex(){
	init(vec3(0.0f, 0.0f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f));
}

void Vertex::init(const vec3 position, const vec4 color) {
	this->position = position;
	this->color = color;
}

vec3 Vertex::getPosition() const {
	return position;
}

void Vertex::setPosition(const vec3 position) {
	this->position = position;
}

void Vertex::setPosition(const float x, const float y, const float z) {
	this->position = vec3(x, y, z);
}

vec4 Vertex::getColor() const {
	return color;
}

void Vertex::setColor(vec4 color) {
	this->color = color;
}

void Vertex::setColor(const float r, const float g, const float b, const float a) {
	this->color = vec4(r, g, b, a);
}