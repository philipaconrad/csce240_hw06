/****************************************************************
 *'Arc' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Used by: Allan Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/
#include "Arc.h"

/****************************************************************
 * Constructor.
**/
Arc::Arc()
{
    this->x = DUMMYX;
    this->y = DUMMYY;
}

Arc::Arc(int a, int b)
{
    this->x = a;
    this->y = b;
}
/****************************************************************
 * Destructor.
**/
Arc::~Arc()
{
    
}
/****************************************************************
 * Accessor function for value of x
 *
 * Returns:
 *   int value of x.
**/
int Arc::getX()
{
    return this->x;
}
/****************************************************************
 * Accessor function for value of y.
 * 
 * Returns:
 *   int value of y.
**/
int Arc::getY()
{
    return this->y;
}
/****************************************************************
 * Function compare Arcs and see if they are equal.
 * If so, returns boolean of true, else returns false.
 *
 * Returns:
 *   none
**/
void Arc::setX(int value)
{
    this->x = value;
}
/****************************************************************
 * Function compare Arcs and see if they are equal.
 * If so, returns boolean of true, else returns false.
 *
 * Returns:
 *   none
**/
void Arc::setY(int value)
{
    this->y = value;
}
/****************************************************************
 * Function compare Arcs and see if they are equal.
 * If so, returns boolean of true, else returns false.
 *
 * Returns:
 *   boolean value
**/
bool Arc::equals(Arc arc)
{
    if((this->x == arc.getX()) && (this->y == arc.getY()))
    {
        return true;
    }

    return false;
}
/****************************************************************
 * Function compare Arcs and see if they are equal.
 * If so, returns boolean of true, else returns false.
 *
 * Returns:
 *   boolean value
**/
bool Arc::z()
{
    return (this->x == this->y);
}
/****************************************************************
 * Function for returning a 'toString' of the data in the class.
 * Here we return the Arc data in string format.
 * Returns:
 *   string of Arc data.
**/
string Arc::toString()
{
    string s = "";
    
    s += "(" + Utils::Format(this->getX(), 3) + " -> ";
    s += Utils::Format(this->getY(), 3) + ")";
    
    return s;
}
