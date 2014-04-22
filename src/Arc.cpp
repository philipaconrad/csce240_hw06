/****************************************************************
 * 'Arc' class implementation.
 * Creates Arc object with int values, returns string representation
 * of Arc data.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Edited by: Allan Bates, Phillip Conrad, Janice Neighbor, 
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
