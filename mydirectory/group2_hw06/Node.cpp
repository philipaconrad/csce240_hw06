/****************************************************************
 *'Node' class.
 * Creates Node object with int values and returns string of Node.
 
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Edited by: Allan Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/
#include "Node.h"

/****************************************************************
 * Constructor.
**/
Node::Node()
{
    this->id = 0;
    this->parent = 0;
}

Node::Node(int ID)
{
    this->id = ID;
    this->parent = ID;
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
