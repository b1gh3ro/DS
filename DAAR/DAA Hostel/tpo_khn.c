#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_VERTICES 100 
 
struct Node { 
    int vertex; 
    struct Node* next; 
}; 
 
struct Graph { 
    int numVertices; 
    int* inDegree; 
    struct Node** adjLists; 
}; 
 
struct Node* createNode(int v) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->vertex = v; 
    newNode->next = NULL; 
    return newNode; 
} 
 
struct Graph* createGraph(int vertices) { 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
    graph->numVertices = vertices; 
 
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*)); 
    graph->inDegree = (int*)malloc(vertices * sizeof(int)); 
 
    for (int i = 0; i < vertices; i++) { 
        graph->adjLists[i] = NULL; 
        graph->inDegree[i] = 0; 
    } 
    return graph; 
} 
 
void addEdge(struct Graph* graph, int src, int dest) { 
    struct Node* newNode = createNode(dest); 
    newNode->next = graph->adjLists[src]; 
    graph->adjLists[src] = newNode; 
 
    graph->inDegree[dest]++; 
} 
 
 
 
void topologicalSortUsingKahn(struct Graph* graph) { 
    int vertices = graph->numVertices; 
    int* inDegree = graph->inDegree; 
    struct Node** adjLists = graph->adjLists; 
 
    int* topoOrder = (int*)malloc(vertices * sizeof(int)); 
    int topoIndex = 0; 
 
    int* queue = (int*)malloc(vertices * sizeof(int)); 
    int front = 0, rear = 0; 
 
    for (int i = 0; i < vertices; i++) { 
        if (inDegree[i] == 0) { 
            queue[rear++] = i; 
        } 
    } 
 
    while (front != rear) { 
        int u = queue[front++]; 
        topoOrder[topoIndex++] = u; 
 
        struct Node* temp = adjLists[u]; 
        while (temp != NULL) { 
            int v = temp->vertex; 
            if (--inDegree[v] == 0) { 
                queue[rear++] = v; 
            } 
            temp = temp->next; 
        } 
    } 
 
    if (topoIndex != vertices) { 
        printf("Topological sorting not possible (graph has cycle)\n"); 
    } else { 
        printf("Topological Sorting using Kahn's Algorithm: "); 
        for (int i = 0; i < vertices; i++) { 
            printf("%d ", topoOrder[i]); 
        } 
        printf("\n"); 
    } 
 
    free(queue); 
    free(topoOrder); 
} 
 
int main() { 
    int vertices, edges, src, dest; 
 
 
 
    printf("Enter the number of vertices: "); 
    scanf("%d", &vertices); 
 
    struct Graph* graph = createGraph(vertices); 
 
    printf("Enter the number of edges: "); 
    scanf("%d", &edges); 
 
    for (int i = 0; i < edges; i++) { 
        printf("Enter edge %d (source destination): ", i + 1); 
        scanf("%d %d", &src, &dest); 
        addEdge(graph, src, dest); 
    } 
 
    topologicalSortUsingKahn(graph); 
 
    return 0; 
} 
