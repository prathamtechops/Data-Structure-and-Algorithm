#include <iostream>
using namespace std;

class Graph
{
public:
    int vertices;
    int edges;
    bool **arr;
};

Graph *ajdMatrix()
{

    Graph *g = new Graph();
    cout << "Enter the number of vertices: ";
    cin >> g->vertices;
    cout << "Enter the number of edges: ";
    cin >> g->edges;
    for (int i = 0; i < g->vertices; i++)
        for (int j = 0; j < g->vertices; j++)
            g->arr[v][v] = 0;
}
int main(int argc, char const *argv[])
{

    return 0;
}