#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void selectionsort(int a[],int n)
{
 int i=0,j,t;
 for(i=0;i<n-1;i++)
 {
  for(j=i;j<n;j++)
  {
   if(a[j]<a[i])
   {
    t=a[j];
    a[j]=a[i];
    a[i]=t;
   }
  }
 }
}

void binarySearch(int a[],int n,int e)
{
 int beg=0,med,end=n-1,i=0;
  while(beg<=end)
  {
   med=(beg+end)/2;
   if(a[med]<e)
   {
    beg=med+1;
   }
   if(a[med]>e)
   end=med-1;
   if(a[med]==e)
   {
    i=1;
    printf("Number found at %d position\n",med+1);
    break;
   }
  }
   if(!i)
   printf("Number is not found\n");
}
int main()
{
        clock_t start,end;
	int a[100000],n=100000,i,e;
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

	//selectionsort(a,n);
	printf("Enter the element you want to search for: ");
	scanf("%d",&e);
	start=clock();
	binarySearch(a,n,e);
	end=clock();
	printf("Time taken:%lf",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
