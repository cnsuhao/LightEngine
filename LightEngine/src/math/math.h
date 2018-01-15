#pragma once
#define _USE_MATH_DEFINES
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix4.h"

namespace Light
{
	float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}
}