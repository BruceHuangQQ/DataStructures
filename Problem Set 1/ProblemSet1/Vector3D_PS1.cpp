#include "Vector3D.h"
#include <cmath>
#include <sstream>

bool Vector3D::operator==(const Vector3D& aOther) const noexcept
{
    float diffX = std::abs(x() - aOther.x());
    float diffY = std::abs(y() - aOther.y());
    float diffW = std::abs(w() - aOther.w());
    return diffX < eps && diffY < eps && diffW < eps;
}

std::string Vector3D::toString() const noexcept
{
    std::stringstream ss;
    ss << "[" << x() << "," << y() << "," << w() << "]";
    return ss.str();
}