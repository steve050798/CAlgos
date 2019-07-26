//PRIM's Algorithm
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int visited[100]={0};
int Visited(int i)
{
	return visited[i];
}
int allVisited(int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		if(visited[i]==0)
		{
			return 0;
		}
	}
	return 1;
}
int min(int key[2][100],int n)
{
	int min=100,x=-1,i;
	for(i=0;i<n;++i)
	{
		if(key[0][i]!=-1&&!Visited(i))
		{
			if(key[0][i]<min)
			{
				min=key[0][i];
				x=i;
			}
		}
	}
	return x;
}
void prims(int a[100][100],int key[2][100],int n)
{
	int i=0,j,pos,x,y,weight=0;
	visited[0]=1;
	printf("\nThe Minimum Spanning Tree\n\n");
	while(!allVisited(n))
	{

		for(j=0;j<n;++j)
		{

			if(a[i][j]!=0&&(key[0][j]==-1||key[0][j]>a[i][j]+key[i][0]))
			{
				key[0][j]=a[i][j]+key[i][0];
				key[1][j]=i;
			}
		}
		pos=min(key,n);
		if(pos==-1)
			break;
		visited[pos]=1;
		weight+=key[0][pos];
		printf("Connected %d to %d\n",key[1][pos],pos);
		i=pos;
	}
	printf("Weight of the MST: %d",weight);
}
int main()
{
    clock_t start,end;
	int adj[100][100],key[2][100],n,i,j;
	printf("Enter the number of nodes in the graph: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{

			scanf("%d",&adj[i][j]);
		}
		key[0][i]=-1;
	}
	key[0][0]=0;
	start=clock();
	prims(adj,key,n);
	end=clock();
	printf("%Time taken: %lf",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
