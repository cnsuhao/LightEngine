#include "Vector4.h"

namespace Light
{
	Vector4::Vector4()
	{

	}

	Vector4::Vector4(const float& a_x, const float& a_y, const float& a_z, const float& a_w)
	{
		x = a_x;
		y = a_y;
		z = a_z;
		w = a_w;
	}

	
	// Operate on two Vector4 objects and return a new Vector4 object

	Vector4 operator+(const Vector4& Vector4_1, const Vector4& Vector4_2)
	{
		return Vector4(Vector4_1.x + Vector4_2.x, Vector4_1.y + Vector4_2.y, Vector4_1.z + Vector4_2.z, Vector4_1.w + Vector4_2.w);
	}

	Vector4 operator-(const Vector4& Vector4_1, const Vector4& Vector4_2)
	{
		return Vector4(Vector4_1.x - Vector4_2.x, Vector4_1.y - Vector4_2.y, Vector4_1.z - Vector4_2.z, Vector4_1.w - Vector4_2.w);
	}

	Vector4 operator*(const Vector4& Vector4_1, const Vector4& Vector4_2)
	{
		return Vector4(Vector4_1.x * Vector4_2.x, Vector4_1.y * Vector4_2.y, Vector4_1.z * Vector4_2.z, Vector4_1.w * Vector4_2.w);
	}

	Vector4 operator/(const Vector4& Vector4_1, const Vector4& Vector4_2)
	{
		return Vector4(Vector4_1.x / Vector4_2.x, Vector4_1.y / Vector4_2.y, Vector4_1.z / Vector4_2.z, Vector4_1.w / Vector4_2.w);
	}


	// Operate on the current Vector4 object in-place and return its reference

	Vector4& Vector4::add(const Vector4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Vector4& Vector4::subtract(const Vector4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	Vector4& Vector4::multiply(const Vector4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	Vector4& Vector4::divide(const Vector4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}

	Vector4& Vector4::operator+=(const Vector4& other)
	{
		return add(other);
	}

	Vector4& Vector4::operator-=(const Vector4& other)
	{
		return subtract(other);
	}

	Vector4& Vector4::operator*=(const Vector4& other)
	{
		return multiply(other);
	}

	Vector4& Vector4::operator/=(const Vector4& other)
	{
		return divide(other);
	}

	bool Vector4::operator==(const Vector4& other)
	{
		return (x == other.x && y == other.y && z == other.z && w == other.w);
	}

	bool Vector4::operator!=(const Vector4& other)
	{
		return (!(*this == other));
	}


	// Other operator overloads

	std::ostream& operator<<(std::ostream& stream, const Vector4& vector)
	{
		stream << "Vector4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return stream;
	}
}