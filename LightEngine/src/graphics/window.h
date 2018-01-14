#pragma once

#include <glad/glad.h>
#include <GLFW\glfw3.h>
#include<iostream>

namespace light {
	namespace graphics {

		class Window
		{

		private:
			const char* title;
			int width, height;
			GLFWwindow * window;

		public:
			Window(const char* a_title, int a_width, int a_height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

		private:
			void init();
		};
	}
}