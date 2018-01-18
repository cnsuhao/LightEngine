#include "vertex_array.h"
#include "renderer.h"

namespace Light
{
	/*
	VERTEX ARRAY: an OpenGL specification that allows vertex buffer layouts
	(and their associated buffers) to be stored in an indexable array.

	This allows us to simply reference the vertex spec. we need for our
	vertex buffer, load/bind that buffer, and apply the proper vertex
	attributes. This prevents us from needing to manually re-define
	vertex attributes before every draw call.
	*/
	VertexArray::VertexArray()
	{
		GlCall(glGenVertexArrays(1, &rendererID));
	}

	VertexArray::~VertexArray()
	{
		GlCall(glDeleteVertexArrays(1, &rendererID));
	}

	void VertexArray::LoadBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
	{
		// bind the vertex array and vertex buffer
		bind();
		vb.bind();

		// define the attributes provided in VertexBufferLayout for the vertex buffer
		const auto& elements = layout.getElements();
		unsigned int offset = 0;
		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			GlCall(glEnableVertexAttribArray(i));
			GlCall(glVertexAttribPointer(i, element.count, element.type, 
				element.normalized, layout.getStride(), (const void*)offset));
			offset += element.count * VertexBufferElement::getSizeOfType(element.type);
		}
		
	}

	void VertexArray::bind() const
	{
		GlCall(glBindVertexArray(rendererID));
	}

	void VertexArray::unbind() const
	{
		GlCall(glBindVertexArray(0));
	}
}