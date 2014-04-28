#include "Mesh.h"
#include <glm\glm.hpp>

Mesh::Mesh(void){
	glGenBuffers(1, &vertexBufferID);
	glGenBuffers(1, &indexBufferID);
	numIndices = 0;
	drawMode = GL_TRIANGLES;
}


Mesh::~Mesh(void){
	glDeleteBuffers(1, &vertexBufferID);
	glDeleteBuffers(1, &indexBufferID);
}

void Mesh::addVertices(Vertex* verts, int numVerts, GLuint* indices, int numIndices){
	this->vertices = verts;
	this->numVertices = numVerts;
	this->indices = indices;
	this->numIndices = numIndices;

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, numVerts * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(GLuint), this->indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);	
}

void Mesh::draw(){
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(glm::vec3)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glDrawElements(drawMode, numIndices, GL_UNSIGNED_INT, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}

void Mesh::setDrawMode(const GLenum drawMode) {
	this->drawMode = drawMode;
}

GLenum Mesh::getDrawMode() const {
	return drawMode;
}