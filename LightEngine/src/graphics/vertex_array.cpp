#include "vertex_array.h"
#include "renderer.h"

namespace Light
{
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
		bind();
		vb.bind();
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