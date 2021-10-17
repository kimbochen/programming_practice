#include "graph.cpp"

void BFS(const Graph& graph, int src)
{
    queue<int> queue_;
    vector<bool> discovered(graph.N, false);
    vector<Edge> SSSP;

    discovered[src] = true;
    queue_.emplace(src);

    while (!queue_.empty())
    {
        int u = queue_.front();
        queue_.pop();

        for (const int& v : graph.adjList[u])
        {
            if (!discovered[v])
            {
                discovered[v] = true;
                queue_.emplace(v);
                SSSP.emplace_back(u, v);
            }
        }
    }

    for (const Edge& edge : SSSP) cout << edge << '\n';
}

int main(void)
{
    vector<Edge> edges = {
        {1, 2}, {1, 5}, {2, 6}, {3, 4}, {3, 6},
        {3, 7}, {4, 8}, {6, 7}, {7, 8}
    };
    Graph graph(edges, 9);
    int src = 2;

    BFS(graph, src);

    return 0;
}
