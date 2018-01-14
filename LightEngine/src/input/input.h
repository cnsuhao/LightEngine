#pragma once

#include "..\graphics\window.h"

namespace Light
{

#define MAX_KEYS 512
#define MAX_BUTTONS 32

	class Input
	{

	private:
		Window* window;
		static bool kInputs[MAX_KEYS];
		static bool mInputs[MAX_BUTTONS];
		static double mouseX, mouseY;
		static double mouseScrollOffsetX, mouseScrollOffsetY;

	public:

	private:
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
		friend void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	public:
		Input(Window* a_window);
		~Input();
		static bool getKeyState(unsigned int keycode);
		static bool getMouseButtonState(unsigned int button);
		static void getMousePosition(double& x_pos, double& y_pos);
		static void getMouseScrollOffset(double& x_offset, double& y_offset);
	};
}