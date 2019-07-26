//HEAP SORT
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int temp;
void heapify(int a[],int n)
{
    int i,lchild,rchild,root;
    for(i=n-1;i>=1;i-=2)
    {
        if(i%2)
        {
            lchild=i;
            rchild=((i+1)<n)?lchild+1:lchild;
        }
        else
        {
            rchild=i;
            lchild=i-1;
        }
        root=lchild/2;
        if(a[root]<a[lchild])
        {
            temp=a[root];
            a[root]=a[lchild];
            a[lchild]=temp;
        }
        if(a[root]<a[rchild])
        {
            temp=a[root];
            a[root]=a[rchild];
            a[rchild]=temp;
        }
    }
}
void heapSort(int a[],int n)
{
    //int i;
	if(n)
	{

		heapify(a,n);
		/*
		for(i=0;i<n;++i)
        {
		printf("%d ",a[i]);
        }
        printf("\n");
		*/
		temp=a[n-1];
		a[n-1]=a[0];
		a[0]=temp;
		heapSort(a,n-1);
	}
}
int main()
{
	int a[1000],n,i;
	clock_t start,end;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the array: ");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	heapSort(a,n);
	printf("Sorted Array\n");
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	n=1000;
	for(i=0;i<n;++i)
        a[i]=i;
    start=clock();
    heapSort(a,n);
    end=clock();
    printf("\nTime taken in the worst case: %lf",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
