#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;
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

    void DFSTraversal(int n)
    {
        vector<bool> visited;
        visited.resize(v, false);
        DFS(n, visited);
    }

    void DFS(int v, vector<bool> &visited)
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

    void BFSTraversal(int s)
    {
        vector<bool> visited;
        visited.resize(v, false);
        visited[s] = true;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            s = q.front();
            cout << s << " ";
            q.pop();
            for (auto adjacent : adj[s])
            {
                if (!visited[adjacent])
                {
                    visited[adjacent] = true;
                    q.push(adjacent);
                }
            }
        }
    }

    void topoSort(int i, vector<bool> &visited, stack<int> &s)
    {
        visited[i] = true;
        list<int>::iterator it = adj[i].begin();
        for (auto x : adj[i])
        {
            if (!visited[x])
                topoSort(x, visited, s);
        }
        s.push(i);
    }
    void topologicalSort()
    {
        stack<int> st;
        vector<bool> visited;
        visited.resize(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                topoSort(i, visited, st);
        }
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }

    void shortestPath(int src, int dst)
    {
        vector<bool> visited;
        visited.resize(v, false);
        vector<int> parent(v); // parent vector
        for (int i = 0; i < v; ++i)
        {
            parent[i] = i; // initialising the parent to node itself
        }
        parent[src] = -1;
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto i : adj[front])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }

        int current = src;
        while (current != dst)
        {
            current = parent[current];
            cout << current << " ";
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 6);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(5, 6);
    g.addEdge(5, 3);
    g.addEdge(5, 2);
    // g.printAdjList();
    // g.BFSTraversal(1);
    // g.topologicalSort();
    g.shortestPath(0, 5);

    return 0;
}