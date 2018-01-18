#pragma once
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

namespace Light
{
	class VertexArray
	{
	private:
		unsigned int rendererID;
	public:
		VertexArray();
		~VertexArray();

		// given a VertexBuffer & VertexBufferLayout, bind the buffer and assign attributes
		void LoadBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

		// bind this vertex array
		void bind() const;

		// unbind vertex array
		void unbind() const;
	};
}