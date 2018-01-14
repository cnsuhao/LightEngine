#pragma once
#include <iostream>

namespace Light
{
	struct Vector2
	{
		float x, y;

		Vector2();
		Vector2(const float& x, const float& y);

		Vector2& add(const Vector2& other);
		Vector2& subtract(const Vector2& other);
		Vector2& multiply(const Vector2& other);
		Vector2& divide(const Vector2& other);

		friend Vector2 operator+(const Vector2& Vector2_1, const Vector2& Vector2_2);
		friend Vector2 operator-(const Vector2& Vector2_1, const Vector2& Vector2_2);
		friend Vector2 operator*(const Vector2& Vector2_1, const Vector2& Vector2_2);
		friend Vector2 operator/(const Vector2& Vector2_1, const Vector2& Vector2_2);
		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		Vector2& operator*=(const Vector2& other);
		Vector2& operator/=(const Vector2& other);
		bool operator==(const Vector2& other);
		bool operator!=(const Vector2& other);

		friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
	};
}