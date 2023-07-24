/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<time.h>
#define infinity 9999;
#define max 10

int g[max][max],i,j,n,s,cost[max][max];
void dijkstra(int g[max][max],int n,int startnode)
{
    int cost[max][max],dist[max],pred[max];
    int visited[10],count=1,min,nextnode,i,j;
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
    if(g[i][j]==0)
    {
    cost[i][j]=infinity;
    }
    else
    cost[i][j]=g[i][j];
    }}
     for(i=0;i<n;i++)
     {
         dist[i]=cost[nextnode][i];
         pred[i]=startnode;
         visited[i]=0;
     }
     dist[startnode]=0;
     visited[startnode]=1;
     while(count<n-1)
     {
         min=infinity;
        for(i=0;i<n;i++)
        if(dist[i]<min && !visited[i])
        {
            min=dist[i];
            nextnode=i;
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
        if(!visited[i])
        if(min+cost[nextnode][i]<dist[i])
        {
        dist[i]=min+cost[nextnode][i];
        pred[i]=nextnode;
        }
        count++;
     }
        for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\ndistance of node %d=%d",i,dist[i]);
            printf("\n\tpath:%d",i); 
            j=i;
            do{
                j=pred[j];
                printf("-->%d",j);
            }while(j!=startnode);
        }
    
}

void floyd(int a[10][10], int n) 
{ 
   for(int k=0;k<n;k++) 
    { 
     for(int i=0;i<n;i++) 
      { 
      for(int j=0;j<n;j++) 
       { 
         if(a[i][j]>a[i][k]+a[k][j]) 
          { 
            a[i][j]=a[i][k]+a[k][j]; 
          } 
       } 
     } 
   } 
printf("All Pairs Shortest Path is :\n"); 
for(int i=0;i<n;i++) 
   { 
    for(int j=0;j<n;j++) 
     { 
      printf("%d ",a[i][j]); 
     }
   printf("\n"); 
   } 
} 


int main()
{
    int ch;
    printf("enter\n1.single source shortest path using Dijkstra algorithm.\n2.all pair shortest path using Flyod Warshall algorithm.");
    printf("\nenter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
           printf("enter number of nodes:");
           scanf("%d",&n);
           printf("enter the adjacency matrix:\n");
          for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          scanf("%d",&g[i][j]);
          printf("enter the start node:");
          scanf("%d",&s);
          dijkstra(g,n,s);
          break;
        }
        
        case 2:
        {
           printf("Enter the number of vertices\n"); 
           scanf("%d",&n); 
           printf("Enter the cost adjacency matrix\n"); 
           for(int i=0;i<n;i++) 
           { 
             for(int j=0;j<n;j++) 
             { 
               scanf("%d",&cost[i][j]); 
              } 
            } 

          floyd(cost,n);
          break; 
        }
        default:printf("enter correct choice!!");
    }
    return 0;
}
