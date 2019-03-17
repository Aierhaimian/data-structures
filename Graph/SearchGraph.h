#ifndef GRAPH_SEARCHGRAPH_H
#define GRAPH_SEARCHGRAPH_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

template <typename Graph>
class SearchGraph
{
public:
    // 构造函数
    SearchGraph(Graph &graph, int s, int t)
        :G(graph), s(s), t(t)
    {
        assert(s >= 0 && s < G.getV());
        assert(t >= 0 && t < G.getV());

        visited = new bool[G.getV()];
        prevPath = new int[G.getV()];
        for (int i = 0; i < G.getV(); i++)
        {
            visited[i] = false;
            prevPath[i] = -1;
        }
        found = false;
    }

    // 析构函数
    ~SearchGraph() 
    {
        delete [] visited;
        delete [] prevPath;
    }

    void bfs()
    {
        if (s == t) 
            return;
        queue<int> q;
        q.push(s);
        visited[s] = true;
        
        while(q.empty() != true)
        {
            int w = q.front();
            q.pop();

            typename Graph::adjIterator adj(G, w);
            for (int i = adj.begin(); !adj.end(); i = adj.next())
            {
                if (!visited[i])
                {
                    prevPath[i] = w;
                    if (i == t)
                    {
                        bfsPrint();
                        return;
                    }
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void dfs()
    {
        found = false;
        recurDfs(s);
        dfsPrint();
    }

    void recurDfs(int u)
    {
        if (found == true) return;
        visited[u] = true;
        if (u == t)
        {
            found = true;
            return;
        }

        typename Graph::adjIterator adj(G, u);
        for (int i = adj.begin(); !adj.end(); i = adj.next())
        {
            if (!visited[i])
            {
                prevPath[i] = u;
                recurDfs(i);
            }
        }
    }

    void bfsPrint()
    {
        cout << "BFS: ";
        print(s, t);
        cout << endl;
    }

    void dfsPrint()
    {
        cout << "DFS: ";
        print(s, t);
        cout << endl;
    }

    void print(int a, int b)
    {
        if (prevPath[b] != -1 && b != a)
            print(a, prevPath[b]);
        cout << b << "  ";
    }

private:
    Graph &G;       // 图的引用
    int s;          // 起始点
    int t;          // 终止点
    bool *visited;  // 记录搜索过程中节点是否已被访问
    int  *prevPath; // 记录s到t的路径
    bool found;     // dfs中找到t提前结束
};

#endif // GRAPH_SEARCHGRAPH_H
