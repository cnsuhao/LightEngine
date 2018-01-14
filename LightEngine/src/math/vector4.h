#pragma once
#include <iostream>

namespace Light
{
	struct Vector4
	{
		float x, y, z, w;

		Vector4();
		Vector4(const float& x, const float& y, const float& z, const float& w);

		Vector4& add(const Vector4& other);
		Vector4& subtract(const Vector4& other);
		Vector4& multiply(const Vector4& other);
		Vector4& divide(const Vector4& other);

		friend Vector4 operator+(const Vector4& Vector4_1, const Vector4& Vector4_2);
		friend Vector4 operator-(const Vector4& Vector4_1, const Vector4& Vector4_2);
		friend Vector4 operator*(const Vector4& Vector4_1, const Vector4& Vector4_2);
		friend Vector4 operator/(const Vector4& Vector4_1, const Vector4& Vector4_2);
		Vector4& operator+=(const Vector4& other);
		Vector4& operator-=(const Vector4& other);
		Vector4& operator*=(const Vector4& other);
		Vector4& operator/=(const Vector4& other);
		bool operator==(const Vector4& other);
		bool operator!=(const Vector4& other);

		friend std::ostream& operator<<(std::ostream& stream, const Vector4& vector);
	};
}