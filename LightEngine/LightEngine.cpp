#include "LightEngine.h"

namespace Light
{
	LightEngine::LightEngine(const char* window_title, int window_width, int window_height)
	{
		window = new Window(window_title, window_width, window_height);
		glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

		input = new Input(window);
	}

	LightEngine::~LightEngine()
	{
		delete window;
		delete input;
	}
}

