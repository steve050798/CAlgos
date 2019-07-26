  //MERGE SORT
#include <stdio.h>
void merge(int a[],int s1,int e1,int s2,int e2)
{
	int c[200],k=0,i=s1,j=s2;
	while(i<=e1&&j<=e2)
	{
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}
	while(i<=e1)
	{
		c[k++]=a[i++];
	}
	while(j<=e2)
	{
		c[k++]=a[j++];
	}
	k=0;
	for(i=s1;i<=e2;++i)
	{
		a[i]=c[k++];
	}
}
void merge_sort(int a[],int start,int end)
{
	if(start<end)
	{
		merge_sort(a,start,(start+end)/2);
		merge_sort(a,(start+end)/2+1,end);
		merge(a,start,(start+end)/2,(start+end)/2+1,end);
	}
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
	merge_sort(a,0,n-1);
	printf("\nThe Sorted Array\n");
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
