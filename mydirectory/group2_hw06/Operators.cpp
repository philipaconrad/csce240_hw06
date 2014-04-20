#include "Arc.h"
#include "UnionFind.h"

ostream& operator <<(ostream& outputStream, Arc& arc)
{
    outputStream << arc.toString();
    return outputStream;
}

