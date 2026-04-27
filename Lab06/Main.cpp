
// COS30008, Tutorial 6, 2026

#include <iostream>

#include "DataWrapper.h"

#define P1
#define P2
#define P3

#ifdef P1

#include "SimpleForwardIterator.h"

void testP1( const DataWrapper& aWrapper )
{
    std::cout << "Test empty iterator:" << std::endl;

    SimpleForwardIterator iter1 = SimpleForwardIterator().begin();

    while ( iter1 != iter1.end() )
    {
        std::cout << static_cast<char>(*iter1);
        
        iter1++;
    }

    std::cout << std::endl;

    std::cout << "Test iterator for aWrapper:" << std::endl;

    SimpleForwardIterator iter2 = SimpleForwardIterator( &aWrapper ).begin();

    while ( iter2 != iter2.end() )
    {
        std::cout << static_cast<char>(*iter2);
        
        iter2++;
    }

    std::cout << std::endl;
}

#endif

#ifdef P2

#include "OrderingForwardIterator.h"

void testP2( const DataWrapper& aWrapper )
{
    std::cout << "Test empty iterator:" << std::endl;

    OrderingForwardIterator iter1 = OrderingForwardIterator().begin();

    while ( iter1 != iter1.end() )
    {
        std::cout << static_cast<char>(*iter1);
        
        iter1++;
    }

    std::cout << std::endl;

    std::cout << "Test iterator for aWrapper:" << std::endl;

    OrderingForwardIterator iter2 = OrderingForwardIterator( &aWrapper ).begin();

    while ( iter2 != iter2.end() )
    {
        std::cout << static_cast<char>(*iter2);
        
        iter2++;
    }

    std::cout << std::endl;
}

#endif

#ifdef P3

#include "OrderingForwardIterator.h"

void testP3( const DataWrapper& aWrapper, auto& aOrdering )
{
    std::cout << "Test empty iterator:" << std::endl;

    OrderingForwardIterator iter1 = OrderingForwardIterator().begin();

    while ( iter1 != iter1.end() )
    {
        std::cout << static_cast<char>(*iter1);
        
        iter1++;
    }

    std::cout << std::endl;

    std::cout << "Test iterator for aWrapper:" << std::endl;

    OrderingForwardIterator iter2 = OrderingForwardIterator( &aWrapper, aOrdering ).begin();

    while ( iter2 != iter2.end() )
    {
        std::cout << static_cast<char>(*iter2);
        
        iter2++;
    }

    std::cout << std::endl;
}

#endif

int main( int argc, char* argv[] )
{
    if ( argc != 2 )
    {
        std::cerr << "Arguments missing." << std::endl;
        std::cerr << "Usage: Lab06 <filename>" << std::endl;
        
        return 1;
    }
    
    DataWrapper lWrapper;
    
    if ( !lWrapper.load( argv[1] ) )
    {
        std::cerr << "Cannot load data file " << argv[1] << std::endl;
        
        return 2;
    }
    
    std::cout << "Data loaded." << std::endl;
    
#ifdef P1
    
    testP1( lWrapper );
    
#endif
    
#ifdef P2
        
    testP2( lWrapper );
    
#endif
    
#ifdef P3
    
    auto lOrdering = [] ( const DataWrapper& aWrapper,
                          size_t aIndex )  -> const DataMap&
                        {
                            size_t i = 0;

                            for ( ; i < aWrapper.size(); i++ )
                            {
                                if ( aWrapper[i].key() == aIndex )
                                {
                                    break;
                                }
                            }
                                
                            return aWrapper[i];
                        };
        
    testP3( lWrapper, lOrdering );
    
#endif
    
    return 0;
}
