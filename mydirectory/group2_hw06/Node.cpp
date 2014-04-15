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
    this->parent = ID;
}

/****************************************************************
 * Destructor.
**/
Node::~Node()
{
    
}
/****************************************************************
 * Accessor function for value of x
 *
 * Returns:
 *   int value of x.
**/
int Node::getID()
{
    return this->parent;
}

