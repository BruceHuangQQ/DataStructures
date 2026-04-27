
// COS30008, Tutorial 6, 2026

#pragma once

#include "ArraySorter.h"

template<typename T, typename Order = std::greater<T>>
class BubbleSorter : public ArraySorter<T>
{
private:
    
    Order fOrderFtn;
    
public:
    
    BubbleSorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept :
        ArraySorter<T>(aArray, aSize),
        fOrderFtn()
    {}

    void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept override
    {
        ArraySorter<T>::sort();
        
        BubbleSorter& Array = *this;
        
        if ( this->size() > 0 )
        {
            for ( size_t i = this->size() - 1; i > 0; i-- )
            {
                for ( int j = 0; j < i; j++ )
                {
                    if ( fOrderFtn( Array[j+1], Array[j] ) )
                    {
                        this->swap( Array[j+1], Array[j] );
                    }
                }
                
                if ( aDoLog )
                {
                    aOStream << Array << std::endl;
                }
            }
        }
    }
};
