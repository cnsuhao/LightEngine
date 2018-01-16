#include "Vector3.h"

namespace Light
{
	Vector3::Vector3()
	{

	}

	Vector3::Vector3(const float& a_x, const float& a_y, const float& a_z)
	{
		x = a_x;
		y = a_y;
		z = a_z;
	}

	
	// Operate on two Vector3 objects and return a new Vector3 object

	Vector3 operator+(const Vector3& a_Vector3_1, const Vector3& a_Vector3_2)
	{
		return Vector3(a_Vector3_1.x + a_Vector3_2.x, a_Vector3_1.y + a_Vector3_2.y, a_Vector3_1.z + a_Vector3_2.z);
	}

	Vector3 operator-(const Vector3& a_Vector3_1, const Vector3& a_Vector3_2)
	{
		return Vector3(a_Vector3_1.x - a_Vector3_2.x, a_Vector3_1.y - a_Vector3_2.y, a_Vector3_1.z - a_Vector3_2.z);
	}

	Vector3 operator*(const Vector3& a_Vector3_1, const Vector3& a_Vector3_2)
	{
		return Vector3(a_Vector3_1.x * a_Vector3_2.x, a_Vector3_1.y * a_Vector3_2.y, a_Vector3_1.z * a_Vector3_2.z);
	}

	Vector3 operator/(const Vector3& a_Vector3_1, const Vector3& a_Vector3_2)
	{
		return Vector3(a_Vector3_1.x / a_Vector3_2.x, a_Vector3_1.y / a_Vector3_2.y, a_Vector3_1.z / a_Vector3_2.z);
	}


	// Operate on the current Vector3 object in-place and return its reference

	Vector3& Vector3::add(const Vector3& a_other)
	{
		x += a_other.x;
		y += a_other.y;
		z += a_other.z;
		return *this;
	}

	Vector3& Vector3::subtract(const Vector3& a_other)
	{
		x -= a_other.x;
		y -= a_other.y;
		z -= a_other.z;
		return *this;
	}

	Vector3& Vector3::multiply(const Vector3& a_other)
	{
		x *= a_other.x;
		y *= a_other.y;
		z *= a_other.z;
		return *this;
	}

	Vector3& Vector3::divide(const Vector3& a_other)
	{
		x /= a_other.x;
		y /= a_other.y;
		z /= a_other.z;
		return *this;
	}

	Vector3& Vector3::operator+=(const Vector3& a_other)
	{
		return add(a_other);
	}

	Vector3& Vector3::operator-=(const Vector3& a_other)
	{
		return subtract(a_other);
	}

	Vector3& Vector3::operator*=(const Vector3& a_other)
	{
		return multiply(a_other);
	}

	Vector3& Vector3::operator/=(const Vector3& a_other)
	{
		return divide(a_other);
	}

	bool Vector3::operator==(const Vector3& a_other)
	{
		return (x == a_other.x && y == a_other.y && z == a_other.z);
	}

	bool Vector3::operator!=(const Vector3& a_other)
	{
		return (!(*this == a_other));
	}


	// a_other operator overloads

	std::ostream& operator<<(std::ostream& a_stream, const Vector3& a_vector)
	{
		a_stream << "Vector3: (" << a_vector.x << ", " << a_vector.y << ", " << a_vector.z << ")";
		return a_stream;
	}
}