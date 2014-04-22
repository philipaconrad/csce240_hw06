/****************************************************************
 * Header for the 'Arc' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Used by: Allan Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/

#ifndef ARC_H
#define ARC_H

#include "../Utilities/Utils.h"
#include "../Utilities/Scanner.h"


class Arc
{

public:
/****************************************************************
 * Constructors and destructors. 
**/
    Arc(int a, int b);
    virtual ~Arc();


/****************************************************************
 * General functions.
**/
    string toString();

    friend ostream& operator <<(ostream& outputStream, Arc& arc);

/****************************************************************
 * Public variables.
**/
    int a;
    int b;

};

#endif // X_H
