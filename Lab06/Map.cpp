
// COS30008, Tutorial 5, 2026

#include "Map.h"

std::istream& operator>>(std::istream& aIStream, Map<int,int>& aMap)
{
    aIStream >> aMap.fKey >> aMap.fValue;

    return aIStream;
}

std::ostream& operator<<(std::ostream& aOStream, const Map<int, int>& aMap)
{
    aOStream << '{' << aMap.fKey << ", " << aMap.fValue << '}';

    return aOStream;
}
