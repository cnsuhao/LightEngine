#include "index_buffer.h"
#include "renderer.h"

namespace Light
{
	IndexBuffer::IndexBuffer(const unsigned int* a_data, unsigned int a_count)
		: count(a_count)
	{
		GlCall(glGenBuffers(1, &rendererID));
		GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
		GlCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, a_count * sizeof(GLuint), a_data, GL_STATIC_DRAW));
	}

	IndexBuffer::~IndexBuffer()
	{
		GlCall(glDeleteBuffers(1, &rendererID));
	}

	void IndexBuffer::bind() const
	{
		GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
	}

	void IndexBuffer::unbind() const
	{
		GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

	}

}