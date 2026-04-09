
// COS30008, tutorial 4, 2026

#include "Vector3D.h"
#include <cmath>
#include <cassert>
#include <sstream>

Vector3D::Vector3D( float aX, float aY, float aW ) noexcept :
    fBaseVector(aX, aY),
    fW(aW)
{}

Vector3D::Vector3D( const Vector2D& aVector ) noexcept :
    fBaseVector(aVector),
    fW(1.0f)
{}

float Vector3D::operator[]( size_t aIndex ) const noexcept
{
    assert( aIndex < 3 );

    return *(reinterpret_cast<const float*>(this) + aIndex);
}

Vector3D::operator Vector2D() const noexcept
{
     return Vector2D( x()/w(), y()/w() );
}
           
Vector3D Vector3D::operator*( const float aScalar ) const noexcept
{
    return Vector3D( x() * aScalar, y() * aScalar, w() * aScalar );
}

Vector3D Vector3D::operator+( const Vector3D& aOther ) const noexcept
{
    return Vector3D( x() + aOther.x(), y() + aOther.y(), w() + aOther.w() );
}

float Vector3D::dot( const Vector3D& aOther ) const noexcept
{
    return x() * aOther.x() + y() * aOther.y() + w() * aOther.w();
}

std::ostream& operator<<( std::ostream& aOStream, const Vector3D& aVector )
{
    return aOStream << static_cast<Vector2D>(aVector);
}

// Problem Set 1 extension

// operator== : compare two vectors with epsilon tolerance
//bool Vector3D::operator==(const Vector3D& aOther) const noexcept
//{
//    // Get the difference of each component
//    float diffX = std::abs(x() - aOther.x());
//    float diffY = std::abs(y() - aOther.y());
//    float diffW = std::abs(w() - aOther.w());
//
//    // All differences must be smaller than epsilon to be considered equal
//    return diffX < eps && diffY < eps && diffW < eps;
//}
//
//// toString() : return string representation "[x,y,w]"
//std::string Vector3D::toString() const noexcept
//{
//    std::stringstream ss;
//    ss << "[" << x() << "," << y() << "," << w() << "]";
//    return ss.str();
//}
