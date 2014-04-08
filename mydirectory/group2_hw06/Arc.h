/****************************************************************
 * Header for the 'Arc' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Used by: Allan Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/
#ifndef X_H
#define X_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

#define DUMMYX -1
#define DUMMYY -2

class Arc
{
public:

/****************************************************************
 * Constructors and destructors for the class. 
**/
  Arc();
  virtual ~Arc();

/****************************************************************
 * General functions.
**/
  int getX();
  int getY();
  void setX(int value);
  void setY(int value);

  bool equals(Arc that);
  bool z();

  string toString();
/****************************************************************
 * General private variables.
**/
private:
  int x;
  int y;

};

#endif // X_H
