// C++ program to implement Floyd-Warshall algorithm

#include <iostream>
#include <limits.h>
#include <vector>

#define INF INT_MAX

using namespace std;

// Function to print the solution matrix
void printSolution(const vector<vector<int>> &dist)
{
    int V = dist.size();
    cout << "The following matrix shows the shortest distances"
            " between every pair of vertices:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to implement the Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<vector<int>> dist = graph;

    // Update the solution matrix by considering all vertices
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && (dist[i][k] + dist[k][j] < dist[i][j]))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

int main()
{
    /* Let us create the following weighted graph
           10
      (0)------->(3)
       |         /|\
     5 |          |
       |          | 1
      \|/         |
      (1)------->(2)
           3           */
    vector<vector<int>> graph = {{0, 5, INF, 10}, 
                                {5, 0, 3, INF}, 
                                {INF, 3, 0, 1}, 
                                {10, INF, 1, 0}};

    // Function call to implement Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}
