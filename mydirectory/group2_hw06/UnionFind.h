/****************************************************************
 * Header for the 'UnionFind' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Used by: Allan Bates, Phillip Conrad, Janice Neighbor, 
 * William Warren
**/// Do-the-work class.

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <map>
#include <vector>
#include <tuple>

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

#include "Arc.h"
#include "Node.h"
class UnionFind
{

public:

/****************************************************************
 * Constructors and destructors for the class. 
**/
  UnionFind();
  virtual ~UnionFind();

/****************************************************************
 * General functions.
**/
  void addLink(int a, int b);
  void dumpTrees();
  Arc find(int thatX);
  Arc find(int thatX, vector<Arc>& nodePath);
  Arc find(map<int, Node> theNodes, int nodeID);
  Arc union(map<int, Node> theNodes, tuple<int, int> edges);
  string toString();
/****************************************************************
 * Private functions.
**/
private:
  vector<std::pair<int, int> > links;
  map<int, Arc> nodes;

  string frabjous(int Arc, int yy);
  string toStringZORK(vector<Arc> path, Arc last);
};

#endif // UNIONFIND_H
