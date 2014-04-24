GPP = g++ -O3 -Wall

UTILS = ../../Utilities
UTILS = ../../Utilities

M = Main.o
F = PathFinder.o
MAT = Matrix.o
O = Operators.o
S = Scanner.o
U = Utils.o


all: build

build:
	$(MAKE) -C src/

package:
	tar -cvf ../targroup2_hw06 ../csce240_hw06
	gzip -f ../targroup2_hw06

clean:
	$(MAKE) -C src/ clean

