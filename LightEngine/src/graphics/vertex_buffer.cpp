#include "vertex_buffer.h"
#include "renderer.h"

namespace Light
{
	VertexBuffer::VertexBuffer(const void* a_data, unsigned int a_size)
	{
		GlCall(glGenBuffers(1, &rendererID));
		GlCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
		GlCall(glBufferData(GL_ARRAY_BUFFER, a_size, a_data, GL_STATIC_DRAW));
	}

	VertexBuffer::~VertexBuffer()
	{
		GlCall(glDeleteBuffers(1, &rendererID));
	}

	void VertexBuffer::bind() const
	{
		GlCall(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
	}

	void VertexBuffer::unbind() const
	{
		GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));

	}

}