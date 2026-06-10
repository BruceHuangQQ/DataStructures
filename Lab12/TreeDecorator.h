
// COS30008, Tutorial 12, 2026

#pragma once

#include "Visitors.h"

template<typename T>
class TreeDecorator : public TreeVisitor<T>
{
public:

    void emitEmpty() const noexcept override
    {
        std::cout << " {}";
    }

    // override pre-order behavior
    void preVisit( const T& aKey ) const noexcept override
    {
        std::cout << " { ";
        std::cout << aKey;
    }

    // override post-order behavior
    void postVisit( const T& aKey ) const noexcept override
    {
        std::cout << " }";
    }
};

