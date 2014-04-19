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
void UnionFind::buildForest()
{
    std::vector<Arc>::iterator it_arc;
    std::set<int>::iterator it_ids;
    int curID;
    Node nodeToAdd; //May need to add a default initializer later to clean this up.

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
        curID = *it_ids;
        nodeToAdd = Node(curID);

        //Add the Node to the forest (the list of Nodes).
        this->nodes[curID] = nodeToAdd;
    }
}

/****************************************************************
* Find function
**/
Node UnionFind::find(int currentNodeID, vector<Arc>& prevArcs)
{
    Node currentNode = this->nodes[currentNodeID];

    //This node is the root of a tree!
    if(currentNode.parent == currentNodeID)
    {
        //DEBUG-KEEP: cout << " base case: " << currentNodeID << "\n";
        prevArcs.push_back(Arc(currentNodeID, currentNode.parent));
        return currentNode;
    }
    //Else, keep recursing up the tree. We'll hit the root sooner or later.
    else
    {
        //DEBUG-KEEP: cout << " recursing from " << currentNodeID << " to " << currentNode.parent << "\n";
        prevArcs.push_back(Arc(currentNodeID, currentNode.parent));
        return find(currentNode.parent, prevArcs);
    }
}

//The actual union-find algorithm:
void UnionFind::addArcToForest(Arc arcToAdd)
{
    //Reset these vectors so we can store the memoized paths in them.
    this->pathA.clear();
    this->pathB.clear();

    //Find the root of each node's owning tree.
    Node rootA = find(arcToAdd.a, this->pathA);
    Node rootB = find(arcToAdd.b, this->pathB);
    //DEBUG-KEEP: cout << rootA.id << " ";
    //DEBUG-KEEP: cout << rootB.id << "\n";

    Node temp;
    std::vector<Arc>::iterator it_pathA;
    std::vector<Arc>::iterator it_pathB;

    //If both roots are the same, we've got a cycle!
    if(rootA.id == rootB.id)
    {
        cout << "CYCLE DETECTED!\n";

        //Dump cycle path A.
        cout << " A: ";
        for(it_pathA = this->pathA.begin();
            it_pathA != this->pathA.end();
            it_pathA++)
        {
            cout << it_pathA->toString() << endl;
        }

        /*for(unsigned int i = 0; i < this->pathA.size(); i++)
        {
            cout << this->pathA[i] << endl;
        }*/
        cout << "\n";

        //Dump cycle path B.
        cout << " B: ";
        for(it_pathB = this->pathB.begin();
            it_pathB != this->pathB.end();
            it_pathB++)
        {
            cout << it_pathB->toString();
        }

        cout << "\n";

        //Dump arc causing cycle.
        
       // cout << " Bad Arc: " << arcToAdd.toString() << "\n";
        cout << " Bad Arc: " << arcToAdd << "\n";
    }
    //The roots differ. It is therefore safe to add this arc.
    else
    {
        this->nodes[arcToAdd.b].parent = arcToAdd.a;
    }
}


//Runs the union-find algorithm across all the input arcs.
void UnionFind::unionFind()
{
    std::vector<Arc>::iterator it;

    for(it = this->arcs.begin(); it != this->arcs.end(); it++)
    {
        //cout << "ADDING PATH!\n";
        this->addArcToForest(*it);
    }
}

/****************************************************************
* Function for returning a 'toString' of the data in the class.
* Here we return vector of the zork whatever.
* Returns:
* string data.
**/
string UnionFind::toString()
{
  string s = "";
  return s;
}
