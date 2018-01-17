#include "window.h"

namespace Light
{
	/*
	WINDOW: a wrapper for our GLFWwindow object.
	
	Window is responsible for providing buffer clear/swap functionality, polling for events (tied to
	the window object), and checking if the user has closed the window.
	*/
	Window::Window(const char* a_title, int a_width, int a_height)
	{
		title = a_title;
		width = a_width;
		height = a_height;
		init();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	// Creates a window with OpenGL
	void Window::init()
	{
		// Initialize GLFW
		if (!glfwInit())
		{
			glfwTerminate();
			std::cout << "Failed to initialize GLFW" << std::endl;
			return;
		}

		// Create the window
		window = glfwCreateWindow(width, height, title, NULL, NULL);

		// Check the window was created
		if (!window)
		{
			glfwTerminate();
			std::cout << "Failed to create the GLFW window" << std::endl;
			return;
		}

		// Make this window the current context
		glfwMakeContextCurrent(window);

		// Initialize GLAD
		if (!gladLoadGL())
			std::cout << "Failed to load OpenGL with glad" << std::endl;
		else
			std::cout << glGetString(GL_VERSION) << std::endl;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	bool Window::closed() const
	{
		return glfwWindowShouldClose(window);
	}
}