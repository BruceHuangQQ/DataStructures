
// COS30008 - Problem Set 3, 2026

#pragma once

#include <ostream>

template<typename K, typename V>
class SortablePair
{
public:
    
    SortablePair( const K& aFirst = K{}, const V& aSecond = V{} ) noexcept;
    
    const K& first() const noexcept;
    const V& second() const noexcept;

    bool operator==( const SortablePair& aOther ) const noexcept;
    
    bool operator<( const SortablePair& aOther ) const noexcept;
    
    friend std::ostream& operator<<( std::ostream& aOStream, const SortablePair<K,V>& aPair );
    
private:
    
    K fFirst;
    V fSecond;
};

// Constructor - store both values, K{} and V{}
template<typename K, typename V>
SortablePair<K, V>::SortablePair(const K& aFirst, const V& aSecond) noexcept {
    fFirst = aFirst;
    fSecond = aSecond;
}

//first()
template<typename K, typename V>
const K& SortablePair<K, V>::first() const noexcept {
    return fFirst;
}

//second()
template<typename K, typename V>
const V& SortablePair<K, V>::second() const noexcept {
    return fSecond;
}

// Equality - both components must match
template<typename K, typename V>
bool SortablePair<K, V>::operator==(const SortablePair& aOther) const noexcept
{
    return fFirst == aOther.fFirst && fSecond == aOther.fSecond;
}

template<typename K, typename V>
bool SortablePair<K, V>::operator<(const SortablePair& aOther) const noexcept
{
    return fFirst > aOther.fFirst;
}
