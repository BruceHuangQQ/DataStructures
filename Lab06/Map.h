
// COS30008, Tutorial 5, 2026

#pragma once

#include <istream>
#include <ostream>

template<typename K, typename V>
class Map
{
private:
    K fKey;
    V fValue;
    
public:
    Map( const K& aKey = K{}, const V& aValue = V{}) noexcept :
        fKey(aKey),
        fValue(aValue)
    {}

    const K& key() const noexcept
    {
        return fKey;
    }
    
    const V& value() const noexcept
    {
        return fValue;
    }
    
    template<typename U>
    operator U() const noexcept
    {
        return static_cast<U>(fValue);
    }
    
    // Grant friendship to a specific specialization
    friend std::istream& operator>>( std::istream& aIStream, Map<K,V>& aMap );
    friend std::ostream& operator<<( std::ostream& aOStream, const Map<K,V>& aMap );
};
