
// COS30008 - Problem Set 3, 2026

#pragma once

#include "SortablePair.h"

#include <optional>
#include <cassert>
#include <algorithm>

template<typename T, typename P>
class PriorityQueue
{
public:
    
    using value_type = SortablePair<P, T>;
    
    PriorityQueue() noexcept;
    
    ~PriorityQueue() noexcept;
    
    PriorityQueue( const PriorityQueue& ) = delete;
    PriorityQueue& operator=( const PriorityQueue& ) = delete;

    size_t count() const noexcept;
    size_t capacity() const noexcept;
    
    std::optional<T> top() const noexcept;
    void push( const T& aValue, const P& aPriority ) noexcept;
    void pop() noexcept;
    
private:
    
    value_type* fElements;
    size_t fHead;
    size_t fTail;
    size_t fCapacity;
    
    void sort() noexcept
    {
        std::sort( &fElements[fHead], &fElements[fTail] );
    }
    
    void resize( size_t aCapacity );
    void ensure_capacity();
    void adjust_capacity();
};

// Constructor
template<typename T, typename P>
PriorityQueue<T, P>::PriorityQueue() noexcept {
    fCapacity = 1;
    fHead = 0;
    fTail = 0;
    fElements = new value_type[fCapacity];
}

// destructor
template<typename T, typename P>
PriorityQueue<T, P>::~PriorityQueue() noexcept {
    delete[] fElements;
}


template<typename T, typename P>
size_t PriorityQueue<T, P>::count() const noexcept {
    return fTail - fHead;
}

template<typename T, typename P>
size_t PriorityQueue<T, P>::capacity() const noexcept {
    return fCapacity;
}

template<typename T, typename P>
std::optional<T> PriorityQueue<T, P>::top() const noexcept {
    if (count() == 0) {
        return std::nullopt;
    }
    return fElements[fHead].second();
}

template<typename T, typename P>
void PriorityQueue<T, P>::resize(size_t aCapacity) {
    value_type* lNewElements = new value_type[aCapacity];

    size_t lCount = count();

    // copy elements from old array to new, offsetting by fHead
    for (size_t i = 0; i < lCount; i++)
    {
        lNewElements[i] = fElements[i + fHead];
    }

    // realign head and tail
    fHead = 0;
    fTail = lCount;

    // swap old array for new
    delete[] fElements;
    fElements = lNewElements;
    fCapacity = aCapacity;
}

// called before push
template<typename T, typename P>
void PriorityQueue<T, P>::ensure_capacity() {
    if (count() == fCapacity) {
        resize(fCapacity * 2);
    }
}

template<typename T, typename P>
void PriorityQueue<T, P>::push(const T& aValue, const P& aPriority) noexcept {
    // make sure there's room
    ensure_capacity();

    // explicitly destroy the object currently at tail position
    fElements[fTail].~value_type();

    // construct new SortablePair in-place at tail, then advance tail
    new (&fElements[fTail++]) value_type(aPriority, aValue);

    // sort to move new element into correct priority position
    sort();
}

template<typename T, typename P>
void PriorityQueue<T, P>::pop() noexcept {
    if (count() > 0) {
        fHead++;
        adjust_capacity();
    }
}

// called after pop
template<typename T, typename P>
void PriorityQueue<T, P>::adjust_capacity() {
    if (fCapacity > 1 && count() == fCapacity / 4) {
        resize(fCapacity / 2);
    }
}