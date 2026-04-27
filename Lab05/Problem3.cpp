
#include "DataWrapper.h"

#include <iostream>
#include <cassert>

void Problem3( const DataWrapper& aWrapper )
{
    std::cout << "Sorting the data: " << std::endl;

    aWrapper.apply( [&aWrapper](size_t i){
        
            bool lFound = false;
            size_t j = 0;
        
            for ( ; j < aWrapper.size(); j++ )
            {
                if ( aWrapper[j].key() == i )
                {
                    lFound = true;
                    break;
                }
            }
        
            assert( lFound );
        
            std::cout << static_cast<char>(aWrapper[j]);
        } );

    std::cout << std::endl;
}
