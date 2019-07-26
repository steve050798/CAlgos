//FLOYD WARSHALL'S ALGORITHM
/*
0 0 6 3 0
3 0 0 0 0
0 0 0 2 0
0 1 1 0 0
0 4 0 2 0
*/
#include <stdio.h>
void floyd_warshall(int graph[100][100],int n)
{
   int i,j,k,spt[100][100];
   for(i=0;i<n;++i)
   {
      for(j=0;j<n;++j)
      {
         if(graph[i][j]==0)
         {
            if(j!=i)
               spt[i][j]=10000;
            else
               spt[i][j]=0;
         }
         else
         {
            spt[i][j]=graph[i][j];
         }
      }
   }
   for(k=0;k<n;++k)
   {
      for(i=0;i<n;++i)
      {
         for(j=0;j<n;++j)
         {
            if(spt[i][j]>spt[i][k]+spt[k][j])
               spt[i][j]=spt[i][k]+spt[k][j];
         }
       }
   }
   printf("The Floyd Warshall matrix:\n");
   for(i=0;i<n;++i)
   {
      for(j=0;j<n;++j)
      {
         printf("%d ",spt[i][j]);
      }
      printf("\n");
   }
}
int main()
{
    int a[100][100],n,i,j;
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
    floyd_warshall(a,n);
    return 0;
}
