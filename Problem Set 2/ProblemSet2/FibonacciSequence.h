
// COS30008, Problem Set 2, 2026

#pragma once

#include <string>
#include <cstdint>
#include <concepts>

constexpr uint64_t MAX_FIBONACCI = 93;              // experimental limit

class FibonacciSequence
{
private:
 
    uint64_t fPrevious;                             // previous Fibonacci number (initially 0)
    uint64_t fCurrent;                              // current Fibonacci number (initially 1)

public:
    
    using iterator = FibonacciSequence;
    using difference_type = std::ptrdiff_t;         // to satisfy concept weakly_incrementable
    using value_type = uint64_t;                    // to satisfy concept indirectly_readable

    FibonacciSequence() noexcept;

    // Retrieve the current Fibonacci number
    const uint64_t& operator*() const noexcept;

    FibonacciSequence& operator++() noexcept;       // prefix, next Fibonacci number
    FibonacciSequence operator++(int) noexcept;     // postfix (extra unused argument)

    bool operator==( const FibonacciSequence& aOther ) const noexcept;

    // Position iterator at start
    void begin() noexcept;

    // Position iterator at no limit
    void end() noexcept;
};

// static type guarantees, requires C++20

template<typename T>
concept FibonacciIterator =
std::forward_iterator<T> &&                     // a basic forward iterator is a forward iterator
requires( T i )
{
    { i.begin() } -> std::same_as<void>;        // iterator provides suitable begin()
    { i.end() } -> std::same_as<void>;          // iterator provides suitable end()
};

static_assert(FibonacciIterator<FibonacciSequence>);
