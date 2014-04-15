/****************************************************************
 * Header for the 'Node' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Used by: Allen Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/
#ifndef X_H
#define X_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

class Node
{
public:

/****************************************************************
 * Constructors and destructors for the class. 
**/
  Node(int ID);
  virtual ~Node();

/****************************************************************
 * General functions.
**/
  int getID();
  
/****************************************************************
 * General private variables.
**/
private:
  int parent;
};

#endif // X_H
