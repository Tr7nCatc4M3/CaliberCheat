#pragma once

#include "IncludeFiles.h"

#define PI	3.14159265358979323846264338327950288419716939937510

/// <summary>
/// Vector2 operations using x, y
/// </summary>
class Vector2 {
public:
	Vector2() {
		x = y = 0.f;
	}

	Vector2(float cx, float cy) {
		x = cx;
		y = cy;
	}

	float x, y;

	Vector2 operator+(const Vector2& input) const {
		return Vector2{ x + input.x, y + input.y };
	}

	Vector2 operator-(const Vector2& input) const {
		return Vector2{ x - input.x, y - input.y };
	}

	Vector2 operator/(const Vector2& input) const {
		return Vector2{ x / input.x, y / input.y };
	}

	Vector2 operator*(const Vector2& input) const {
		return Vector2{ x * input.x, y * input.y };
	}

	Vector2& operator-=(const Vector2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2& operator/=(float input) {
		x /= input;
		y /= input;
		return *this;
	}

	Vector2& operator*=(float input) {
		x *= input;
		y *= input;
		return *this;
	}

	float length() const {
		return std::sqrt((x * x) + (y * y));
	}

	Vector2 normalized() const {
		return { x / length(), y / length() };
	}

	float dot_product(Vector2 input) const {
		return (x * input.x) + (y * input.y);
	}

	float distance(Vector2 input) const {
		return (*this - input).length();
	}

	bool empty() const {
		return x == 0.f; y == 0.f;
	}
};