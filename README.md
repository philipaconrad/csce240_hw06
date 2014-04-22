csce240_hw6
==========

Homework 6 is designed to demonstrate the Union-Find algorithm.


## The Algorithm

The Union-Find algorithm allows one to generate a list of the cycles in a given graph, which, when unioned together, will give all of the unique cycles present in the graph.

This algorithm has a particularly neat property: context/state of previous cycles doesn't have to be retained in order to find the unique cycles.

At the start, every node is the root of its own tree. This changes once we start adding arcs, however, since each time we add in an arc, we reparent a node.


## Our Implementation

We use a recursive function in our code, `unionFind()`, that is responsible for adding arcs to the graph, and for detecting (and *not* adding) arcs that would generate a cycle.


## Build

To build hw6, just run `make` in the top level directory.

If you want to package this homework for submission to the CSE Dropbox, run `make package`.


## Test

To run hw6 manually, use:

    ./union-find xin1.txt xlog.txt xout.txt

To run hw6 on the provided test data, just run `make test`.


## License

This code, should it ever appear to the public, is released under the [MIT License][1].


   [1]: http://choosealicense.com/licenses/mit/
