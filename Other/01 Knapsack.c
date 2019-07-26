//BINARY KNAPSACK PROBLEM
#include <stdio.h>
void binary_knapsack(int capacity,int w[],int v[],int n)
{
	int m[100][100],i,j;
	for(i=0;i<=capacity;++i)
	{
		m[0][i]=0;
	}
	for(i=1;i<n+1;++i)
	{
		for(j=0;j<=capacity;++j)
		{
			if(j>=w[i-1])
			{
				if(m[i-1][j]<m[i-1][j-w[i-1]]+v[i-1])
					m[i][j]=m[i-1][j-w[i-1]]+v[i-1];
				else
					m[i][j]=m[i-1][j];
			}
			else
				m[i][j]=m[i-1][j];
		}
	}
	printf("\nThe optimal value of the knapsack: %d",m[n][capacity]);
}
int main()
{
	int n,i;
	int w[100],v[100],capacity;
	printf("Enter the capacity of the bag: ");
	scanf("%d",&capacity);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	printf("Enter the details of %d items", n);
	for(i=0;i<n;++i)
	{
		printf("\nITEM %d:\n",i+1);
		printf("Weight: ");
		scanf("%d",&w[i]);
		printf("Value: ");
		scanf("%d",&v[i]);
	}
	binary_knapsack(capacity,w,v,n);
	return 0;
}
