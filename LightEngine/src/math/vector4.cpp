#include "Vector4.h"

namespace Light
{
	Vector4::Vector4(const float& a_x, const float& a_y, const float& a_z, const float& a_w)
	{
		x = a_x;
		y = a_y;
		z = a_z;
		w = a_w;
	}

	
	// Operate on two Vector4 objects and return a new Vector4 object

	Vector4 operator+(const Vector4& a_Vector4_1, const Vector4& a_Vector4_2)
	{
		return Vector4(a_Vector4_1.x + a_Vector4_2.x, a_Vector4_1.y + a_Vector4_2.y, a_Vector4_1.z + a_Vector4_2.z, a_Vector4_1.w + a_Vector4_2.w);
	}

	Vector4 operator-(const Vector4& a_Vector4_1, const Vector4& a_Vector4_2)
	{
		return Vector4(a_Vector4_1.x - a_Vector4_2.x, a_Vector4_1.y - a_Vector4_2.y, a_Vector4_1.z - a_Vector4_2.z, a_Vector4_1.w - a_Vector4_2.w);
	}

	Vector4 operator*(const Vector4& a_Vector4_1, const Vector4& a_Vector4_2)
	{
		return Vector4(a_Vector4_1.x * a_Vector4_2.x, a_Vector4_1.y * a_Vector4_2.y, a_Vector4_1.z * a_Vector4_2.z, a_Vector4_1.w * a_Vector4_2.w);
	}

	Vector4 operator/(const Vector4& a_Vector4_1, const Vector4& a_Vector4_2)
	{
		return Vector4(a_Vector4_1.x / a_Vector4_2.x, a_Vector4_1.y / a_Vector4_2.y, a_Vector4_1.z / a_Vector4_2.z, a_Vector4_1.w / a_Vector4_2.w);
	}


	// Operate on the current Vector4 object in-place and return its reference

	Vector4& Vector4::add(const Vector4& a_other)
	{
		x += a_other.x;
		y += a_other.y;
		z += a_other.z;
		w += a_other.w;
		return *this;
	}

	Vector4& Vector4::subtract(const Vector4& a_other)
	{
		x -= a_other.x;
		y -= a_other.y;
		z -= a_other.z;
		w -= a_other.w;
		return *this;
	}

	Vector4& Vector4::multiply(const Vector4& a_other)
	{
		x *= a_other.x;
		y *= a_other.y;
		z *= a_other.z;
		w *= a_other.w;
		return *this;
	}

	Vector4& Vector4::divide(const Vector4& a_other)
	{
		x /= a_other.x;
		y /= a_other.y;
		z /= a_other.z;
		w /= a_other.w;
		return *this;
	}

	Vector4& Vector4::operator+=(const Vector4& a_other)
	{
		return add(a_other);
	}

	Vector4& Vector4::operator-=(const Vector4& a_other)
	{
		return subtract(a_other);
	}

	Vector4& Vector4::operator*=(const Vector4& a_other)
	{
		return multiply(a_other);
	}

	Vector4& Vector4::operator/=(const Vector4& a_other)
	{
		return divide(a_other);
	}

	bool Vector4::operator==(const Vector4& a_other)
	{
		return (x == a_other.x && y == a_other.y && z == a_other.z && w == a_other.w);
	}

	bool Vector4::operator!=(const Vector4& a_other)
	{
		return (!(*this == a_other));
	}


	// a_other operator overloads

	std::ostream& operator<<(std::ostream& a_stream, const Vector4& a_vector)
	{
		a_stream << "Vector4: (" << a_vector.x << ", " << a_vector.y << ", " << a_vector.z << ", " << a_vector.w << ")";
		return a_stream;
	}
}