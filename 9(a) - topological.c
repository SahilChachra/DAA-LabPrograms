#include<stdio.h>
int visited[10],adj[10][10],n,order[12],cost[10][10],pop[10],count=0;
int i,j,v,n;
void dfs(int v)
{
	int w;visited[v]=1;
	for(w=1;w<=n;w++)
	{
		if(cost[v][w]&&visited[w]==0)
		{
			visited[w]=1;
			//printf("%d\n",w);
			dfs(w);

		}
	}pop[count++]=v;
}
int main()
{
	int flag=0;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("Enter the Adjacency Matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) {
            printf("Enter value for Cost[%d][%d] : ",i,j);
			scanf("%d",&cost[i][j]);
        }
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("Enter the starting vertex:");
	scanf("%d",&v);
	dfs(v);
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			flag=1;
			printf("\nDisconnected Graph\n");
			break;
		}
	}
	if(flag==0)
		printf("\nConnected Grap\n");
	for(i=count-1;i>=0;i--)
	    printf("%d\t",pop[i]);
}
