#include <stdio.h> 
#include <stdlib.h> 
 
struct Edge { 
    int src, dest, weight; 
}; 
 
struct Graph { 
    int V, E; 
    struct Edge* edge; 
}; 
 
struct Subset { 
    int parent; 
    int rank; 
}; 
 
struct Graph* createGraph(int V, int E) { 
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
    graph->E = E; 
    graph->edge = (struct Edge*) malloc(E * sizeof(struct Edge)); 
    return graph; 
} 
 
int find(struct Subset subsets[], int i) { 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 
 
void Union(struct Subset subsets[], int x, int y) { 
    int rootX = find(subsets, x); 
    int rootY = find(subsets, y); 
     
    if (subsets[rootX].rank < subsets[rootY].rank) 
        subsets[rootX].parent = rootY; 
    else if (subsets[rootX].rank > subsets[rootY].rank) 
        subsets[rootY].parent = rootX; 
    else { 
        subsets[rootY].parent = rootX; 
        subsets[rootX].rank++; 
    } 
} 
 
 
 
int compareEdges(const void* a, const void* b) { 
    struct Edge* edgeA = (struct Edge*) a; 
    struct Edge* edgeB = (struct Edge*) b; 
    return edgeA->weight - edgeB->weight; 
} 
 
void KruskalMST(struct Graph* graph) { 
    int V = graph->V; 
    struct Edge resultMST[V]; 
    int e = 0; 
    int i = 0; 
 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges); 
 
    struct Subset* subsets = (struct Subset*) malloc(V * sizeof(struct Subset)); 
 
    for (int v = 0; v < V; v++) { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 
 
    while (e < V - 1 && i < graph->E) { 
        struct Edge nextEdge = graph->edge[i++]; 
 
        int x = find(subsets, nextEdge.src); 
        int y = find(subsets, nextEdge.dest); 
 
        if (x != y) { 
            resultMST[e++] = nextEdge; 
            Union(subsets, x, y); 
        } 
    } 
 
    printf("Edges in Minimum Cost Spanning Tree:\n"); 
    int totalWeight = 0; 
    for (i = 0; i < e; ++i) { 
        printf("%d -- %d  Weight: %d\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight); 
        totalWeight += resultMST[i].weight; 
    } 
    printf("Total Weight of MST: %d\n", totalWeight); 
 
    free(subsets); 
} 
 
int main() { 
    int V, E; 
    int src, dest, weight; 
 
 
 
    printf("Enter the number of vertices: "); 
    scanf("%d", &V); 
 
    printf("Enter the number of edges: "); 
    scanf("%d", &E); 
 
    struct Graph* graph = createGraph(V, E); 
 
    for (int i = 0; i < E; ++i) { 
        printf("Enter edge %d (source destination weight): ", i + 1); 
        scanf("%d %d %d", &src, &dest, &weight); 
        graph->edge[i].src = src; 
        graph->edge[i].dest = dest; 
        graph->edge[i].weight = weight; 
    } 
 
    KruskalMST(graph); 
 
    return 0; 
} 
