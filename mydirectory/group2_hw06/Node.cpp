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
Node::Node()
{
    this->x = DUMMYX;
    this->y = DUMMYY;
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
    return this->id;
}

void Node::setID(int newId)
{
   this->id = newId;
}

void Node::setEdges()
{
}

string toStringEdges()
{
 string s = "";
    for(int i = 0; i < this->edges.length; i++)
    {
        s += edges[i];
        s += ", ";
    }

 return s;
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
