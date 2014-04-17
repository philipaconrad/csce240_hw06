/****************************************************************
 * Header for the 'Node' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Used by: Allen Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/
#ifndef NODE_H
#define NODE_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

class Node
{
public:

/****************************************************************
 * Constructors and destructors for the class.
**/
    Node();
    Node(int ID);
    virtual ~Node();


/****************************************************************
 * General functions.
**/
    string toString();

  
/****************************************************************
 * Public variables.
**/
    int id;
    int parent;

};

#endif // NODE_H
