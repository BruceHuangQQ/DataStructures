
// COS30008, Tutorial 6, 2026

#include "ArraySorter.h"

std::ostream& operator<<( std::ostream& aOStream, const ArraySorter<int>& aSorter )
{
    aOStream << '[';
    
    if ( aSorter.size() > 0 )
    {
        aOStream << aSorter[0];
        
        for ( size_t i = 1; i < aSorter.size(); i++ )
        {
            aOStream << ',' << aSorter[i];
        }
    }
    
    return aOStream << ']';
}

