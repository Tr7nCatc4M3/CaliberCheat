#pragma once

#include "IncludeFiles.h"

#define PI	3.14159265358979323846264338327950288419716939937510

/// <summary>
/// Vector4 operations using x, y, z, a
/// </summary>
class Vector4 {
public:
	Vector4() {
		x = y = z = a = 0.f;
	}

	Vector4(float cx, float cy, float cz, float ca) {
		x = cx;
		y = cy;
		z = cz;
		a = ca;
	}

	float x, y, z, a;

	Vector4 operator+(const Vector4& input) const {
		return Vector4{ x + input.x, y + input.y, z + input.z, a + input.a };
	}

	Vector4 operator-(const Vector4& input) const {
		return Vector4{ x - input.x, y - input.y, z - input.z, a - input.a };
	}

	Vector4 operator/(const Vector4& input) const {
		return Vector4{ x / input.x, y / input.y, z / input.z, a / input.a };
	}

	Vector4 operator*(const Vector4& input) const {
		return Vector4{ x * input.x, y * input.y, z * input.z, a * input.a };
	}

	Vector4& operator-=(const Vector4& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		a -= v.a;
		return *this;
	}

	Vector4& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		a /= input;
		return *this;
	}

	Vector4& operator*=(float input) {
		x *= input;
		y *= input;
		z *= input;
		a *= input;
		return *this;
	}

	bool operator==(const Vector4& input) const {
		return x == input.x && y == input.y && z == input.z && a == input.a;
	}

	void make_absolute() {
		x = std::abs(x);
		y = std::abs(y);
		z = std::abs(z);
		a = std::abs(a);
	}

	float length_sqr() const {
		return (x * x) + (y * y) + (z * z) + (a * a);
	}

	float length() const {
		return std::sqrt(length_sqr());
	}

	float length_2d() const {
		return std::sqrt((x * x) + (y * y));
	}

	Vector4 normalized() const {
		return { x / length(), y / length(), z / length(), a / length() };
	}

	float dot_product(Vector4 input) const {
		return (x * input.x) + (y * input.y) + (z * input.y) + (a * input.a);
	}

	float distance(Vector4 input) const {
		return (*this - input).length();
	}

	float distance_2d(Vector4 input) const {
		return (*this - input).length_2d();
	}

	void clamp() { // https://learn.microsoft.com/en-us/cpp/code-quality/c6031?f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(C6031)%26rd%3Dtrue&view=msvc-170
		std::clamp(x, -89.f, 89.f);
		std::clamp(y, -180.f, 180.f);

		z = 0.f;
	}

	bool empty() const {
		return x == 0.f && y == 0.f && z == 0.f && a == 0.f;
	}
};