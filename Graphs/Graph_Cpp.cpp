#include <iostream>
using namespace std;
#include <vector>
#include <list>
class Graph
{
public:
    int v;
    vector<list<int>> adj;
    Graph(int v)
    {
        this->v = v;
        adj.resize(v);
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void printAdjList()
    {
        for (int d = 0; d < v; ++d)
        {
            cout << "\n Vertex " << d << ":";
            for (auto x : adj[d])
                cout << "-> " << x;
            printf("\n");
        }
    }
    // void BFS(int s)
    // {
    //     bool *visited = new bool[v];
    //     for (int i = 0; i < v; i++)
    //     {
    //         visited[i] = false;
    //     }
    //     list<int> q;
    //     visited[s] = true;
    //     list<int>::iterator it = adj[s].begin();
    //     while (!q.empty())
    //     {
    //         s = q.front();
    //         cout << s << " ";
    //         q.pop_front();
    //         for (; it != adj[s].end(); it++)
    //         {
    //             if (!visited[*it])
    //             {
    //                 visited[*it] = true;
    //                 q.push_back(*it);
    //             }
    //         }
    //     }
    // }
    void DFSTraversal(int v)
    {
        bool *visited = new bool[v];
        for (int i = 0; i < v; i++)
            visited[i] = false;
        DFS(v, visited);
    }

    void DFS(int v, bool *visited)
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator it = adj[v].begin();
        for (; it != adj[v].end(); it++)
        {
            if (!visited[*it])
                DFS(*it, visited);
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    // g.printAdjList();
    g.DFSTraversal(1);

    return 0;
}