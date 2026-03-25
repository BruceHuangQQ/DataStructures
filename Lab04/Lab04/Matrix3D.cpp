#if _HAS_CXX20 || __cplusplus >= 202002L

#include <numbers>

static constexpr float Pi = std::numbers::pi_v<float>;

#else

#define _USE_MATH_DEFINES     // must be defined before any #include
#include "Matrix3x3.h"
#include <cassert>
#include <iostream>


#include <cmath>

static const float Pi = static_cast<float>(M_PI);

#endif

const Vector3D Matrix3x3::column(size_t aColumnIndex) const noexcept {
	assert(aColumnIndex < 3);
	const Matrix3x3& M = *this;

	return Vector3D(
		M[0][aColumnIndex],
		M[1][aColumnIndex],
		M[2][aColumnIndex]
	);
}

const Vector3D& Matrix3x3::operator[](size_t aRowIndex) const noexcept {
	return row(aRowIndex);
}

Matrix3x3 Matrix3x3::operator*(const float aScalar) const noexcept {
	const Matrix3x3& M = *this;

	return Matrix3x3(M[0] * aScalar, M[1] * aScalar, M[2] * aScalar);
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& aOther) const noexcept {
	const Matrix3x3& M = *this;

	return Matrix3x3(M[0] + aOther[0], M[1] + aOther[1], M[2] + aOther[2]);
}

Vector3D Matrix3x3::operator*(const Vector3D& aVector) const noexcept {
	const Matrix3x3& M = *this;

	return Vector3D(M[0].dot(aVector), M[1].dot(aVector), M[2].dot(aVector));
}

Matrix3x3 Matrix3x3::getS(const float aX, const float aY) noexcept {
	return Matrix3x3(
		Vector3D(aX, 0.0f, 0.0f),
		Vector3D(0.0f, aY, 0.0f),
		Vector3D(0.0f, 0.0f, 1.0f)
	);
}

Matrix3x3 Matrix3x3::getT(const float aX, const float aY) noexcept {
	return Matrix3x3(
		Vector3D(1.0f, 0.0f, aX),
		Vector3D(0.0f, aY, 0.0f),
		Vector3D(0.0f, 0.0f, 1.0f)
	);
}

Matrix3x3 Matrix3x3::getR(const float aAngleInDegree) noexcept {
	float lRadTheta = aAngleInDegree * Pi;

	float lSinTheta = std::sin(lRadTheta);
	float lCosTheta = std::cos(lRadTheta);

	return Matrix3x3(
		Vector3D(lCosTheta, -lSinTheta, 0.0f),
		Vector3D(lSinTheta, lCosTheta, 0.0f),
		Vector3D(0.0f, 0.0f, 1.0f)
	);
}