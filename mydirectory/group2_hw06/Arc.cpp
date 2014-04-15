/****************************************************************
 * 'Arc' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Used by: Allan Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/

#include "Arc.h"

static const string TAG = "ZORK: ";

/****************************************************************
 * Constructor.
**/
Arc::Arc()
{
    this->x = DUMMYX;
    this->y = DUMMYY;
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
 * Mutator function for value of x.
 *
 * Returns:
 *   none
**/
void Arc::setX(int value)
{
    this->x = value;
}
/****************************************************************
 * Mutator function for value of y.
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
bool Arc::equals(Arc that)
{
    if((this->x == that.getX()) && (this->y == that.getY()))
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
    return (this->x = this->y);
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
