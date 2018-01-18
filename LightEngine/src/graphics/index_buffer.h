#pragma once

namespace Light
{
	class IndexBuffer
	{
	private:
		unsigned int rendererID;
		unsigned int count;

	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		// bind this index buffer
		void bind() const;

		// unbind this index buffer
		void unbind() const;

		inline unsigned int getCount() const { return count; }
	};

}