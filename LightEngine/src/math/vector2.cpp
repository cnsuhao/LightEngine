#include "Vector2.h"

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

	Vector2 operator+(const Vector2& a_Vector2_1, const Vector2& a_Vector2_2)
	{
		return Vector2(a_Vector2_1.x + a_Vector2_2.x, a_Vector2_1.y + a_Vector2_2.y);
	}

	Vector2 operator-(const Vector2& a_Vector2_1, const Vector2& a_Vector2_2)
	{
		return Vector2(a_Vector2_1.x - a_Vector2_2.x, a_Vector2_1.y - a_Vector2_2.y);
	}

	Vector2 operator*(const Vector2& a_Vector2_1, const Vector2& a_Vector2_2)
	{
		return Vector2(a_Vector2_1.x * a_Vector2_2.x, a_Vector2_1.y * a_Vector2_2.y);
	}

	Vector2 operator/(const Vector2& a_Vector2_1, const Vector2& a_Vector2_2)
	{
		return Vector2(a_Vector2_1.x / a_Vector2_2.x, a_Vector2_1.y / a_Vector2_2.y);
	}


	// Operate on the current Vector2 object in-place and return its reference

	Vector2& Vector2::add(const Vector2& a_other)
	{
		x += a_other.x;
		y += a_other.y;
		return *this;
	}

	Vector2& Vector2::subtract(const Vector2& a_other)
	{
		x -= a_other.x;
		y -= a_other.y;
		return *this;
	}

	Vector2& Vector2::multiply(const Vector2& a_other)
	{
		x *= a_other.x;
		y *= a_other.y;
		return *this;
	}

	Vector2& Vector2::divide(const Vector2& a_other)
	{
		x /= a_other.x;
		y /= a_other.y;
		return *this;
	}

	Vector2& Vector2::operator+=(const Vector2& a_other)
	{
		return add(a_other);
	}

	Vector2& Vector2::operator-=(const Vector2& a_other)
	{
		return subtract(a_other);
	}

	Vector2& Vector2::operator*=(const Vector2& a_other)
	{
		return multiply(a_other);
	}

	Vector2& Vector2::operator/=(const Vector2& a_other)
	{
		return divide(a_other);
	}

	bool Vector2::operator==(const Vector2& a_other)
	{
		return (x == a_other.x && y == a_other.y);
	}

	bool Vector2::operator!=(const Vector2& a_other)
	{
		return (!(*this == a_other));
	}


	// other operator overloads

	std::ostream& operator<<(std::ostream& a_stream, const Vector2& a_vector)
	{
		a_stream << "Vector2: (" << a_vector.x << ", " << a_vector.y << ")";
		return a_stream;
	}
}