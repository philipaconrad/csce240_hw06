GPP = g++ -O3 -Wall

UTILS = ../Utilities

M = Main.o
UF = UnionFind.o
Arc = Arc.o
S = Scanner.o
U = Utils.o
N = Node.o
O = Operators.o

union-find: $(M) $(UF) $(Arc) $(S) $(U) $(N) $(O)
	$(GPP) -o union-find $(M) $(UF) $(Arc) $(S) $(U) $(N) $(O)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c -DEBUG Main.cpp


#The Extra-Credit code can be enabled by swapping which line 
#below is commented out.
UnionFind.o: UnionFind.h UnionFind.cpp
	#$(GPP) -o UnionFind.o -c -DEXTRA_CREDIT UnionFind.cpp
	$(GPP) -o UnionFind.o -c UnionFind.cpp


Arc.o: Arc.h Arc.cpp
	$(GPP) -o Arc.o -c Arc.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(UTILS)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

Node.o: Node.h Node.cpp
	$(GPP) -o Node.o -c Node.cpp

Operators.o: Operators.cpp
	$(GPP) -o Operators.o -c Operators.cpp

clean:
	rm union-find
	rm *.o

