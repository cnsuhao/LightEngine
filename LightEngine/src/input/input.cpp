#include "input.h"

namespace Light
{
	// statics
	bool Input::kInputs[MAX_KEYS];
	bool Input::mInputs[MAX_BUTTONS];
	double Input::mouseX;
	double Input::mouseY;
	double Input::mouseScrollOffsetX;
	double Input::mouseScrollOffsetY;

	// callbacks
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
	void mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	/*
	INPUT: responsible for obtaining input information from its associated Window object.

	On initialization input state arrays are initialized. Note that the current implementation makes
	these STATIC (under the assumption that in the event of multiple windows, we would want to use the
	same input devices). Also note that multi-window applications have not been tested, however they
	should be supported as long as the current window "focus" is tracked and the inputs are interpreted
	accordingly from external classes.
	*/
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

	bool Input::getKeyState(unsigned int a_keycode)
	{
		if (a_keycode >= MAX_KEYS)
		{
			return false;
			// log something here...
		}

		return Input::kInputs[a_keycode];
	}

	bool Input::getMouseButtonState(unsigned int a_button)
	{
		if (a_button >= MAX_BUTTONS)
		{
			return false;
			// log something here...
		}

		return mInputs[a_button];
	}

	void Input::getMousePosition(double& a_x_pos, double& a_y_pos)
	{
		a_x_pos = mouseX;
		a_y_pos = mouseY;
	}

	void Input::getMouseScrollOffset(double& a_x_offset, double& a_y_offset)
	{
		a_x_offset = mouseScrollOffsetX;
		a_y_offset = mouseScrollOffsetY;
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