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

		void LoadBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

		void bind() const;
		void unbind() const;
	};
}