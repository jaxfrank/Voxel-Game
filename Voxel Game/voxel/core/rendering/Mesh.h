#pragma once

#include <GL\glew.h>
#include <SFML\OpenGL.hpp>
#include "Vertex.h"

class Mesh  {

public:
	Mesh(void);
	~Mesh(void);

	void addVertices(Vertex* verts, int numVerts, GLuint* indices, int numIndices);
	void draw();

	void setDrawMode(const GLenum drawMode);
	GLenum getDrawMode() const;

private:
	Vertex* vertices;
	int numVertices;
	GLuint* indices;
	int numIndices;
	GLuint vertexBufferID;
	GLuint indexBufferID;
	GLenum drawMode;
};

