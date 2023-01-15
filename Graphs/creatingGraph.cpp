#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>

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