/****************************************************************
 * 'Arc' class implementation.
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
Arc::Arc(int a, int b)
{
    this->a = a;
    this->b = b;
}


/****************************************************************
 * Destructor.
**/
Arc::~Arc()
{
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
    if((this->a == that.a()) && (this->b == that.b()))
    {
        return true;
    }

    return false;
}


/****************************************************************
 * Function for returning a string representation of an Arc.
 * Returns:
 *   string of Arc data.
**/
string Arc::toString()
{
    string s = "";
    
    s += "(" + Utils::Format(this->a, 3) + " -> ";
    s += Utils::Format(this->b, 3) + ")";
    
    return s;
}
