/****************************************************************
* 'UnionFind' class.
*
* Author/copyright: Duncan Buell
* Date: 24 April 2014
* Used by: Allan Bates, Phillip Conrad, Janice Neighbor,
* William Warren
**/

#include "UnionFind.h"

static const string TAG = "UnionFind: ";
static const string BUILD = "BUILD TREE BY ADDING ARC";
static const string FOUND = "FOUND CYCLE IN ADDING ARC";
static const string ONE = "PATH ONE ";
static const string TWO = "PATH TWO ";

/****************************************************************
* Constructor.
**/
UnionFind::UnionFind()
{
}


/****************************************************************
* Destructor.
**/
UnionFind::~UnionFind()
{
}


/****************************************************************
* Function add links and do voodoo magic.
*
* Returns:
* none
**/
void UnionFind::addArc(const int a, const int b)
{
    std::vector<Arc>::iterator it;
    Arc arcToAdd = Arc(a, b);

    if( this->isArcUnique(arcToAdd) ) {
        this->arcs.push_back(arcToAdd);
        cout << toStringPath(arcs, arcToAdd);
    }

    //Implicit else:
    //Ignore the Arc if it's not unique.
}


bool UnionFind::isArcUnique(const Arc arcToAdd)
{
    std::vector<Arc>::iterator it;

    for(it = this->arcs.begin(); it != this->arcs.end(); it++)
    {
        //Duplicate detected! This arc is NOT unique.
        if( (arcToAdd.a == it->a) && (arcToAdd.b == it->b) )
        {
            return false;
        }
    }

    //Otherwise, no duplicates detected, so this Arc is unique.
    return true;
}


//Function for building the initial forest of Nodes.
void UnionFind::buildForest(const vector<Arc>& nodes)
{
    std::vector<Arc>::iterator it_arc;
    std::set<int>::iterator it_ids;
    Node nodeToAdd = Node(0); //May need to add a default initializer later to clean this up.

    //For each Arc, add that Arc's 'a' and 'b' members to the set of Node ids.
    for(it_arc = this->arcs.begin(); it_arc != this->arcs.end(); it_arc++)
    {
        this->ids.insert(it_arc->a); //Add 1st id in the Arc.
        this->ids.insert(it_arc->b); //Add 2nd id in the Arc.
    }

    //For each id in the set of node ids, build a Node and add it to the
    //list of Nodes.
    for(it_ids = this->ids.begin(); it_ids != this->ids.end(); it_ids++)
    {
        //Create a Node with the current ID, and make it its own parent.
        nodeToAdd = Node(*it_ids);
        nodeToAdd.parent = *it_ids;

        //Add the Node to the forest (the list of Nodes).
        this->nodes.push_back(nodeToAdd);
    }
}

/****************************************************************
* Function for returning a 'toString' of the data in the class.
* Here we return vector of the zork whatever.
* Returns:
* string of ZORK data.
**/
string UnionFind::toStringPath(vector<Arc> path, Arc last)
{
  string s = "";
  
  s += TAG;
  s += BUILD;
  s += last.toString();
  s += "\n";

  s += TAG;
  s += "\n";

  for(vector<Arc>::iterator it = path.end(); it != path.begin(); --it)
  {
    s += (*it).toString();
  }
  cout << s << endl;
  return s;
}

/****************************************************************
* Function for returning a 'toString' of the data in the class.
* Here we return vector of the zork whatever.
* Returns:
* string data.
**/
/**string UnionFind::toString()
{
  string s = "";
  return s;
}**/
