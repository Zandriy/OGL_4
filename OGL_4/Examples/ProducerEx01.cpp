/*
* ProducerEx01.cpp
*
* Created on: May 18, 2014
* Author: Andrew Zhabura
*/

#include "ProducerEx01.h"
#include "ZGL/zglLoaderWin.h"

#define BUFFER_OFFSET(x)  ((const void*) (x))

void ProducerEx01::InitGL()
{
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat  vertices[NumVertices][2] = {
		{ -0.90, -0.90 },  // Triangle 1
		{  0.85, -0.90 },
		{ -0.90,  0.85 },
		{  0.90, -0.85 },  // Triangle 2
		{  0.90,  0.90 },
		{ -0.85,  0.90 }
	};

	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
		vertices, GL_STATIC_DRAW);

	ZGL::ShaderInfo  shaders[] = {
		{ GL_VERTEX_SHADER, "Shaders/triangles.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/triangles.frag" },
		{ GL_NONE, NULL }
	};

	m_prg.LoadShaders(shaders);
	m_prg.ActivateProgram();

	glVertexAttribPointer(vPosition, 2, GL_FLOAT,
		GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);

	glClearColor(0.4, 0.7, 0.7, 1.0);
}

void ProducerEx01::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
}
