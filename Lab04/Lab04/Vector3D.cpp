#include <iostream>
#include "Vector3D.h"
#include <cassert>

Vector3D::Vector3D(float aX = 1.0f, float aY = 0.0f, float aW = 1.0f) noexcept :
	fBaseVector(aX, aY),
	fW(aW)
{}; //is it a default vector3d if vector 2d is not provided?

Vector3D::Vector3D(const Vector2D& aVector) noexcept :
	fBaseVector(aVector),
	fW(1.0f)
{};

//float x() const noexcept { return fBaseVector.x(); }
//float y() const noexcept { return fBaseVector.y(); }
//float w() const noexcept { return fW; }

float Vector3D::operator[](size_t aIndex) const noexcept{
	assert(aIndex < 3);
	return *(reinterpret_cast<const float*>(this) + aIndex);
}

Vector3D::operator Vector2D() const noexcept {
	return Vector2D(x() / w(), y() / w());
}

Vector3D Vector3D::operator*(const float aScalar) const noexcept {
	return Vector3D(x() * aScalar, y() * aScalar, w() * aScalar);
}

Vector3D Vector3D::operator+(const Vector3D& aOther) const noexcept {
	return Vector3D(x() + aOther.x(), y() + aOther.y(), w() + aOther.w());
}

float Vector3D::dot(const Vector3D& aOther) const noexcept {
	return x() * aOther.x() + y() * aOther.y() + w() * aOther.w();
}

std::ostream& operator<<(std::ostream& aOStream, const Vector3D& aVector) {
	return aOStream << static_cast<Vector2D>(aVector);
}