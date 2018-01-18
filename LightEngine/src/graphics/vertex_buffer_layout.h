#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "renderer.h"

namespace Light
{
	/*
	VERTEX BUFFER ELEMENT: generic wrapper for storing information about vertex attributes

	VertexBufferElements are used to construct the VertexBufferLayout object. This abstraction simplifies
	the loading of vertex buffers into the vertex array
	*/
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned int normalized;

		static unsigned int getSizeOfType(unsigned int type)
		{
			switch (type)
			{
				case GL_FLOAT:			return 4;
				case GL_UNSIGNED_INT:	return 4;
				case GL_UNSIGNED_BYTE:	return 1;
			}
			ASSERT(false);
			return 0;
		}
	};

	/*
	VERTEX BUFFER LAYOUT: stores information required to set a VertexBuffer's attributes before binding it

	This abstraction can be used by pushing "elements" (attributes) tied to vertices in a VertexBuffer. Each "push"
	represents an attribute associated with the vertices in the VertexBuffer this instance of VertexBufferLayout describes.
	The resulting instance of VertexBufferLayout can then be used to bind the proper attributes to a VertexBuffer.
	*/
	class VertexBufferLayout
	{
	private:
		std::vector<VertexBufferElement> elements;
		unsigned int stride;

	public:
		VertexBufferLayout()
			: stride(0) {}

		// Push an element to the VertexBufferLayout
		template<typename T>
		void Push(unsigned int count) { static_assert(false); }
		
		template<>
		void Push<float>(unsigned int count) 
		{ 
			elements.push_back({ GL_FLOAT, count, GL_FALSE }); 
			stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);

		}

		template<>
		void Push<unsigned int>(unsigned int count)
		{ 
			elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
			stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
		}

		template<>
		void Push<unsigned char>(unsigned int count)
		{ 
			elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
			stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
		}

		// Get the elements stored in this Layout
		inline const std::vector<VertexBufferElement> getElements() const { return elements; }

		// Get the stride of each vertex given the items stored in VertexBufferLayout
		inline unsigned int getStride() const { return stride; }
	};

}
