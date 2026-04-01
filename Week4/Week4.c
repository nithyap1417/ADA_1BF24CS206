#include<stdio.h>
#include<stdlib.h>
#define V 5
int minDistance(int dist[], int visited[]) {
    int min = 999, min_index;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int src){
    printf("Vertex \t distance from source: %d\n",src);
    for(int i=0;i<V;i++){
        printf("%d \t %d\n",i,dist[i]);
    }
}

void djkstra(int graph[V][V], int src){
    int dist[V], visited[V];
    for(int i=0;i<V;i++){
        dist[i]=999;
        visited[i]=0;
    }
    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int u=minDistance(dist,visited);
        visited[u]=1;
        for(int v=0;v<V;v++){
            if(!visited[v] && graph[u][v] && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSolution(dist,src);
}

int main()
{
    int graph[V][V];
    printf("Enter Adjacency Matrix: ");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    int src;
    printf("\nEnter Source Vertex: ");
    scanf("%d",&src);
    djkstra(graph,src);
    return 0;
}
