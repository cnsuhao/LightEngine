#include "src/graphics/window.h"

int main()
{
	using namespace light;
	using namespace graphics;

	Window window("Light Engine", 1920, 1080);
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);



	while (!window.closed())
	{
		window.clear();
		window.update();
	}


	//system("PAUSE");
	return 0;
}