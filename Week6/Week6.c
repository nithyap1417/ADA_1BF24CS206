#include<stdio.h>
#define v 4
#define INF 99999

void printSolution(int dist[v][v])
{
    printf("Shortest distance matrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dist[i][j]==INF)
                printf("%7s","INF");
            else
                printf("%7d",dist[i][j]);
        }
        printf("\n");
    }
}
void floydAlgorithm(int graph[v][v])
{
    int dist[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                     if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                         dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist);
}
int main()
{
    printf("Enter graph:\n ");
    int graph[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    floydAlgorithm(graph);
    return 0;
}


