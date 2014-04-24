/****************************************************************
 * 'UnionFind' class.
 *
 * This class file implements the Union-Find algorithm. It tests 
 * arcs for uniqueness and adds to the vector container if it is 
 * unique. Once added, builds the forest of nodes and makes node its
 * own parent and adds node to the list. Function then finds if node
 * is its own parent and if so, sets as root, otherwise it recurses up 
 * the tree. Union-Find algorithm is then run and cycles are detected 
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
 * Function to add arcs by calling isArcUnique and testing. If 
 * isArcUnique returns true then function is added to the vector. 
 * If the arc is not unique, it is ignored implicitly.
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
}


/****************************************************************
 * Boolean function to test if an Arc is unique. If the Arc is not 
 * unique then it returns false. If the Arc is unique, it returns true.
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
}


/****************************************************************
 * Function builds a set of all integer ids present in the input data, 
 * then builds a map<int, Node> with one node per unique id. Each 
 * Node instance is its own parent. This is how the initial forest 
 * of nodes is constructed.
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
}


/****************************************************************
 * Function finds if the current node is at the root of the tree.
 * If the node's id is found to match its parent, the node is a root 
 * and the function returns the current node. If not, the function 
 * recurses up the tree to find the root and then returns the parent 
 * and all previous arcs.
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
}


/****************************************************************
 * Function for adding an Arc to the forest of Nodes. It finds
 * the root of each node's tree and compares these roots' ids.
 *
 * If rootA and rootB are the same then there is a cycle. We dump
 * the path of root A and root B and also dump the bad arc.
 *
 * If rootA and rootB are different, then it is safe to add the 
 * arc.
 *
 * Returns:
 *   none
**/
void UnionFind::addArcToForest(Arc arcToAdd)
{
    //These variables allow us to track where we've been so that 
    //dumping cycles is easier later. We reset these each time we 
    //add a new arc to the forest.
    this->pathA.clear();
    this->pathB.clear();

    //Find the root of each node's tree.
    Node rootA = find(arcToAdd.a, this->pathA);
    Node rootB = find(arcToAdd.b, this->pathB);
  
    //Iterators for printing the paths out later. (In the event 
    //of a cycle).
    std::vector<Arc>::iterator it_pathA;
    std::vector<Arc>::iterator it_pathB;

    //If the two roots match, we have a cycle!
    if(rootA.id == rootB.id)
    {
        this->output     += "CYCLE DETECTED!\n";
        Utils::logStream << "CYCLE DETECTED!" << endl;

        //Dump cycle path A.
        this->output     += "A: ";
        Utils::logStream << "A: ";

        for(it_pathA =  this->pathA.begin();
            it_pathA != this->pathA.end();
            it_pathA++)
        {
            this->output     += it_pathA->toString();
            Utils::logStream << *it_pathA;
        }

        this->output     += "\n";
        Utils::logStream << "\n";

        //Dump cycle path B.
        this->output     += "B: ";
        Utils::logStream << "B: ";

        for(it_pathB =  this->pathB.begin();
            it_pathB != this->pathB.end();
            it_pathB++)
        {
            this->output     += it_pathB->toString();
            Utils::logStream << *it_pathB;
        }

        this->output     += "\n";
        Utils::logStream << "\n";

        
        this->output     += "Bad Arc: "  + arcToAdd.toString()  + "\n";
        Utils::logStream << "Bad Arc: " << arcToAdd.toString() << "\n";
    }
    //Otherwise, the roots differ, and it is safe to reparent Node b.
    else
    {
        this->nodes[arcToAdd.b].parent = arcToAdd.a;
    }
}


/****************************************************************
 * Function runs the union-find algorithm across all input arcs.
 *
 * Returns:
 *   none
**/
void UnionFind::unionFind()
{
    std::vector<Arc>::iterator it;

    //For each arc in the input, try to add it to the forest.
    for(it = this->arcs.begin(); it != this->arcs.end(); it++)
    {
        this->addArcToForest(*it);
    }
}


/****************************************************************
 * Function for returning a string representation of a UnionFind 
 * instance.
 *
 * Returns:
 *   string representation of the UnionFind.
**/
string UnionFind::toString()
{
    return output;
}

