
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Function to print the shortest path from source to destination
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf("%d -> ", j);
}

// Function to print the distance array
void printSolution(int dist[], int parent[], int src)
{
    printf("Vertex\t\tDistance\tPath");
    for (int i = 0; i < V; i++) {
        printf("\n%d -> %d\t\t%d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}

// Function to calculate the average time from source to all other cities
double calculateAverageTime(int dist[], int src)
{
    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (i != src && dist[i] != INT_MAX) {
            sum += dist[i];
            count++;
        }
    }

    return sum / count;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // Array to store the shortest distance from source to each vertex
    int visited[V]; // Array to keep track of visited vertices
    int parent[V]; // Array to store the shortest path tree

    // Initialize all distances as infinite and visited array as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    parent[src] = -1; // Source vertex has no parent

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1; // Mark the selected vertex as visited

        // Update the distance value of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the distance array and shortest paths
    printSolution(dist, parent, src);

    // Calculate and print the average time
    double averageTime = calculateAverageTime(dist, src);
    printf("\n\nAverage time from city %d to all other cities: %.2f\n", src, averageTime);
}

int main()
{
    int graph[V][V] = { { 0, 10, 0, 0, 15, 5 },
                        { 10, 0, 10, 30, 0, 0 },
                        { 0, 10, 0, 12, 5, 0 },
                        { 0, 30, 12, 0, 0, 20 },
                        { 15, 0, 5, 0, 0, 0 },
                        { 5, 0, 0, 20, 0, 0 } };

    int source = 5; // Set the source vertex

    dijkstra(graph, source); // Run Dijkstra's algorithm

    return 0;
}

