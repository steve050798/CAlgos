#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int linearSearch(int a[],int n,int e)
{
	int i,pos=-1;
	for(i=0;i<n;++i)
	{
	    Sleep(0.001);
		if(a[i]==e)
		{
			pos=i;
			break;
		}
	}
	return pos;
}
int main()
{
	int a[100000],n=100000,i,e,pos;
	clock_t start,end;
	/*
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	*/
	//srand(time(NULL));
	for(i=0;i<n;++i)
		a[i]=i;
	printf("Enter the element you want to search for: ");
	scanf("%d",&e);
	start=clock();
	pos=linearSearch(a,n,e);
	end=clock();
	if(pos==-1)
		printf("\nElement is not found");
	else
		printf("Element found at %d position\n",pos+1);
	printf("Time taken: %lf",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
