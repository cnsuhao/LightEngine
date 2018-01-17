#pragma once

#include <glad/glad.h>
#include <GLFW\glfw3.h>
#include<iostream>

namespace Light 
{
	class Window
	{
		friend class Input;

	private:
		const char* title;
		int width, height;
		GLFWwindow* window;

	public:
		// Constructs a new window and makes it the current context
		Window(const char* title, int width, int height);
		~Window();

		// Clears the OpenGL buffer bits.
		// This should be done before update() swaps the buffers.
		void clear() const;

		// Polls for events in the window. Swaps the buffers.
		void update();

		// Checks if the user closed the window.
		bool closed() const;

	private:
		void init();
	};
}