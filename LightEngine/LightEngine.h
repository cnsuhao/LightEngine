#pragma once

#include "src/graphics/window.h"
#include "src/input/input.h"

namespace Light
{
	class LightEngine
	{

	private:

	public:
		Window* window;
		Input* input;

	private:

	public:
		LightEngine(const char* window_title, int window_width, int window_height);
		~LightEngine();
	};
}