/*
* ProducerEx01.h
*
* Created on: May 18, 2014
* Author: Andrew Zhabura
*/

#ifndef ProducerEx01_h
#define ProducerEx01_h

#include "ZGL/zglProgram.h"
#include "ZGL/zglProducer.h"

class ProducerEx01 : public ZGL::zglProducer
{
private:
	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0 };

	GLuint  VAOs[NumVAOs];
	GLuint  Buffers[NumBuffers];

	static const GLuint  NumVertices = 6;

	ZGL::zglProgram m_prg;
public:
	virtual void InitGL();
	virtual void Display();
};

#endif // ProducerEx01_h