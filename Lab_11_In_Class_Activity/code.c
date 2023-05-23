#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 9999

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void prim()
{
    int selected[MAX_VERTICES];
    int i, j, numEdges;
    int minWeight, source, destination;
    int totalWeight = 0;

    // Initialize selected array and set all vertices as not selected
    for (i = 0; i < numVertices; i++)
        selected[i] = false;

    // Select the first vertex and mark it as selected
    selected[0] = true;
    numEdges = 0;

    // Repeat until all vertices are selected
    while (numEdges < numVertices - 1)
    {
        minWeight = INF;
        source = 0;
        destination = 0;

        // Find the minimum weight edge from the selected vertices
        for (i = 0; i < numVertices; i++)
        {
            if (selected[i])
            {
                for (j = 0; j < numVertices; j++)
                {
                    if (!selected[j] && graph[i][j] && graph[i][j] < minWeight)
                    {
                        minWeight = graph[i][j];
                        source = i;
                        destination = j;
                    }
                }
            }
        }

        // Mark the destination vertex as selected and print the edge
        selected[destination] = true;
        printf("Edge %d: (%d -> %d), Weight: %d\n", numEdges + 1, source, destination, minWeight);
        totalWeight += minWeight;
        numEdges++;
    }

    // Print the total weight of the minimum spanning tree
    printf("\nTotal Weight of the Minimum Spanning Tree: %d\n", totalWeight);
}

int main()
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nFinding the minimum spanning tree using Prim's algorithm...\n");
    prim();

    return 0;
}

