#include "graph.cpp"

void DFSVisit(int v, const Graph& graph, vector<bool>& discovered, vector<Edge>& DFST)
{
    discovered[v] = true;

    for (const int& u : graph.adjList[v])
    {
        if (!discovered[u])
        {
            DFST.emplace_back(v, u);
            DFSVisit(u, graph, discovered, DFST);
        }
    }
}

void DFS(const Graph& graph)
{
    vector<bool> discovered(graph.N, false);
    vector<Edge> DFST;

    for (int v = 0; v < graph.N; v++)
    {
        if (!discovered[v]) {
            DFSVisit(v, graph, discovered, DFST); 
        }
    }

    for (const Edge& edge : DFST) cout << edge << '\n';
}

int main(void)
{
    vector<Edge> edges = {
        {1, 2}, {1, 5}, {2, 6}, {3, 4}, {3, 6},
        {3, 7}, {4, 8}, {6, 7}, {7, 8}
    };
    Graph graph(edges, 9);

    DFS(graph);

    return 0;
}
