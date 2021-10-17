#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::ostream;
using std::queue;
using std::vector;

class Edge
{
public:
    Edge(int src_, int dest_): src(src_), dest(dest_) {}
    Edge(void) {}

    friend ostream& operator<<(ostream& os, const Edge& edge)
    {
        os << '(' << edge.src << ", " << edge.dest << ')';
        return os;
    }

    int src, dest;
};

class Graph
{
public:
    Graph(const vector<Edge>& edges, int N_): N(N_)
    {
        adjList.reserve(N);

        for (const auto& edge : edges) {
            adjList[edge.src].emplace_back(edge.dest);
            adjList[edge.dest].emplace_back(edge.src);
        }
    }

    int N;
    vector<vector<int>> adjList;
};
