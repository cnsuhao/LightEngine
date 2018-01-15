#pragma once
#include <math.h>		//for sin/cos/tan
#include "math.h"


namespace Light
{
	struct Matrix4
	{
		float underlyingArray[4 * 4];

		Matrix4();
		Matrix4(float diagonal);

		Matrix4& multiply(const Matrix4& other);
		friend Matrix4 operator*(Matrix4 matrix4_1, const Matrix4& matrix4_2);
		Matrix4& operator*=(const Matrix4& other);

		static Matrix4 identity();
		static Matrix4 orthographic(float a_clip_left, float a_clip_right, float a_clip_top, float a_clip_bottom, float a_clip_near, float a_clip_far);
		
		static Matrix4 translation(const Vector3& a_translation);
		static Matrix4 rotation(float a_angle, const Vector3& a_axis);
		static Matrix4 scale(const Vector3& a_scale);
	};


}
