#include "Arc.h"

ostream& operator <<(ostream& outputStream, const Arc& arc)
{
    outputStream << arc.toString();
    return outputStream;
}
