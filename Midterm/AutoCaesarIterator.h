
// COS30008 - Midterm 2026

#pragma once

#include <string>

#include "KeyIterator.h"

class AutoCaesarIterator
{
public:
    
    using difference_type = std::ptrdiff_t;
    using value_type = char;
    using iterator = AutoCaesarIterator;

    static constexpr size_t KEY_LENGTH = 6;
    
    AutoCaesarIterator( const char aInit[KEY_LENGTH],
                        const std::string* aCollection = nullptr ) noexcept;
    
    value_type operator*() const noexcept;
    
    iterator& operator++() noexcept;
    iterator operator++(int) noexcept;

    bool operator==( const iterator& aOther ) const noexcept;
    
    iterator begin() const noexcept;
    iterator end() const noexcept;
    
private:
    
    const std::string* fCollection;
    const char* fInit;
    KeyIterator<KEY_LENGTH> fKeys;
    size_t fIndex;
};
