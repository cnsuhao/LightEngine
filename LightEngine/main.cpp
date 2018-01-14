#include "LightEngine.h"
#include "src\math\vector2.h"

using namespace Light;

int main()
{
	LightEngine engine("Light Engine", 1920, 1080);
	Vector2 vec1(1, 1);
	Vector2 vec2(1, 1);
	int result = vec1 != vec2;

	std::cout << "\n" << result << std::endl;


	while (!engine.window->closed())
	{
		engine.window->clear();
		engine.window->update();
	}

	//system("PAUSE");
	return 0;
}