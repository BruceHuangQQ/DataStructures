
// COS30008, Tutorial 6, 2026

#pragma once

#include <concepts>

#include "DataWrapper.h"

class SimpleForwardIterator
{
private:
    const DataWrapper* fCollection;
    size_t fIndex;

public:

    // C++20 iterator type properties
    using iterator = SimpleForwardIterator;
    using difference_type = std::ptrdiff_t;
    using value_type = DataMap;
    
    // Iterator must be default initializable
    SimpleForwardIterator( const DataWrapper* aCollection = nullptr ) noexcept;
    
    // Iterator must be const
    const value_type& operator*() const noexcept;
    
    iterator& operator++() noexcept;       // prefix
    iterator operator++(int) noexcept;     // postfix

    // Iterator must implement operator==. The operation != is synthesized.
    bool operator==( const iterator& aOther ) const noexcept;
    bool operator!=( const iterator& aOther ) const noexcept;
    
    // Auxiliary methods not part of std::forward_iterator.
    iterator begin() const noexcept;
    iterator end() const noexcept;
};

static_assert(std::forward_iterator<SimpleForwardIterator>);
