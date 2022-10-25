#pragma once

#include "IncludeFiles.h"

#define PI	3.14159265358979323846264338327950288419716939937510

/// <summary>
/// Defining Vector3 operators and floats
/// <summary>
class Vector3 {
public:
	Vector3() : x(0.f), y(0.f), z(0.f) {
	}

	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {
	}

	~Vector3() {
	}
	float x;
	float y;
	float z;

	inline float Dot(Vector3 v) {
		return x * v.x + y * v.y + z * v.z;
	}

	inline float Distance(Vector3 v) {
		return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
	}

	inline double Length() {
		return sqrt(x * x + y * y + z * z);
	}

	inline FRotator ToFRotator() {
		FRotator rot = FRotator();
		float RADPI = (float)(180 / PI);
		rot.Yaw = (float)atan2(y, x) * RADPI;
		rot.Pitch = (float)atan2(z, sqrt((x * x) + (y * y))) * RADPI;
		rot.Roll = 0;
		return rot;
	}
	Vector3 operator+(Vector3 v) {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	Vector3 operator-(Vector3 v) {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}
	Vector3 operator*(float flNum) { return Vector3(x * flNum, y * flNum, z * flNum); }
};
