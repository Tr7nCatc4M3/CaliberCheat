#pragma once

#include "IncludeFiles.h"

#define PI	3.14159265358979323846264338327950288419716939937510

/// <summary>
/// Vector3 operations using x, y, z
/// </summary>
class Vector3 {
public:
	Vector3() {
		x = y = z = 0.f;
	}

	Vector3(float cx, float cy, float cz) {
		x = cx;
		y = cy;
		z = cz;
	}

	float x, y, z;

	Vector3 operator+(const Vector3& input) const {
		return Vector3{ x + input.x, y + input.y, z + input.z };
	}

	Vector3 operator-(const Vector3& input) const {
		return Vector3{ x - input.x, y - input.y, z - input.z };
	}

	Vector3 operator/(const Vector3& input) const {
		return Vector3{ x / input.x, y / input.y, z / input.z };
	}

	Vector3 operator*(const Vector3& input) const {
		return Vector3{ x * input.x, y * input.y, z * input.z };
	}

	Vector3& operator-=(const Vector3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vector3& operator*=(float input) {
		x *= input;
		y *= input;
		z *= input;
		return *this;
	}

	Vector3& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		return *this;
	}

	bool operator==(const Vector3& input) const {
		return x == input.x && y == input.y && z == input.z;
	}

	// These are not needed but I intend to use later on
	void make_absolute() {
		x = std::abs(x);
		y = std::abs(y);
		z = std::abs(z);
	}

	float length_sqr() const {
		return (x * x) + (y * y) + (z * z);
	}

	float length() const {
		return std::sqrt(length_sqr());
	}

	float length_2d() const {
		return std::sqrt((x * x) + (y * y));
	}

	Vector3 normalized() const {
		return { x / length(), y / length(), z / length() };
	}

	float dot_product(Vector3 input) const {
		return (x * input.x) + (y * input.y) + (z * input.z);
	}

	float distance(Vector3 input) const {
		return (*this - input).length();
	}

	float distance_2d(Vector3 input) const {
		return (*this - input).length_2d();
	}

	// No clamping

	bool empty() const {
		return x == 0.f && y == 0.f && z == 0.f;
	}
};