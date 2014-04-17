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

    void buildForest(const vector<Arc>& nodes);

    void dumpTrees();

    //Arc find(int startNodeID);
    //Arc find(int startNodeID, vector<Arc>& nodePath); //Not needed yet.

    string toString();


private:
/****************************************************************
* Private functions.
**/
    vector<Arc> arcs;
    set<int> ids;
    vector<Node> nodes;

    //string frabjous(int Arc, int yy);
    //string toStringZORK(vector<Arc> path, Arc last);
};

#endif // UNIONFIND_H
