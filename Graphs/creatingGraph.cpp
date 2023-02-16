#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool directed)
    {
        adj[u].push_back(v);
        if (directed == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "--> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

void DFSTraversal(Graph<int> *g, int m)
{
    int visited[m] = {0};
    for (int i = 0; i < m; i++)
    {
        if (!visited[i])
            DFS(g, i, m, visited);
    }
}

void DFS(Graph<int> *g, int i, int m, int visited)
{
}

int main(int argc, char const *argv[])
{

    int n = 5;
    int m = 6;
    Graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printAdjList();

    return 0;
}