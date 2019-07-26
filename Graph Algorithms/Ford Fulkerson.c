//FORD FULKERSON ALGORITHM
/*
0 3 2 0 0 0
0 0 1 3 4 0
0 0 0 0 2 0
0 0 0 0 0 2
0 0 0 0 0 3
0 0 0 0 0 0

0 10 0 10 0 0
0 0 4 2 8 0
0 0 0 0 0 10
0 0 0 0 9 0
0 0 6 0 0 10
0 0 0 0 0 0
*/
#include <stdio.h>
int st[100],top;
void push(int x)
{
	if(top<100)
	{
		st[++top]=x;
	}
}
int pop()
{
	top--;
	return st[top+1];
}
int dfs(int graph[100][100],int n,int parent[100],int s,int t)
{
	int x[100]={0},i,temp;
	top=-1;
	push(s);
	parent[s]=-1;
	while(top!=-1)
	{
		x[st[top]]=1;
		temp=pop();
		for(i=0;i<n;++i)
		{
			if(!x[i]&&graph[temp][i])
			{
				push(i);
				x[i]=1;
				parent[i]=temp;
			}
		}
	}
	return x[t];
}			
void flow_network(int graph[100][100],int n,int s,int t)
{
    int parent[100],i,flow,max=0;
    while(dfs(graph,n,parent,s,t))
    {
    	flow=1000;
    	for(i=t;parent[i]!=-1;i=parent[i])
    	{
    		if(flow>graph[parent[i]][i])
    			flow=graph[parent[i]][i];
    	}
    	for(i=t;parent[i]!=-1;i=parent[i])
    	{
    		graph[parent[i]][i]-=flow;
    	}
    	max+=flow;
    }
    printf("\nThe maximum flow is: %d",max);
}
int main()
{
    int graph[100][100],i,j,n,s,t;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);
    printf("Enter the graph's adjacency list:\n");
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter the source: ");
    scanf("%d",&s);
    printf("Enter the destination: ");
    scanf("%d",&t);
    flow_network(graph,n,s,t);
    return 0;
}
