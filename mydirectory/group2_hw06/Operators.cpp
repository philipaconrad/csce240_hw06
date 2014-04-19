#include "Arc.h"
#include "UnionFind.h"

ostream& operator <<(ostream& outputStream, const Arc& arc)
{
    outputStream << arc.toString();
    return outputStream;
}

