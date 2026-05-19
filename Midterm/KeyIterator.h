
// COS30008 - Midterm 2026

#pragma once

#include <cctype>

//template class, implementation in the header file
// used to get the key after the initial key
template<size_t N>
class KeyIterator
{
public:
    
    using difference_type = std::ptrdiff_t;
    using value_type = size_t;
    using iterator = KeyIterator;

    KeyIterator( const char aInit[N] ) noexcept;
    
    size_t operator*() const noexcept;
    
    iterator& operator++() noexcept;
    iterator operator++(int) noexcept;

    iterator& operator+=( char aKey ) noexcept;
    
private:
    
    value_type fKeys[N+1]; //offsets
    size_t fIndex;
    size_t fUpdateIndex;
};

template<size_t N>
KeyIterator<N>::KeyIterator( const char aInit[N] ) noexcept :
    fIndex( 0 ),
    fUpdateIndex( 0 )
{
    for ( size_t i = 0; i < N; ++i )
    {
        //convert each char to upper
        char upperLetter = std::toupper(aInit[i]);
        int numberOfLetter = upperLetter - 'A';
        fKeys[i] = numberOfLetter;
    }

    fUpdateIndex = N;
}

template<size_t N>
size_t KeyIterator<N>::operator*() const noexcept
{
    //The dereference operator returns the element that the iterator is currently positioned on???
    return fKeys[fIndex];
}

template<size_t N>
typename KeyIterator<N>::iterator& KeyIterator<N>::operator++() noexcept
{
    //prefix increment not postfix
    ++fIndex;

    //goes beyond bound
    if ( fIndex >= (N+1) )
    {
        fIndex = 0;
    }

    return *this;
}

template<size_t N>
typename KeyIterator<N>::iterator KeyIterator<N>::operator++( int ) noexcept
{
    // similar to FibonacciSequence temp = *this
	iterator temp = *this;
	++(*this);
	return temp;
}

template<size_t N>
typename KeyIterator<N>::iterator& KeyIterator<N>::operator+=( char aKey ) noexcept
{
    fKeys[fUpdateIndex] = std::toupper(aKey) - 'A';
    ++fUpdateIndex;

    if ( fUpdateIndex >= (N+1) ) // or just > n??
    {
        fUpdateIndex = 0;
    }

    return *this;
}
