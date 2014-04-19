/****************************************************************
 * 'UnionFind' class.
 * This class file implements the union find algorithm. It tests 
 * arcs for uniqueness and adds to the vector container if it is 
 * unique. Once added, builds the forest of nodes and makes node its
 * own parent and adds node to the list. Function then finds if node
 * is its own parent and if so, sets as root, otherwise it recurses up 
 * the tree. UnionFind algorithm is then run and cycles are detected 
 * across all inputs.
 *
 * Author/copyright:  Duncan Buell
 * Date: 24 April 2014
 * Edited by: Allan Bates, Phillip Conrad, Janice Neighbor, 
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
 * Function add arcs by calling isArcUnique and testing. If 
 * isArcUnique returns true then function is added to the vector. 
 * if arc is not unique due to implicit else, it is ignored.
 *
 * Returns:
 *   none
**/
void UnionFind::addArc(const int a, const int b)
{
    std::vector<Arc>::iterator it;
    Arc arcToAdd = Arc(a, b);

    if( this->isArcUnique(arcToAdd) ) {
        this->arcs.push_back(arcToAdd);
    }
}//void UnionFind::addArc(const int a, const int b)


/****************************************************************
 * Boolean function to test if an arc is unique. If arc is not 
 * unique then returns false. If arc is unique returns true.
 *
 * Returns:
 *   boolean
**/
bool UnionFind::isArcUnique(const Arc arcToAdd)
{
    std::vector<Arc>::iterator it;

    for(it = this->arcs.begin(); it != this->arcs.end(); it++)
    {
        if( (arcToAdd.a == it->a) && (arcToAdd.b == it->b) )
        {
            return false;
        }
    }

    return true;
}//bool UnionFind::isArcUnique(const Arc arcToAdd)


/****************************************************************
 * Function declares iterator over vector and set containers.
 * Adds arcs a and b members to the set of node ids by iterating 
 * through the vector and inserting. Also iterates over set and 
 * creates a node with the current node, setting as own parent. 
 * Adds node to the list of nodes, or forest.
 *
 * Returns:
 *   none
**/
void UnionFind::buildForest()
{
    std::vector<Arc>::iterator it_arc;
    std::set<int>::iterator it_ids;
    int curID;
    Node nodeToAdd;

    for(it_arc = this->arcs.begin(); it_arc != this->arcs.end(); it_arc++)
    {
        this->ids.insert(it_arc->a); //Add 1st id in the Arc.
        this->ids.insert(it_arc->b); //Add 2nd id in the Arc.
    }

    
    for(it_ids = this->ids.begin(); it_ids != this->ids.end(); it_ids++)
    {
        //Create a Node with the current ID, and make it its own parent.
        curID = *it_ids;

        nodeToAdd = Node(curID);

        //Add the Node to the forest (the list of Nodes).
        this->nodes[curID] = nodeToAdd;
    }
}//void UnionFind::buildForest()


/****************************************************************
 * Function finds if the current node is at the root of the tree.
 * If node id is found to match the parent, node is set as root and 
 * returns current node. If not, function recurses up the tree to 
 * find root and then returns the parent and all previous arcs.
 *
 * Returns:
 *   Node
**/
Node UnionFind::find(int currentNodeID, vector<Arc>& prevArcs)
{
    Node currentNode = this->nodes[currentNodeID];

    
    if(currentNode.parent == currentNodeID)
    {
        prevArcs.push_back(Arc(currentNodeID, currentNode.parent));
        return currentNode;
    }
    
    else
    {
        prevArcs.push_back(Arc(currentNodeID, currentNode.parent));
        return find(currentNode.parent, prevArcs);
    }
}//Node UnionFind::find(int currentNodeID, vector<Arc>& prevArcs)


/****************************************************************
 * Function resets vectors in order to store paths in them. Finds
 * the root of each node's owning tree and initializes iterator.
 * If rootA and rootB are the same then there is a cycle. Dumps
 * the cycle path of root A and B and also dumps the bad arcs path.
 * If no cycle path is detected, the roots are different and thus 
 * no cycle is found and deemed safe to add arc.
 *
 * Returns:
 *   none
**/
void UnionFind::addArcToForest(Arc arcToAdd)
{
    
    this->pathA.clear();
    this->pathB.clear();

    
    Node rootA = find(arcToAdd.a, this->pathA);
    Node rootB = find(arcToAdd.b, this->pathB);
  
    Node temp;
    std::vector<Arc>::iterator it_pathA;
    std::vector<Arc>::iterator it_pathB;

   
    if(rootA.id == rootB.id)
    {
        cout << "CYCLE DETECTED!\n";

        //Dump cycle path A.
        cout << "  A: ";
        for(it_pathA =  this->pathA.begin();
            it_pathA != this->pathA.end();
            it_pathA++)
        {
            cout << it_pathA->toString();
        }

        cout << "\n";

        //Dump cycle path B.
        cout << "  B: ";
        for(it_pathB =  this->pathB.begin();
            it_pathB != this->pathB.end();
            it_pathB++)
        {
            cout << it_pathB->toString();
        }

        cout << "\n";

        
        cout << "  Bad Arc: " << arcToAdd.toString() << "\n";
    }
    
    else
    {
        this->nodes[arcToAdd.b].parent = arcToAdd.a;
    }
}//void UnionFind::addArcToForest(Arc arcToAdd)


/****************************************************************
 * Function runs the union-find algorithm across all input arcs.
 *
 * Returns:
 *   none
**/
void UnionFind::unionFind()
{
    std::vector<Arc>::iterator it;

    for(it = this->arcs.begin(); it != this->arcs.end(); it++)
    {
        this->addArcToForest(*it);
    }
}//void UnionFind::unionFind()

