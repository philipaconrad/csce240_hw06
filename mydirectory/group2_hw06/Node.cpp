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

void Node::getID()
{
  return this->parent;
}
