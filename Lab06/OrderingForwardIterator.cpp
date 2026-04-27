
// COS30008, Tutorial 6, 2026

#include "OrderingForwardIterator.h"

OrderingForwardIterator::OrderingForwardIterator( const DataWrapper* aCollection,
                                                  Sorter aOrdering ) noexcept :
    fCollection(aCollection),
    fOrdering(aOrdering),
    fIndex(0)
{}
    
const DataMap& OrderingForwardIterator::operator*() const noexcept
{
    return fOrdering( *fCollection, fIndex );
}
    
OrderingForwardIterator& OrderingForwardIterator::operator++() noexcept
{
    fIndex++;
    
    return *this;
}
    
OrderingForwardIterator OrderingForwardIterator::operator++(int) noexcept
{
    OrderingForwardIterator old = *this;
        
    ++(*this);
        
    return old;
}

bool OrderingForwardIterator::operator==( const OrderingForwardIterator& aOther ) const noexcept
{
    return fCollection == aOther.fCollection && fIndex == aOther.fIndex;
}

bool OrderingForwardIterator::operator!=( const OrderingForwardIterator& aOther ) const noexcept
{
    return !(*this == aOther);
}
    
OrderingForwardIterator OrderingForwardIterator::begin() const noexcept
{
    OrderingForwardIterator copy = *this;
        
    copy.fIndex = 0;
        
    return copy;
}

OrderingForwardIterator OrderingForwardIterator::end() const noexcept
{
    OrderingForwardIterator copy = *this;

    if ( fCollection != nullptr )
    {
        copy.fIndex = fCollection->size();
    }

    return copy;
}
