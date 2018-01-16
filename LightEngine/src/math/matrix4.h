#pragma once
#include <math.h>		//for sin/cos/tan
#include "math.h"

namespace Light
{
	struct Matrix4
	{
		union 
		{
			float underlyingArray[4 * 4];
			Vector4 columns[4];
		};
		

		Matrix4();
		Matrix4(float diagonal);

		Matrix4& multiply(const Matrix4& other);
		friend Matrix4 operator*(Matrix4 matrix4_1, const Matrix4& matrix4_2);
		Matrix4& operator*=(const Matrix4& other);

		static Matrix4 identity();
		static Matrix4 orthographic(float clip_left, float clip_right, float clip_top, float clip_bottom, float clip_near, float clip_far);
		
		static Matrix4 translation(const Vector3& translation);
		static Matrix4 rotation(float angle, const Vector3& axis);
		static Matrix4 scale(const Vector3& scale);
	};
}
