#include "vector2.h"

namespace Light
{
	Vector2::Vector2()
	{

	}

	Vector2::Vector2(const float& a_x, const float& a_y)
	{
		x = a_x;
		y = a_y;
	}

	
	// Operate on two Vector2 objects and return a new Vector2 object

	Vector2 operator+(const Vector2& vector2_1, const Vector2& vector2_2)
	{
		return Vector2(vector2_1.x + vector2_2.x, vector2_1.y + vector2_2.y);
	}

	Vector2 operator-(const Vector2& vector2_1, const Vector2& vector2_2)
	{
		return Vector2(vector2_1.x - vector2_2.x, vector2_1.y - vector2_2.y);
	}

	Vector2 operator*(const Vector2& vector2_1, const Vector2& vector2_2)
	{
		return Vector2(vector2_1.x * vector2_2.x, vector2_1.y * vector2_2.y);
	}

	Vector2 operator/(const Vector2& vector2_1, const Vector2& vector2_2)
	{
		return Vector2(vector2_1.x / vector2_2.x, vector2_1.y / vector2_2.y);
	}


	// Operate on the current Vector2 object in-place and return its reference

	Vector2& Vector2::add(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2& Vector2::subtract(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2& Vector2::multiply(const Vector2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2& Vector2::divide(const Vector2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector2& Vector2::operator+=(const Vector2& other)
	{
		return add(other);
	}

	Vector2& Vector2::operator-=(const Vector2& other)
	{
		return subtract(other);
	}

	Vector2& Vector2::operator*=(const Vector2& other)
	{
		return multiply(other);
	}

	Vector2& Vector2::operator/=(const Vector2& other)
	{
		return divide(other);
	}

	bool Vector2::operator==(const Vector2& other)
	{
		return (x == other.x && y == other.y);
	}

	bool Vector2::operator!=(const Vector2& other)
	{
		return (!(*this == other));
	}


	// Other operator overloads

	std::ostream& operator<<(std::ostream& stream, const Vector2& vector)
	{
		stream << "Vector2: (" << vector.x << ", " << vector.y << ")";
		return stream;
	}
}