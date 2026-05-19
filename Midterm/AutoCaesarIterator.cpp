#include "AutoCaesarIterator.h"

#include <cctype>
//fCollection is a pointer to the underlying collection
AutoCaesarIterator::AutoCaesarIterator( const char aInit[KEY_LENGTH],
                                        const std::string* aCollection ) noexcept :
    fCollection( aCollection ),
    fInit( aInit ),
    fKeys( aInit ),
    fIndex( 0 )
{
}

AutoCaesarIterator::value_type AutoCaesarIterator::operator*() const noexcept
{
    //solution given in pseudo code
    if ( fCollection == nullptr )
    {
        return '\0';
    }

    value_type copy = (*fCollection)[fIndex];

    if ( std::isalpha(copy) != 0 )
    {
        const bool lIsLower = (std::islower(copy) != 0);

        copy = std::toupper(copy);
        copy = copy + *fKeys;

        if ( copy > 'Z' )
        {
            copy = copy - 26;
        }

        if ( lIsLower )
        {
            copy = std::tolower(copy);
        }
    }

    return copy;
}

AutoCaesarIterator::iterator& AutoCaesarIterator::operator++() noexcept
{
    if ( fCollection != nullptr )
    {
        char lCurrent = (*fCollection)[fIndex];

        if ( std::isalpha(lCurrent) != 0 )
        {
            fKeys += lCurrent;
            ++fKeys;
        }

        ++fIndex;
    }
    return *this;
}

AutoCaesarIterator::iterator AutoCaesarIterator::operator++( int ) noexcept
{
    iterator temp = *this;
    ++(*this);
    return temp;
}

bool AutoCaesarIterator::operator==( const iterator& aOther ) const noexcept
{
    return fCollection == aOther.fCollection && fIndex == aOther.fIndex;
}

AutoCaesarIterator::iterator AutoCaesarIterator::begin() const noexcept
{
    iterator copy = *this;
    copy.fIndex = 0;
    // KeyIterator<KEY_LENGTH>(fInit)
    copy.fKeys = KeyIterator<KEY_LENGTH>( fInit );
    return copy;

}

AutoCaesarIterator::iterator AutoCaesarIterator::end() const noexcept
{
    iterator copy = *this;
    if (fCollection != nullptr)
    {
        copy.fIndex = fCollection->size();
    }
    return copy;
}