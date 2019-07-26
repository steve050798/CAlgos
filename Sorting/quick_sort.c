//QUICK SORT
#include <stdio.h>
void quick_sort(int a[],int s,int e)
{
	int pivot=a[e],i,pos=s,temp;
	for(i=s;i<=e;++i)
	{
		if(a[i]<=pivot)
		{
			temp=a[pos];
			a[pos]=a[i];
			a[i]=temp;
			pos++;
		}
	}
	if(pos<e)
		quick_sort(a,pos,e);
	if(s<pos-2)
		quick_sort(a,s,pos-2);
}
int main()
{
	int a[100],n,i;
	printf("Enter array size: ");
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("\nThe Sorted Array\n");
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
