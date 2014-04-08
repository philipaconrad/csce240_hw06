#  union-find.py -- Algorithm for CSCE240 Final Project.
#  Copyright (c) Philip Conrad 2014 -- MIT License


#Example dataset taken from Buell's PDF.
arcList = [
    (7, 5),
    (5, 3),
    (3, 1),
    (1, 1),
    
    (4, 2),
    (2, 2),

    (8, 8)
]


#Class used to model the nodes of the graph.
class Node:
    def __init__(self, ID):
        self.id = ID
        self.ein  = []
        self.eout = []
    
    def __repr__(self):
        out = "\nArc("+str(self.id)+")\n"
        out += " - in:  "
        out += str(self.ein)+"\n"
        out += " - out: "
        out += str(self.eout)
        return out


#Constructs the initial list of Nodes.
#  build([(int, int)]:arcs) -> [Node]
def build(arcs):
    out = []
    ids = set()
    #extract all IDs:
    for arc in arcs:
        ids.add(arc[0])
        ids.add(arc[1])
    #build Arcs:
    for nodeid in ids:
        out.append(Node(nodeid))
    #build connection graph:
    for arc in arcs:
        for node in out:
            if arc[0] == node.id:
                node.eout.append(arc[1])
            elif arc[1] == node.id:
                node.ein.append(arc[0])
    return out
        

#Chases down to the root of the tree a node is in.
#  find([Node], int:id) -> int
def find(nodes, ID):
    #find our desired node:
    for node in nodes:
        if node.id == ID:
            #found the root!
            if node.id in node.eout:
                return node.id
            else:
                #print "recursing "+str(node.id)+" going to "+str(node.eout[0])
                return find(nodes, node.eout[0])


#Used to dump cycles to output.
#  verbose_find([Node], int:id) -> str
def verbose_find(nodes, ID):
    #find our desired node:
    for node in nodes:
        if node.id == ID:
            #found the root!
            if node.id in node.eout:
                return str((node.id, node.id))
            else:
                out = ""
                out += str((node.id, node.eout[0])) #arc from here to next node
                out += verbose_find(nodes, node.eout[0]) #future arcs
                return out


def union(nodes, arc):
    rootA = find(nodes, arc[0])
    rootB = find(nodes, arc[1])
    if rootA != rootB:
        print "Detected cycle when trying to add "+str(arc)
        print "Cycle (a, b) is:"
        print " - From a: " + verbose_find(nodes, arc[0])
        print " - From b: " + verbose_find(nodes, arc[1])
    else:
        print "Can safely add Arc "+str(arc)+" to the tree."
        #recreate set of node ids (in case a new node appeared).
        ids = set()
        for node in nodes:
            ids.add(node.id)

        #This stuff is super-ugly, and probably subtly-wrong. Needs a major cleanup.

        if arc[0] not in ids:
            newNode = Node(arc[0])
            newNode.eout.append(arc[1]) #add outbound edge
            nodes.append(newNode)
        elif arc[0] in ids:
            #grab desired node:
            for node in nodes:
                if node.id == arc[0]:
                    node.eout.append(arc[1]) #add outbound edge

        if arc[1] not in ids:
            newNode = Node(arc[1])
            newNode.ein.append(arc[0]) #add inbound edge
            newNode.eout.append(arc[1]) #add necessary root for self.
            nodes.append(newNode)
        elif arc[1] in ids:
            #grab desired node:
            for node in nodes:
                if node.id == arc[1]:
                    node.ein.append(arc[0]) #add inbound edge
    return nodes



if __name__ == '__main__':
    nodeList = build(arcList)
    
    print "INITIAL DATASET:\n"
    print nodeList
    
    print "\n\n\n"
    
    print "TEST: FIND ROOT OF 7\n"
    print verbose_find(nodeList, 7)

    print "\n\n\n"

    print "TEST: DETECT KNOWN CYCLE\n"
    union(nodeList, (7, 8))
    union(nodeList, (3, 8))

    print "\n\n\n"

    print "TEST: UNION A NON-CYCLIC ARC\n"
    print union(nodeList, (5,5))
