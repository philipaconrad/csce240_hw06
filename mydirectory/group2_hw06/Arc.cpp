#include "Arc.h"

static const string TAG = "ZORK: ";

Arc::Arc()
{
    this->x = DUMMYX;
    this->y = DUMMYY;
}

Arc::~Arc()
{
    
}

int Arc::getX()
{
    return this->x;
}

int Arc::getY()
{
    return this->y;
}

void Arc::setX(int value)
{
    this->x = value;
}

void Arc::setY(int value)
{
    this->y = value;
}

bool Arc::equals(Arc that)
{
    if((this->x == that.getX()) && (this->y == that.getY()))
    {
        return true;
    }

    return false;
}

bool Arc::z()
{
    return (this->x = this->y);
}

string Arc::toString()
{
    string s = "";
    
    s += "(" + Utils::Format(this->getX(), 3) + " -> ";
    s += Utils::Format(this->getY(), 3) + ")";
    
    return s;
}