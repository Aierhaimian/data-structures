#include <iostream>
#include <vector>
#include "min_heap.h"

using namespace std;

#define MAX_V 1000

struct Edge{
    int sid; // 边的起始顶点编号
    int tid; // 边的终止顶点编号
    int weight; // 权重
    Edge() = default;
    Edge(int s, int t, int w)
        :sid(s), tid(t), weight(w) {}
};

class Vertex{
public:
    int id; // 顶点编号 ID
    int dist; // 从起始顶点到这个顶点的距离
    Vertex() = default;
    Vertex(int idV, int distV)
        :id(idV), dist(distV) {}

    bool operator==(const Vertex &rhs)
    {
        return this->id == rhs.id && this->dist == rhs.dist;
    }

    bool operator<(const Vertex &rhs)
    {
        return this->dist < rhs.dist;
    }

    bool operator>(const Vertex &rhs)
    {
        return this->dist > rhs.dist;
    }
};

class Graph{
public:
    Graph() = default; // 构造函数
    Graph(int val)
        :v(val)
    {
        adj = vector<vector<Edge>>(v, vector<Edge>(MAX_V, Edge(0,0,0)));
        predecessor = vector<int>(v, 0);
    }

    void addEdge(int s, int t, int w)
    {
        Edge edges(s, t, w);
        adj[s].push_back(edges);
    }

    void dijkstra(int s, int t)
    {
        vector<Vertex> vertexes = vector<Vertex>(v);
        for (int i=0; i<v; ++i)
        {
            vertexes[i].id = i;
            vertexes[i].dist = INT_MAX;
        }
        MinHeap<Vertex> priq;
        vector<bool> inq = vector<bool>(v, false);

        vertexes[s].dist = 0;
        priq.push(vertexes[s]);
        inq[s] = true;
        while(!priq.empty())
        {
            Vertex minVertex = priq.top();
            priq.pop();

            if (minVertex.id == t)
                break; // 最短路径产生了

            for (int i=0; i<adj[minVertex.id].size(); ++i)
            {
                Edge e = adj[minVertex.id][i]; // 取出一条minVertex相连的边
                Vertex nextVertex = vertexes[e.tid]; // minVertex->nextVertex

                if (minVertex.dist + e.weight < nextVertex.dist)
                {
                    nextVertex.dist = minVertex.dist + e.weight;
                    predecessor[nextVertex.id] = minVertex.id;
                    if (inq[nextVertex.id] == true)
                    {
                        priq.update(nextVertex); // 更新队列中的dist值
                    }
                    else
                    {
                        priq.push(nextVertex);
                        inq[nextVertex.id] = true;
                    }
                }
            }
        }
    }

    void print(int s, int t)
    {
        if (s == t)
            return;
        print(s, predecessor[t]);
        cout << "->" << t;
    }
private:
    int v; // 顶点个数
    vector<vector<Edge>> adj; // 邻接表
    vector<int> predecessor;
};

int main()
{
    Graph g(5);

    g.addEdge(1,2,4);
    g.addEdge(1,3,1);
    g.addEdge(3,2,1);
    g.addEdge(3,4,5);
    g.addEdge(2,4,3);
    g.addEdge(2,5,1);
    g.addEdge(4,5,2);

    g.dijkstra(1,5);

    cout << 1;
    g.print(1,5);
    cout << endl;

    return 0;
}

