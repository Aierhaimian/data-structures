#include <iostream>
#include <string>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "SearchGraph.h"

using namespace std;


int main()
{
    string filename = "testG3.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout << endl;

    SearchGraph<SparseGraph> s1(g, 0, 6);
    s1.dfs();

    cout << "---------------------------" << endl;

    SearchGraph<SparseGraph> s2(g, 0, 6);
    s2.bfs();

    return 0;
}

