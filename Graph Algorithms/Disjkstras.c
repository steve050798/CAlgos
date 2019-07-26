//DJKSTRA's ALGORITHM
/*
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
*/
#include <stdio.h>
void update(int graph[100][100],int mset[100][2],int n,int min)
{
   int i;
   for(i=0;i<n;++i)
   {
      if(graph[min][i]!=0&&!mset[i][1])
      {
         if(mset[i][0]==-1||mset[i][0]>mset[min][0]+graph[min][i])
         {
            mset[i][0]=mset[min][0]+graph[min][i];
         }
      }
   }
}  
int findmin(int mset[100][2],int n)
{
   int min=1000,pos=-1,i;
   for(i=0;i<n;++i)
   {
      if(!mset[i][1]&&mset[i][0]!=-1)
      {
         if(min>mset[i][0])
         {
            min=mset[i][0];
            pos=i;
         }
      }
   }
   return pos;
}
void djkstra(int graph[100][100],int n,int s)
{
   int spt[100],c=0,mset[100][2],i,j,min;
   for(i=0;i<n;++i)
   {
      mset[i][0]=-1;
      mset[i][1]=0;
   }
   mset[s][0]=0;
   while(c<n)
   {
      min=findmin(mset,n);
      mset[min][1]=1;
      spt[c++]=min;
      update(graph,mset,n,min);
   }
   printf("The shortest path tree goes as follows: ");
   for(i=0;i<c;++i)
   {
      printf("%d ",spt[i]);
   }
   printf("\nDistance from source to all vertices:\n");
   for(i=0;i<c;++i)
   {
      printf("To %d: %d\n",i,mset[i][0]);
   }
}
int main()
{
   int graph[100][100],n,i,j,s;
   printf("Enter the number of nodes in the graph: ");
   scanf("%d",&n);
   printf("\nEnter the Adjacency matrix of the graph:\n");
   for(i=0;i<n;++i)
   {
      for(j=0;j<n;++j)
      {
         scanf("%d",&graph[i][j]);
      }
   }
   printf("Choose a source vertex for Djkstra's Algorithm: ");
   scanf("%d",&s);
   djkstra(graph,n,s);
   return 0;
}
