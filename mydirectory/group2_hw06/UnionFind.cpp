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
* Function that finds the holy grail.
*
* Returns:
* root
**/
/*Arc UnionFind::find(int zz)
{
Arc root;
vector<Arc> nodePath;
root = this->find(zz, nodePath);
return root;
}*/


/****************************************************************
* Function that finds root and places in vector.
* Returns:
* root
**/
/*Arc UnionFind::find(int zz, vector<Arc>& nodePath)
{
Arc root;

root = nodes[zz];
nodePath.push_back(root);
if(root.getX() != root.getY())
{
while(root.getX() != root.getY())
{
root = nodes[root.getY()];
nodePath.push_back(root);
}
}

return root;
}*/


/****************************************************************
* Function that returns string data of UnionFind.
*
* Returns:
* string value.
**/
/*string UnionFind::frabjous(int which, int whatever)
{
string s = "";
Arc thisValue, rootOfSmaller;
vector<Arc> pathSmaller, pathLarger;
rootOfSmaller = this->find(which, pathSmaller);
thisValue = this->find(whatever, pathLarger);
vector<Arc>::iterator itSmaller = pathSmaller.end();
vector<Arc>::iterator itLarger = pathLarger.end();
--itSmaller;
--itLarger;
while( (*itSmaller).equals( (*itLarger) ))
{
--itSmaller;
--itLarger;
}
Arc topOfSmaller = *itSmaller;
Arc topOfLarger = *itLarger;
Arc tempNode;
tempNode.setX(whatever);
tempNode.setY(which);
Utils::logStream << TAG << "PATH ONE " << tempNode.toString()
<< this->toStringZORK(pathSmaller, *itSmaller) << endl;
Utils::logStream.flush();
Utils::logStream << TAG << "PATH TWO " << this->toStringZORK(pathLarger, *itLarger)
<< endl << endl;
Utils::logStream.flush();
return s;
}*/


/****************************************************************
* Function for returning a 'toString' of the data in the class.
* Here we return vector of the zork whatever.
* Returns:
* string of ZORK data.
**/
/*string UnionFind::toString()
{
string s = "";
map<int, Arc>::iterator it;
for(it = this->nodes.begin(); it != this->nodes.end(); ++it)
{
vector<Arc> path;
int usu = it->first;
Arc node = this->find(usu, path);
s += this->toStringZORK(path, node) + "\n";
}
return s;
}*/


/****************************************************************
* Function for returning a 'toString' of the data in the class.
* Here we return vector of the zork whatever.
* Returns:
* string of ZORK data.
**/
/*string UnionFind::toStringZORK(vector<Arc> path, Arc last)
{
string s = "";
for(vector<Arc>::iterator it = path.end(); it != path.begin(); --it)
{
s += (*it).toString();
if((*it).equals(last)) break;
}
return s;
}*/
