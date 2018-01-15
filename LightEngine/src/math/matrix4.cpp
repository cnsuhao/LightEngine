#include "matrix4.h"

namespace Light
{
	Matrix4::Matrix4()
	{
		for (int i = 0; i < 4 * 4; i++)
			underlyingArray[i] = 0.0f;
	}

	Matrix4::Matrix4(float diagonal)
	{
		for (int i = 0; i < 4 * 4; i++)
			underlyingArray[i] = 0.0f;

		underlyingArray[0 + (0 * 4)] = diagonal;
		underlyingArray[1 + (1 * 4)] = diagonal;
		underlyingArray[2 + (2 * 4)] = diagonal;
		underlyingArray[3 + (3 * 4)] = diagonal;
	}

	Matrix4 Matrix4::identity()
	{
		return Matrix4(1.0f);
	}

	Matrix4& Matrix4::multiply(const Matrix4& other)
	{
		for (int column = 0; column < 4; column++)
		{
			for (int row = 0; row < 4; row++)
			{
				float sum = 0;
				for (int element = 0; element < 4; element++)
				{		
					sum += underlyingArray[row + (element * 4)] * other.underlyingArray[element + (column * 4)];
				}
				// this will probably not work
				underlyingArray[row + (column * 4)] = sum;
			}
		}
		return *this;
	}

	Matrix4 operator*(Matrix4 matrix4_1, const Matrix4& matrix4_2)
	{
		return matrix4_1.multiply(matrix4_2);
	}

	Matrix4& Matrix4::operator*=(const Matrix4& other)
	{
		return multiply(other);
	}

	Matrix4 Matrix4::orthographic(float a_clip_left, float a_clip_right, float a_clip_top, float a_clip_bottom, float a_clip_near, float a_clip_far)
	{
		Matrix4 output(1.0f);

		output.underlyingArray[0 + (0 * 4)] = 2.0f / (a_clip_right - a_clip_left);
		output.underlyingArray[1 + (1 * 4)] = 2.0f / (a_clip_top - a_clip_bottom);
		output.underlyingArray[2 + (2 * 4)] = 2.0f / (a_clip_near - a_clip_far);

		output.underlyingArray[0 + (3 * 4)] = (a_clip_left + a_clip_right) / (a_clip_left - a_clip_right);
		output.underlyingArray[1 + (3 * 4)] = (a_clip_bottom + a_clip_top) / (a_clip_bottom - a_clip_top);
		output.underlyingArray[2 + (3 * 4)] = (a_clip_far + a_clip_near) / (a_clip_far - a_clip_near);

		return output;
	}

	Matrix4 Matrix4::translation(const Vector3& a_translation)
	{
		Matrix4 output(1.0f);

		output.underlyingArray[0 + (3 * 4)] = a_translation.x;
		output.underlyingArray[1 + (3 * 4)] = a_translation.y;
		output.underlyingArray[2 + (3 * 4)] = a_translation.z;

		return output;
	}

	Matrix4 Matrix4::rotation(float a_angle, const Vector3& a_axis)
	{
		Matrix4 output(1.0f);

		float radians = toRadians(a_angle);
		float cosRadians = cos(radians);
		float sinRadians = sin(radians);
		float omc = 1.0f - cos(radians);

		float x = a_axis.x;
		float y = a_axis.y;
		float z = a_axis.z;
		
		output.underlyingArray[0 + (0 * 4)] = x * omc + cosRadians;
		output.underlyingArray[1 + (0 * 4)] = y * x * omc + z * sinRadians;
		output.underlyingArray[2 + (0 * 4)] = x * z * omc - y * sinRadians;

		output.underlyingArray[0 + (1 * 4)] = x * y * omc - z * sinRadians;
		output.underlyingArray[1 + (1 * 4)] = y * omc + cosRadians;
		output.underlyingArray[2 + (1 * 4)] = y * z * omc + x * sinRadians;

		output.underlyingArray[0 + (2 * 4)] = x * z * omc + y * sinRadians;
		output.underlyingArray[1 + (2 * 4)] = y * z * omc - x * sinRadians;
		output.underlyingArray[2 + (2 * 4)] = z * omc + cosRadians;

		return output;
	}

	Matrix4 Matrix4::scale(const Vector3& a_scale)
	{
		Matrix4 output(1.0f);

		output.underlyingArray[0 + (0 * 4)] = a_scale.x;
		output.underlyingArray[1 + (1 * 4)] = a_scale.y;
		output.underlyingArray[2 + (2 * 4)] = a_scale.z;

		return output;
	}

}