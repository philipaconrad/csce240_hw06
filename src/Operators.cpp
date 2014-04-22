#include "Arc.h"

ostream& operator <<(ostream& outputStream, Arc& arc)
{
    outputStream << arc.toString();
    return outputStream;
}

