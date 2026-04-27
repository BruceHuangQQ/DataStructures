
// COS30008, Tutorial 6, 2026

#pragma once

#include <cstdint>
#include <iostream>
#include <cassert>

template<typename T>
class ArraySorter
{
public:
    
    ArraySorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept :
        fElements(new T[aSize]),
        fSize(aSize),
        fSwapCount(0)
    {
        for ( size_t i = 0; i < fSize; i++ )
        {
            fElements[i] = aArray[i];
        }
    }
    
    virtual ~ArraySorter() noexcept
    {
        delete[] fElements;
    }
    
    size_t size() const noexcept
    {
        return fSize;
    }

    size_t swapCount() const noexcept
    {
        return fSwapCount;
    }
    
    void swap( T& aLeft, T& aRight ) noexcept
    {
        std::swap( aLeft, aRight );
        
        fSwapCount++;
    }

    T& operator[]( size_t aIndex ) const noexcept
    {
        assert( aIndex < fSize );
        
        return const_cast<T&>(fElements[aIndex]);
    }
    
    virtual void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept
    {
        fSwapCount = 0;
    }
    
    friend std::ostream& operator<<( std::ostream& aOStream, const ArraySorter<T>& aSorter );
    
private:
    
    T* fElements;
    size_t fSize;
    size_t fSwapCount;
};
