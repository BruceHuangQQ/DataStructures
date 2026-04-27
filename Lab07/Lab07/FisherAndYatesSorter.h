
// COS30008, Tutorial 6, 2026

#pragma once

#include "ArraySorter.h"

#include <cstdlib>
#include <ctime>

template<typename T, typename Order = std::greater<T>>
class FisherAndYatesSorter : public ArraySorter<T>
{
private:
    
    Order fOrderFtn;
    
    void shuffle() noexcept
    {
        FisherAndYatesSorter& Array = *this;
        
        // Fisher & Yates shuffling
        size_t n = this->size();

        while ( n > 1 )
        {
            // new random index in the range 0 to n
            size_t k = rand() % n;
            n--;                                    // n last pertinent index

            this->swap( Array[n], Array[k] );
        }
    }
    
    bool isSorted() noexcept
    {
        FisherAndYatesSorter& Array = *this;

        for ( size_t i = 1; i < this->size(); i++ )
        {
            if ( !fOrderFtn( Array[i-1], Array[i] ) )
            {
                return false;
            }
        }
        
        return true;
    }
    
public:
    
    FisherAndYatesSorter( const T aArray[] = nullptr, size_t aSize = 0 ) noexcept :
        ArraySorter<T>(aArray, aSize),
        fOrderFtn()
    {
        srand( (unsigned int)time( NULL ) );
    }

    void sort( bool aDoLog = false, std::ostream& aOStream = std::cout ) noexcept override
    {
        ArraySorter<T>::sort();

        while (true)
        {
            if ( aDoLog )
            {
                aOStream << *this << std::endl;
            }

            if ( isSorted() )
            {
                break;
            }
            
            shuffle();
        }
    }
};
