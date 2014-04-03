#include "UnionFind.h"

static const string TAG = "UnionFind: ";

UnionFind::UnionFind()
{
}

UnionFind::~UnionFind()
{
}

void UnionFind::addLink(int a, int b)
{
int whatever;
int which;

Arc thisValue;
Arc rootOfSmaller;

if(a <= b)
{
which = a;
whatever = b;
}
else
{
which = b;
whatever = a;
}
Arc whichNode = nodes[which];
if(whichNode.getX() == DUMMYX)
{
nodes[which].setX(which);
nodes[which].setY(which);
}
Arc someNode = nodes[whatever];
if(someNode.getX() == DUMMYX)
{
nodes[whatever].setX(whatever);
nodes[whatever].setY(whatever);
}
rootOfSmaller = this->find(which);
thisValue = this->find(whatever);
if(rootOfSmaller.equals(thisValue))
{
Arc tempNode;
tempNode.setX(whatever);
tempNode.setY(which);
Utils::logStream << tempNode.toString() << endl;
Utils::logStream << this->frabjous(which, whatever) << endl;
Utils::logStream.flush();
}
else
{
Arc tempNode;
tempNode.setX(whatever);
tempNode.setY(which);
Utils::logStream << tempNode.toString() << endl;
Utils::logStream.flush();
nodes[whatever].setY(which);
}
Utils::logStream << TAG << endl;
Utils::logStream << this->toString();
Utils::logStream.flush();
}
Arc UnionFind::find(int zz)
{
Arc root;
vector<Arc> nodePath;
root = this->find(zz, nodePath);
return root;
}
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
