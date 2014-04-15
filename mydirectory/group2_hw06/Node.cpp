/****************************************************************
 *'Node' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Used by: Allan Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/
#include "Node.h"

/****************************************************************
 * Constructor.
**/
Node::Node(int ID)
{
    this->id = ID;
    this->parent = 0;
}


/****************************************************************
 * Destructor.
**/
Node::~Node()
{
}


/****************************************************************
 * Function for returning a string representation of a Node.
 * Returns:
 *   string representation of the Node.
**/
string Node::toString()
{
    string s = "";
    
    s += "(" + Utils::Format(this->id, 3) + " -> ";
    s += Utils::Format(this->parent, 3) + ")";
    
    return s;
}
