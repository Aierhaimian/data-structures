#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稠密图-邻接矩阵
class DenseGraph{
private:
    int v, e;               // 顶点数和边数
    bool directed;          // 是否为有向图
    vector<vector<bool> > adj; // 邻接矩阵

public:
    // 构造函数
    DenseGraph() = default;
    DenseGraph(int n, bool directed)
        :v(n), directed(directed)
    {
        assert(v >= 0);
        this->e = 0; // 初始化时无任何边
        // g初始化为n*n的布尔矩阵，每一个g[i][j]均为false，表示没有任何边
        adj = vector<vector<bool> >(v, vector<bool>(n, false));
    }
    // 析构函数
    ~DenseGraph(){}
    
    int getV(){ return v; } // 返回节点个数
    int getE(){ return e; } // 返回边的个数

    // 向图中添加一个边
    void addEdge(int s, int t)
    {
        assert(s >= 0 && s < v);
        assert(t >= 0 && t < v);

        if (hasEdge(s, t))
            return;

        adj[s][t] = true;

        if (!directed)
            adj[t][s] = true;

        e ++;
    }

    // 验证图中是否有从s到t的边
    bool hasEdge(int s, int t)
    {
        assert(s >= 0 && s < v);
        assert(t >= 0 && t < v);

        return adj[s][t];
    }

    // 显示图的信息
    void show()
    {
        for (int i=0; i < v; i++ ){
            for (int j=0; j < v; j++)
                cout << adj[i][j] << "\t";
            cout << endl;
        }
    }

    // 邻边迭代器，传入一个图和一个顶点，
    // 迭代在这个图中和这个顶点相连的所有顶点
    class adjIterator{
    private:
        DenseGraph &G; // 图的引用
        int v;
        int index;

    public:
        // 构造函数
        adjIterator(DenseGraph &graph, int v)
            :G(graph), v(v)
        {
            assert(v >= 0 && v < G.v);
            this->index = -1; // 索引从-1开始，因为每次遍历都需要调用一次nex()
        }

        // 析构函数
        ~adjIterator(){}

        // 返回图G中与顶点v相连接的第一个顶点
        int begin()
        {
            // 索引从-1开始，因为每次遍历都需要调用一次next()
            index = -1;
            return next();
        }

        // 返回图G中与顶点v相连的下一个顶点
        int next()
        {
            // 从当前index开始向后搜索，直到找到一个g[v][index]为true
            for (index += 1; index < G.v; index++)
            {
                if (G.adj[v][index])
                    return index;
            }
            // 若没有顶点和v相连，则返回-1
            return -1;
        }

        // 查看是否已经迭代完成了图G中与顶点v相连的所有顶点
        bool end()
        {
            return index >= G.getV();
        }
    };
};

#endif //GRAPH_DENSEGRAPH_H
