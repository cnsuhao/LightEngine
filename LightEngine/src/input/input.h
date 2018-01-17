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
		static bool kInputs[MAX_KEYS];		// keyboard input state array
		static bool mInputs[MAX_BUTTONS];	// mouse button input state array
		static double mouseX, mouseY;
		static double mouseScrollOffsetX, mouseScrollOffsetY;

	public:
		Input(Window* a_window);
		~Input();

		// Retrieve the state of (keycode). True = down. False = up.
		static bool getKeyState(unsigned int keycode);

		// Retrieve the state of a mouse buttone. True = active. False = inactive.
		static bool getMouseButtonState(unsigned int button);

		// Set x_pos/y_pos to the position of the user cursor relative to the window (top left).
		// Off-window cursors return the last position logged in-window.
		static void getMousePosition(double& x_pos, double& y_pos);

		// Set x_offset/y_offset to the stored x/y scroll offset value. This value is initialized at 0.
		static void getMouseScrollOffset(double& x_offset, double& y_offset);

	private:
		// callbacks - polled from inside Window
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
		friend void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	};
}