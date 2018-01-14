#include "input.h"

namespace Light
{
	bool Input::kInputs[MAX_KEYS];
	bool Input::mInputs[MAX_BUTTONS];
	double Input::mouseX;
	double Input::mouseY;
	double Input::mouseScrollOffsetX;
	double Input::mouseScrollOffsetY;

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
	void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	Input::Input(Window* a_window)
	{
		window = a_window;

		for (int i = 0; i < MAX_KEYS; i++)
			kInputs[i] = false;
		for (int i = 0; i < MAX_BUTTONS; i++)
			mInputs[i] = false;

		glfwSetKeyCallback(window->window, key_callback);
		glfwSetMouseButtonCallback(window->window, mouse_button_callback);
		glfwSetCursorPosCallback(window->window, mouse_pos_callback);
		glfwSetScrollCallback(window->window, mouse_scroll_callback);
	}

	Input::~Input()
	{

	}

	bool Input::getKeyState(unsigned int keycode)
	{
		if (keycode >= MAX_KEYS)
		{
			return false;
			// log something here...
		}

		return Input::kInputs[keycode];
	}

	bool Input::getMouseButtonState(unsigned int button)
	{
		if (button >= MAX_BUTTONS)
		{
			return false;
			// log something here...
		}

		return mInputs[button];
	}

	void Input::getMousePosition(double& x_pos, double& y_pos)
	{
		x_pos = mouseX;
		y_pos = mouseY;
	}

	void Input::getMouseScrollOffset(double& x_offset, double& y_offset)
	{
		x_offset = mouseScrollOffsetX;
		y_offset = mouseScrollOffsetY;
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Input::kInputs[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Input::mInputs[button] = action != GLFW_RELEASE;
	}

	void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Input::mouseX = xpos;
		Input::mouseY = ypos;
	}

	void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Input::mouseScrollOffsetX += xoffset;
		Input::mouseScrollOffsetY += yoffset;
	}
}