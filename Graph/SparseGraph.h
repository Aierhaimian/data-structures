#ifndef GRAPH_SPARSEGRAPH_H_H
#define GRAPH_SPARSEGRAPH_H_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稀疏图-邻接表
class SparseGraph{
private:
    int v, e;               // 顶点数和边数
    bool directed;          // 是否为有向图
    vector<vector<int> > adj;    // 邻接表

public:
    // 构造函数
    SparseGraph() = default;
    SparseGraph(int n, bool directed)
        :v(n), directed(directed)
    {
        assert(v >= 0);
        this->e = 0; // 初始化时无任何边
        // adj初始化为n个空的邻接表，表示每个adj[i]为空，表示没有任何边
        adj = vector<vector<int> >(v, vector<int>()); 
    }
    // 析构函数
    ~SparseGraph(){};

    int getV(){ return v; } // 返回节点个数
    int getE(){ return e; } // 返回边的个数

    // 向图中添加一个边
    void addEdge(int s, int t)
    {
        assert(s >= 0 && s < v);
        assert(t >= 0 && t < v);

        adj[s].push_back(t);

        if (s != t && !directed)
            adj[t].push_back(s);

        e ++;
    }

    // 验证图中是否有从s到t的边
    bool hasEdge(int s, int t)
    {
        assert(s >= 0 && s < v);
        assert(t >= 0 && t < v);

        for (size_t i = 0; i < adj[s].size(); i++)
        {
            if (adj[s][i] == t)
                return true;
        }
        return false;
    }

    // 显示图的信息
    void show()
    {
        for (int i=0; i < v; i++)
        {
            cout << "vertex " << i << ":\t";
            for (size_t j=0; j < adj[i].size(); j++)
                cout << adj[i][j] << "\t";
            cout << endl;
        }
    }

    // 邻边迭代器，传入一个图和一个顶点，
    // 迭代在这个图中和这个顶点相连的所有顶点
    class adjIterator{
    private:
        SparseGraph &S; // 图的引用
        int v;
        size_t index;

    public:
       // 构造函数
       adjIterator(SparseGraph &graph, int v)
           :S(graph), v(v)
       {
           assert(v >= 0 && v < S.v);
           this->index = 0;
       }

       // 析构函数
       ~adjIterator(){};

       // 返回图S中与顶点v相连的第一个顶点
       int begin()
       {
           index = 0;
           if (S.adj[v].size())
               return S.adj[v][index];

           return -1;
       }
       
       // 返回图S中与顶点v相连的下一个顶点
       int next()
       {
           index ++;
           if (index < S.adj[v].size())
               return S.adj[v][index];

           return -1;
       }

       // 查看是否已经迭代完了图S中与顶点v相连接的所有顶点
       bool end()
       {
           return index >= S.adj[v].size();
       }
    };
};

#endif // GRAPH_SPARSEGRAPH_H_H
