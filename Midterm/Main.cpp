
// COS30008, Midterm 2026

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

#define P1
#define P2

static size_t gCount = 0;

#if defined (P1)

#include "KeyIterator.h"

void runP1()
{
    gCount++;

    std::cout << "Test AutoKey:" << std::endl;

    constexpr size_t KEY_LENGTH = 6;
    char lInit[KEY_LENGTH] = { 'B', 'e', 'r', 'l', 'i', 'n' };
    std::string lMessage = "Julius Caesar was a Roman general.";
    
    KeyIterator<KEY_LENGTH> lAutoKey( lInit ); //key length is the type?

    std::cout << "\nInitial lAutoKey:";
    
    for ( size_t i = 0; i < KEY_LENGTH; i++ )
    {
        std::cout << ' ' << *lAutoKey++;
    }

    std::cout << "\nlAutoKey after message:";

    for ( size_t i = 0; i < lMessage.size(); i++ )
    {
        if ( std::isalpha( lMessage[i] ) != 0 )
        {
            lAutoKey += std::toupper( lMessage[i] );
            
            std::cout << ' ' << *lAutoKey++;
        }
    }

    std::cout << "\n\nTest AutoKey complete." << std::endl;
}

#endif

#if defined (P2)

#include "KeyIterator.h"
#include "AutoCaesarIterator.h"

void runP2()
{
    gCount++;
    
    std::cout << "Test AutoCaesarIterator:" << std::endl;

    constexpr size_t KEY_LENGTH = 6;
    char lInit[KEY_LENGTH] = { 'B', 'e', 'r', 'l', 'i', 'n' };
    std::string lMessage = "Julius Caesar was a Roman general.";

    KeyIterator<KEY_LENGTH> lAutoKey( lInit );

    std::cout << "\nKeys:   ";

    for ( size_t i = 0; i < KEY_LENGTH; i++ )
    {
        std::cout << ' ' << std::setw(2) << std::setfill(' ') << *lAutoKey++;
    }

    for ( size_t i = 0; i < lMessage.size() - (KEY_LENGTH + 1) ; i++ )
    {
        if ( std::isalpha( lMessage[i] ) != 0 )
        {
            lAutoKey += lMessage[i];
            
            std::cout << ' ' << std::setw(2) << std::setfill(' ') << *lAutoKey++;
        }
    }

    std::cout << "\nLetters:";

    for ( char c : lMessage  )
    {
        if ( std::isalpha( c ) != 0 )
        {
            std::cout << "  " << c;
        }
    }
    
    std::cout << "\n\nClear:   ";
    
    std::cout << lMessage;
    
    std::cout << "\nEncoded: ";
    
    for ( char c : AutoCaesarIterator( lInit, &lMessage ) )
    {
        std::cout << c;
    }
    
    std::cout << "\n\nTest AutoCaesarIterator complete." << std::endl;
}

#endif

int main()
{
#if defined (P1)

    runP1();

#endif
    
#if defined (P2)

    runP2();

#endif

    if (gCount != 0)
    {
        std::cout << gCount << " Test(s) completed." << std::endl;
    }
    else
    {
        std::cout << "No Test enabled." << std::endl;
    }
    
    return 0;
}
