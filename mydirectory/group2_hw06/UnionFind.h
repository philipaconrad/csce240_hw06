/****************************************************************
* Header for the 'UnionFind' class.
*
* Author/copyright: Duncan Buell
* Date: 24 April 2014
* Used by: Allan Bates, Phillip Conrad, Janice Neighbor,
* William Warren
**/

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <map>
#include <vector>
#include <set>
#include <iostream>
#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "Arc.h"
#include "Node.h"

class UnionFind
{

public:
/****************************************************************
* Constructors and destructors.
**/
    UnionFind();
    virtual ~UnionFind();


/****************************************************************
* General functions.
**/
    void addArc(const int a, const int b);
    bool isArcUnique(const Arc arcToAdd);

    void buildForest();

    void dumpTrees();

    Node find(int currentNodeID, vector<Arc>& prevArcs);
    void addArcToForest(Arc arcToAdd);
    void unionFind();

    string toString();
    //Arc find(int startNodeID);
    //Arc find(int startNodeID, vector<Arc>& nodePath); //Not needed yet.

   // friend ostream& operator <<(ostream& outputStream, const Arc& arc);

    string output;


private:
/****************************************************************
* Private variables.
**/
    vector<Arc> arcs;
    set<int> ids;

    map<int, Node> nodes;
    vector<Arc> pathA; 
    vector<Arc> pathB;
    //string frabjous(int Arc, int yy);
    
};

#endif // UNIONFIND_H
