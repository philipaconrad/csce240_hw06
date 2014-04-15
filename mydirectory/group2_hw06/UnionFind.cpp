/****************************************************************
Header for the 'UnionFind' class.
*
* Author/copyright: Duncan Buell
* Date: 24 April 2014
* Used by: Allen Bates, Phillip Conrad, Janice Neighbor,
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
void UnionFind::addLink(int a, int b)
{
int firstNode;
int secondNode;

Arc thisValue;
Arc rootOfSmaller;

if(a <= b)
{
  secondNode = a;
  firstNode = b;
}

else
{
  secondNode = b;
  firstNode = a;
}

Arc whichNode = nodes[secondNode];

if(whichNode.getX() == DUMMYX)
{
  nodes[secondNode].setX(secondNode);
  nodes[secondNode].setY(secondNode);
}

Arc someNode = nodes[ firstNode];

if(someNode.getX() == DUMMYX)
{
  nodes[firstNode].setX(firstNode);
  nodes[firstNode].setY(firstNode);
}

rootOfSmaller = this->find(secondNode);
thisValue = this->find(firstNode);

if(rootOfSmaller.equals(thisValue))
{
  Arc tempNode;
  tempNode.setX(firstNode);
  tempNode.setY(secondNode);
  Utils::logStream << tempNode.toString() << endl;
  Utils::logStream << this->frabjous(secondNode, firstNode) << endl;
  Utils::logStream.flush();
}

else
{
  Arc tempNode;
  tempNode.setX(firstNode);
  tempNode.setY(secondNode);
  Utils::logStream << tempNode.toString() << endl;
  Utils::logStream.flush();
  nodes[firstNode].setY(secondNode);
}

Utils::logStream << TAG << endl;
Utils::logStream << this->toString();
Utils::logStream.flush();
}
/****************************************************************
* Function that finds the holy grail.
*
* Returns:
* root
**/
Arc UnionFind::find(int zz)
{
Arc root;
map<int, Arc>::iterator iter;
int index;

for(iter = nodes.begin(); iter != nodes.end(); ++iter)
{
    index = (iter->first);
    if(index == zz)
    {
        root = nodes[index];
    }
}

//vector<Arc> nodePath;
//root = this->find(zz, nodePath);
return root;
}
/****************************************************************
* Function that finds root and places in vector.
* Returns:
* root
**/
Arc UnionFind::find(int zz, vector<Arc>& nodePath)
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
}
/****************************************************************
<<<<<<< HEAD
*The find function should return an arc based on id of the nodes 
*
*
**/
Arc UnionFind::find(map<int, Node> theNodes, int Id)
{

}

/*****************************************************************
*The union function should make an arc between nodes depending on
*any relative edges 
*
**/
Arc UnionFind::union(map<int, Node> theNodes, tuple<int, int> edges)
{
}

/****************************************************************
=======
>>>>>>> 0d17097dc4f266e1732e04dd028763e2b7c9fa1c
* Function that returns string data of UnionFind.
*
* Returns:
* string value.
**/
string UnionFind::frabjous(int which, int whatever)
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
Utils::logStream << TAG << "PATH ONE " << tempNode.toString() << this->toStringZORK(pathSmaller, *itSmaller) << endl;
Utils::logStream.flush();
Utils::logStream << TAG << "PATH TWO " << this->toStringZORK(pathLarger, *itLarger) << endl << endl;
Utils::logStream.flush();
return s;
}
/****************************************************************
* Function for returning a 'toString' of the data in the class.
* Here we return vector of the zork whatever.
* Returns:
* string of ZORK data.
**/
string UnionFind::toString()
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
}
/****************************************************************
* Function for returning a 'toString' of the data in the class.
* Here we return vector of the zork whatever.
* Returns:
* string of ZORK data.
**/
string UnionFind::toStringZORK(vector<Arc> path, Arc last)
{
string s = "";
for(vector<Arc>::iterator it = path.end(); it != path.begin(); --it)
{
s += (*it).toString();
if( (*it).equals(last)) break;
}
return s;
}
