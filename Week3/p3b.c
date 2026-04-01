#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, weight;
};

struct Subset {
    int parent;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        return find(subsets, subsets[i].parent);
    return i;
}

void unionSet(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    subsets[rootX].parent = rootY;
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int createEdgeList(int graph[MAX][MAX], int V, struct Edge edges[]) {
    int k = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }
    return k;
}


void kruskalMST(struct Edge edges[], int E, int V) {
    struct Edge result[MAX];
    struct Subset subsets[MAX];

    for (int i = 0; i < V; i++)
        subsets[i].parent = i;

    qsort(edges, E, sizeof(edges[0]), compare);

    int e = 0;
    int i = 0;
    int minCost = 0;

    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, next.u);
        int y = find(subsets, next.v);

        if (x != y) {
            result[e++] = next;
            minCost += next.weight;
            unionSet(subsets, x, y);
        }
    }


    printf("\nEdges in MST:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
    }

    printf("Minimum Cost = %d\n", minCost);
}

int main() {
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    struct Edge edges[MAX];
    int E = createEdgeList(graph, V, edges);

    kruskalMST(edges, E, V);

    return 0;
}
