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

	Vector3 operator+(const Vector3& Vector3_1, const Vector3& Vector3_2)
	{
		return Vector3(Vector3_1.x + Vector3_2.x, Vector3_1.y + Vector3_2.y, Vector3_1.z + Vector3_2.z);
	}

	Vector3 operator-(const Vector3& Vector3_1, const Vector3& Vector3_2)
	{
		return Vector3(Vector3_1.x - Vector3_2.x, Vector3_1.y - Vector3_2.y, Vector3_1.z - Vector3_2.z);
	}

	Vector3 operator*(const Vector3& Vector3_1, const Vector3& Vector3_2)
	{
		return Vector3(Vector3_1.x * Vector3_2.x, Vector3_1.y * Vector3_2.y, Vector3_1.z * Vector3_2.z);
	}

	Vector3 operator/(const Vector3& Vector3_1, const Vector3& Vector3_2)
	{
		return Vector3(Vector3_1.x / Vector3_2.x, Vector3_1.y / Vector3_2.y, Vector3_1.z / Vector3_2.z);
	}


	// Operate on the current Vector3 object in-place and return its reference

	Vector3& Vector3::add(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3& Vector3::subtract(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3& Vector3::multiply(const Vector3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vector3& Vector3::divide(const Vector3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vector3& Vector3::operator+=(const Vector3& other)
	{
		return add(other);
	}

	Vector3& Vector3::operator-=(const Vector3& other)
	{
		return subtract(other);
	}

	Vector3& Vector3::operator*=(const Vector3& other)
	{
		return multiply(other);
	}

	Vector3& Vector3::operator/=(const Vector3& other)
	{
		return divide(other);
	}

	bool Vector3::operator==(const Vector3& other)
	{
		return (x == other.x && y == other.y && z == other.z);
	}

	bool Vector3::operator!=(const Vector3& other)
	{
		return (!(*this == other));
	}


	// Other operator overloads

	std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
	{
		stream << "Vector3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}
}