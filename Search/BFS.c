//Breadth First Search
#include <stdio.h>
int q[100],v[100],c=0,f=-1,r=-1;
void enQueue(int x)
{
	if(r>99)
	{
		printf("\nQueue Overflow\n");
		return;
	}
	else if(f==-1&&r==-1)
	{
		f=0;r=0;
		q[r]=x;
	}
	else
	{
		r++;
		q[r]=x;
	}
}
int deQueue()
{
	if(f>r||f==-1)
	{
		f=-1;r=-1;
		printf("Queue Underflow\n");
	}
	else
	{
		f++;
	}
	return q[f-1];
}
int isEmpty()
{
	if(f>r||f==-1)
	{
		return 1;
	}
	return 0;
}
int notInV(int x)
{
	int i;
	for(i=0;i<c;++i)
	{
		if(v[i]==x)
		{
			return 0;
		}
	}
	return 1;
}
int notInQ(int x)
{
	int i;
	for(i=f;i<=r;++i)
	{
		if(q[i]==x)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int a[100][100],n,i,j,s;
	printf("Enter the number of nodes in the graph: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the source vertex: ");
	scanf("%d",&s);
	enQueue(s-1);
	while(!isEmpty())
	{
		v[c++]=deQueue();
		for(i=0;i<n;++i)
		{
			if(a[v[c-1]][i]==1 && notInV(i) && notInQ(i))
				enQueue(i);
		}

	}	
	printf("\nThe breadth first traversal\n");
	for(i=0;i<c;++i)
	{
		printf("%d ",v[i]+1);
	}
	return 0;
}  
