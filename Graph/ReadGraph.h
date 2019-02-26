#ifndef GRAPH_READGRAPH_H
#define GRAPH_READGRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

// 从文件中读取图的算法
template <typename Graph>
class ReadGraph
{
public:
    ReadGraph(Graph &graph, const string &filename) 
    {
        ifstream file(filename);
        string line;
        int v, e;

        assert(file.is_open());

        // 第一行读取图中的节点个数和边的个数
        assert(getline(file, line));
        stringstream ss(line);
        ss >> v >> e;

        assert( v == graph.getV() );

        // 读取每一条边的信息
        for (int i = 0; i < e; i ++)
        {
            assert(getline(file, line));
            stringstream ss(line);

            int a,b;
            ss >> a >> b;
            assert(a >= 0 && a < v);
            assert(b >= 0 && b < v);
            graph.addEdge(a, b);
        }
    }
};

#endif // GRAPH_READGRAPH_H
