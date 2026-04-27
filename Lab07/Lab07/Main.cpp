
// COS30008, Tutorial 6, 2026

#include <iostream>

#define P1
#define P2
#define P3

#if defined(P1)

#include "ArraySorter.h"

#endif

#if defined(P2)

#include "BubbleSorter.h"

#endif

#if defined(P3)

#include "FisherAndYatesSorter.h"

#endif

int main()
{
    int lArray[] = { 34, 2, 890, 40, 16, 218, 20, 49, 10, 29 };
    size_t lSize = sizeof(lArray) / sizeof(int);

#if defined(P1)
    
    ArraySorter<int> lSorter1( lArray, lSize );

    std::cout << "Testing ArraySorter." << std::endl;
    std::cout << "The array before sorting:" << std::endl;
    std::cout << lSorter1 << std::endl;
    
    lSorter1.sort();

    std::cout << "Number of swaps: " << lSorter1.swapCount() << std::endl;

    std::cout << "The array after sorting:" << std::endl;
    std::cout << lSorter1 << std::endl;
    
#endif

#if defined(P2)
    
    BubbleSorter<int> lSorter2( lArray, lSize );

    std::cout << "Testing BubbleSorter." << std::endl;
    std::cout << "The array before sorting:" << std::endl;
    std::cout << lSorter2 << std::endl;
    
    lSorter2.sort();

    std::cout << "Number of swaps: " << lSorter2.swapCount() << std::endl;

    std::cout << "The array after sorting:" << std::endl;
    std::cout << lSorter2 << std::endl;
    
#endif

#if defined(P3)
    
    FisherAndYatesSorter<int> lSorter3( lArray, lSize );

    std::cout << "Testing FisherAndYatesSorter." << std::endl;
    std::cout << "The array before sorting:" << std::endl;
    std::cout << lSorter3 << std::endl;
    
    lSorter3.sort();

    std::cout << "Number of swaps: " << lSorter3.swapCount() << std::endl;
    
    std::cout << "The array after sorting:" << std::endl;
    std::cout << lSorter3 << std::endl;
    
#endif

    return 0;
}
