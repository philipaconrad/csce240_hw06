GPP = g++ -O3 -Wall

UTILS = ../../Utilities

M = Main.o
UF = UnionFind.o
Arc = Arc.o
S = Scanner.o
U = Utils.o
N = Node.o

Aprog: $(M) $(UF) $(Arc) $(S) $(U) $(N)
	$(GPP) -o Aprog $(M) $(UF) $(Arc) $(S) $(U) $(N)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c -DEBUG Main.cpp

UnionFind.o: UnionFind.h UnionFind.cpp
	$(GPP) -o UnionFind.o -c UnionFind.cpp

Arc.o: Arc.h Arc.cpp
	$(GPP) -o Arc.o -c Arc.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(UTILS)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

Node.o: Node.h Node.cpp
	$(GPP) -o Node.o -c Node.cpp

clean:
	rm Aprog
	clean
