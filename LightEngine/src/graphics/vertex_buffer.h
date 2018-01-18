#pragma once

namespace Light
{
	class VertexBuffer
	{
	private:
		// unique ID associated with 
		unsigned int rendererID;

	public:
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();

		// bind (this) buffer (associated with the rendererID)
		void bind() const;

		// unbind array buffer
		void unbind() const;
	};

}