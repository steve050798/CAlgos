//Depth First Search
#include <stdio.h>
int st[100],v[100],c=0,top=-1;
void push(int x)
{
	if(top>99)
	{
		printf("\nStack Overflow\n");
		return;
	}
	else
	{
		top++;
		st[top]=x;
	}
}
int pop()
{
	if(top<0)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		top--;
	}
	return st[top+1];
}
int isEmpty()
{
	if(top<0)
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
int notInSt(int x)
{
	int i;
	for(i=0;i<=top;++i)
	{
		if(st[i]==x)
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
	push(s-1);
	while(!isEmpty())
	{
		v[c++]=pop();
		for(i=0;i<n;++i)
		{
			if(a[v[c-1]][i]==1 && notInV(i) && notInSt(i))
				push(i);
		}

	}	
	printf("\nThe Depth first traversal\n");
	for(i=0;i<c;++i)
	{
		printf("%d ",v[i]+1);
	}
	return 0;
}  
