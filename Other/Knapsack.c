//FRACTIONAL KNAPSACK PROBLEM
#include <stdio.h>
void fractional_knapsack(float capacity,float w[],float v[],int n)
{
	float p[100][2],temp,V=0;
	int i,j;
	for(i=0;i<n;++i)
	{
		p[i][0]=(float)(v[i])/w[i];
		p[i][1]=i;
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n-1-i;++j)
		{
			if(p[j][0]<p[j+1][0])
			{
				temp=p[j][0];
				p[j][0]=p[j+1][0];
				p[j+1][0]=temp;
				temp=p[j][1];
				p[j][1]=p[j+1][1];
				p[j+1][1]=temp;
			}
		}
	}
	i=0;
	while(capacity>0)
	{
		j=(int)p[i][1];
		if(capacity-w[j]>0)
		{
			V+=v[j];
			capacity-=w[j];
		}
		else
		{
			V+=capacity*p[i][0];
			capacity=0;	
		}
		i++;
	}
	printf("The optimal value of the knapsack: %0.2f",V);
}
int main()
{
	int n,i;
	float w[100],v[100],capacity;
	printf("Enter the capacity of the bag: ");
	scanf("%f",&capacity);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	printf("Enter the details of %d items", n);
	for(i=0;i<n;++i)
	{
		printf("\nITEM %d:\n",i+1);
		printf("Weight: ");
		scanf("%f",&w[i]);
		printf("Value: ");
		scanf("%f",&v[i]);
	}
	fractional_knapsack(capacity,w,v,n);
	return 0;
}
