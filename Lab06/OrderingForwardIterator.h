
// COS30008, Tutorial 6, 2026

#pragma once

#include <concepts>
#include <functional>

#include "DataWrapper.h"

class OrderingForwardIterator
{
public:

    using Sorter = std::function<const DataMap&(const DataWrapper&, size_t)>;
    
    // C++20 iterator type properties
    using iterator = OrderingForwardIterator;
    using difference_type = std::ptrdiff_t;
    using value_type = DataMap;
    
    // Iterator must be default initializable
    OrderingForwardIterator( const DataWrapper* aCollection = nullptr,
                             Sorter aOrdering = [] ( const DataWrapper& aCollection,
                                                     size_t aIndex ) -> const DataMap&
                                    {
                                        return aCollection[aIndex];
                                    } ) noexcept;

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

private:
    
    const DataWrapper* fCollection;
    Sorter fOrdering;
    size_t fIndex;
};

static_assert(std::forward_iterator<OrderingForwardIterator>);
