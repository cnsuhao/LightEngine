#include "window.h"

namespace Light
{
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
			if (!glfwInit())
			{
				glfwTerminate();
				std::cout << "Failed to initialize GLFW" << std::endl;
				return;
			}

			window = glfwCreateWindow(width, height, title, NULL, NULL);

			if (!window)
			{
				glfwTerminate();
				std::cout << "Failed to create the GLFW window" << std::endl;
				return;
			}

			glfwMakeContextCurrent(window);

			if (!gladLoadGL())
				std::cout << "Failed to load OpenGL with glad" << std::endl;
			else
				printf("OpenGL Version %d.%d loaded", GLVersion.major, GLVersion.minor);
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


		// Check if the user close the window
		bool Window::closed() const
		{
			return glfwWindowShouldClose(window);
		}
}