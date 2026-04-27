
// COS30008, Tutorial 5, 2026

#include <iostream>
#include <cassert>
#include <type_traits>

#define P0
#define P1
#define P2
#define P3

#ifdef P0

template<typename T>
const T& max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template<typename T, typename U>
std::common_type_t<T, U> max(const T& a, const U& b)
{
    // The compiler uses this function when T and U are different types. It is the best match.
    // A conversion to std::common_type<T,U> requires a temporary.
    // The temporary contains the type-converted value of a or b.
    // However, we cannot return references to temporaries.
    // Hence, the maximum must be copied as value to the caller.
    return a > b ? a : b;
}

struct AStruct
{
    int a;
    float b;
    
    bool operator>( const AStruct& aOther ) const noexcept
    {
        return a > aOther.a && b > aOther.b;
    }
};

std::ostream& operator<<( std::ostream& aOStream, const AStruct& aObj )
{
    return aOStream << '{' << aObj.a << ", " << aObj.b << '}';
}

static void testP0()
{
    int lValue1 = max( 20, 30 );
    float lValue2 = max( 200.0f, 300.0f );
    double lValue3 = max<double>( 200.0f, 300.0 );
    auto lValue4 = max( 200.0f, 300.0 );

    std::cout << "Value of max( 20, 30 ): " << lValue1 << std::endl;
    std::cout << "Value of max( 200.0f, 300.0f ): " << lValue2 << std::endl;
    std::cout << "Value of max<double>( 200.0f, 300.0 ): " << lValue3 << std::endl;
    std::cout << "Value of max( 200.0f, 300.0 ): " << lValue4 << std::endl;

    std::cout << typeid(lValue4).name() << std::endl;
    
    AStruct lStruct1 = { 10, 56.0f };
    AStruct lStruct2 = { 10, 57.0f };
    AStruct lStruct3 = { 12, 56.0f };
    
    const AStruct& lRefValue1 = max( lStruct1, lStruct2 );
    const AStruct& lRefValue2 = max( lStruct1, lStruct3 );
    const AStruct& lRefValue3 = max( lStruct2, lStruct3 );
    
    std::cout << "Value of max( lStruct1, lStruct2 ): " << lRefValue1 << std::endl;
    std::cout << "Value of max( lStruct1, lStruct3 ): " << lRefValue2 << std::endl;
    std::cout << "Value of max( lStruct2, lStruct3 ): " << lRefValue3 << std::endl;
}

#endif

#ifdef P1

#include <sstream>
#include "Map.h"

static void testP1()
{
    using DataMap = Map<int,int>;
    int lData[] = { 1, 32, 2, 68, 3, 83, 4, 80,
                    5, 87, 6, 69, 7, 75, 8, 53 };
    constexpr size_t lDataSize = sizeof(lData)/sizeof(int);
    constexpr size_t lSize1 = lDataSize / 2;
    DataMap lArray1[lSize1]{};
    int lArray2[] { 1, 2, 3, 0, 4, 5, 5, 6, 0, 7};
    constexpr size_t lSize2 = sizeof(lArray2)/sizeof(int);

    std::stringstream ss;
    for ( size_t i = 0; i < lDataSize; i++ )
    {
        ss << ' ' << lData[i];
    }

    // Test input

    for ( size_t i = 0; i < lSize1; i++ )
    {
        ss >> lArray1[i];
    }

    // Test output
    
    for ( size_t i = 0; i < lSize1; i++ )
    {
        std::cout << "Key-value pair " << i << ": " << lArray1[i] << std::endl;
    }

    std::cout << "Test type conversion: ";
    
    for ( size_t i = 0; i < lSize2; i++ )
    {
        std::cout << static_cast<char>(lArray1[lArray2[i]]);
    }

    std::cout << std::endl;
}

#endif

#if defined(P2) || defined(P3)

#include "DataWrapper.h"

static bool loadData( DataWrapper& aWrapper, const std::string& aFileName )
{
    if ( !aWrapper.load( aFileName ) )
    {
        std::cerr << "Cannot load data file " << aFileName << std::endl;
        
        return false;
    }
    
    std::cout << "Data loaded." << std::endl;
    
    return true;
}

#endif

#ifdef P2

static void testP2( const DataWrapper& aWrapper )
{
    std::cout << "Accessing data sequentially: " << std::endl;
    
    aWrapper.apply( [&aWrapper](size_t i) { std::cout << static_cast<char>(aWrapper[i]); } );

    std::cout << std::endl;
}

#endif

#ifdef P3

extern void Problem3( const DataWrapper& aWrapper );

void testP3( const DataWrapper& aWrapper )
{
    Problem3( aWrapper );
}

#endif

int main( int argc, char* argv[] )
{
#ifdef P0
 
    testP0();

#endif

#ifdef P1
 
    testP1();

#endif
    
#if defined(P2) || defined(P3)
    
    if ( argc != 2 )
    {
        std::cerr << "Arguments missing." << std::endl;
        std::cerr << "Usage: Lab04 <filename>" << std::endl;
        
        return 1;
    }
    
    DataWrapper lWrapper;
    
    if ( loadData( lWrapper, argv[1] ) )
    {
#ifdef P2
        testP2( lWrapper );

#endif
        
#ifdef P3
        
        testP3( lWrapper );

#endif
        
        return 0;
    }

    return 2;
    
#else
    
    return 0;
    
#endif
}
