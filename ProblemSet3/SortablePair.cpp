#include "SortablePair.h"

// Explicit specialization of operator<<
std::ostream& operator<<(std::ostream& aOStream, const SortablePair<size_t, int>& aPair)
{
    aOStream << "(" << aPair.fFirst << "," << aPair.fSecond << ")";
    return aOStream;
}