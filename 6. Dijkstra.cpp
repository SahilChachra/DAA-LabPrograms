#include<stdio.h>
int main() {
	int cost[10][10], parent[10], visited[10],dist[10],i,k,w,v,min,n,sv,j,x;
	
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the cost matrix - 999 for no edge\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			printf("Cost[%d][%d] = ",i,j);
			scanf("%d",&cost[i][j]);
		}
	}
	
	printf("Enter source vertex\n");
	scanf("%d",&sv);
	
	for(i=1;i<=n;i++) {
		visited[i]=0;
		dist[i]=cost[sv][i];
		parent[i] = sv;
	}
	
	visited[sv] = 1;
	dist[sv]=0;
	parent[sv] = sv;
	
	for(k=2;k<=n;k++) {
		min=999;
		for(w=1;w<=n;w++) {
			if(dist[w]<min && visited[w]==0) {
				min=dist[w];
				v=w;
			}
		}
		visited[v] = 1;
		for(w=1;w<=n;w++) {
			if(dist[v]+cost[v][w]<dist[w]) {
				dist[w] = cost[v][w] + dist[v];
				parent[w]=v;
			
			}
		}
	}
	
	printf("Shortest path \n");  //This should have been working.
	for(j=1;j<=n;j++) {
		if(j!=sv) {
			x=j;
			while(x!=sv) {
				printf("%d <--",x);
				x=parent[x];
			}
			printf("\t%d = %d\n",sv,dist[j]);
		}
	}
	
	/*
	for(i=1;i<=n;i++) {
		if(i!=sv)
			printf("%d --> %d = %d\n",sv,i,dist[i]);
	}
	*/
	
}
