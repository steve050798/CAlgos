//KRUSKAL'S ALGORITHM
/*
Adjacency matrix:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0


0 3 0 0 0 2 0 0 0 0
3 0 17 16 0 0 0 0 0 0
0 17 0 8 0 0 0 0 18 0
0 16 8 0 11 0 0 0 4 0
0 0 0 11 0 1 6 5 10 0
2 0 0 0 1 0 7 0 0 0
0 0 0 0 6 7 0 15 0 0
0 0 0 0 5 0 15 0 12 13
0 0 18 4 10 0 0 12 0 9
0 0 0 0 0 0 0 13 9 0
*/
#include <stdio.h>
#include <time.h>
int parent[100];
void sort(int key[3][1000],int n)
{
	int i,j,temp;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n-1-i;++j)
		{
			if(key[0][j]>key[0][j+1])
			{
				temp=key[0][j];key[0][j]=key[0][j+1];key[0][j+1]=temp;
				temp=key[1][j];key[1][j]=key[1][j+1];key[1][j+1]=temp;
				temp=key[2][j];key[2][j]=key[2][j+1];key[2][j+1]=temp;
			}
		}
	}
}

int findparent(int x)
{
	if(parent[x]!=-1)
		return findparent(parent[x]);
	else
		return x;
}
int cycle(int x,int y)
{
	if(findparent(x)==findparent(y))
	{
		return 1;
	}
	return 0;
}
void kruskals(int a[100][100],int key[3][1000],int n)
{
	int weight=0;
	int i,c=0,temp1,temp2;
	for(i=0;i<n;++i)
		parent[i]=-1;
	i=0;
	printf("\nThe Minimum Spanning Tree\n");
	while(c<n-1)
	{
		if(!cycle(key[1][i],key[2][i]))
		{
			c++;
			printf("Connected %d to %d\n",key[1][i],key[2][i]);
            weight+=key[0][i];
			temp1=findparent(key[1][i]);
			temp2=findparent(key[2][i]);
			parent[temp1]=temp2;
		}
		i++;
	}
	printf("\nWeight of the MST: %d",weight);
}
int main()
{
    clock_t start,end;
	int a[100][100],n,key[3][1000]={0},i,j,k,c=0;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0&&j>=i)
			{
				key[0][c]=a[i][j];
				key[1][c]=i;
				key[2][c]=j;
				c++;
			}
		}
	}
    start=clock();
	sort(key,c);
	printf("\nKEY\n");
	for(i=0;i<3;++i)
	{
		for(j=0;j<c;++j)
		{
			printf("%d ",key[i][j]);
		}
		printf("\n");
	}

	kruskals(a,key,n);
	end=clock();
	printf("\nTime taken: %lf",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
