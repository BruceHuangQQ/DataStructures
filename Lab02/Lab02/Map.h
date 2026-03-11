
#pragma once

#include <istream>
#include <ostream>

class Map
{
public:

    int key;
    int value;

    Map(int aKey = 0, int aValue = 0) :
        key(aKey),
        value(aValue)
    {}

    friend std::istream& operator>>(std::istream& aStream, Map& aObject);
    friend std::ostream& operator<<(std::ostream& aStream, const Map& aObject);
};
