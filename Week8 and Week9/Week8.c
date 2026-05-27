#include<stdio.h>
#define MAX 10
int main()
{
    int n,i,j;
    int graph[MAX][MAX];
    int indegree[MAX]={0};
    int queue[MAX], front=0, rear=0;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==1)
                indegree[j]++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(indegree[i]==0)
            queue[rear++]=i;
    }
    printf("Topological Order: ");
    while(front<rear)
    {
        int v = queue[front++];
        printf("%d ",v);
        for(j=0;j<n;j++)
        {
            if(graph[v][j]==1)
            {
                indegree[j]--;
                if(indegree[j]==0)
                    queue[rear++]=j;
            }
        }
    }
    return 0;
}
