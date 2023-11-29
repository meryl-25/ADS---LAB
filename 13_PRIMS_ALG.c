#include<stdio.h>
#include<stdio.h>
int main()
{
int cost[10][10],i,j,n,row,col,vertex[10],visited[10]={0},count=1,mincost,sumcost=0,edge,row_no,col_no,vertice1,vertice2;
clrscr();
printf("\nenter the no of vertices: ");
scanf("%d",&n);
printf("\nenter the vertices: ");
for(i=1;i<=n;i++)
{
scanf("%d",&vertex[i]);
}
printf("\nenter the matrix in the following way: ");
for(row=1;row<=n;row++)
{
printf("\n");
for(col=1;col<=n;col++)
{
printf(" x");
}
}
printf("\nenter the cost of respective edges: ");
for(row=1;row<=n;row++)
{
for(col=1;col<=n;col++)
{
scanf("%d",&cost[row][col]);
if(cost[row][col]==0)
{
cost[row][col]=999;
}
}
}
edge=n-1;
visited[1]=1;
while(count<=edge)
{
for(row=1,mincost=999;row<=n;row++)
{
for(col=1;col<=n;col++)
{
if(cost[row][col]<mincost)
{
if(visited[row]!=0)
{
mincost=cost[row][col];
vertice1=row_no=row;
vertice2=col_no=col;
}
}
}
}
if(visited[row_no]==0||visited[col_no]==0)
{
printf("\nselected vertex: %d edge:%d->%d=%d",count++,vertex[vertice1],vertex[vertice2],mincost);
sumcost+=mincost;
visited[col_no]=1;
}
cost[vertice1][vertice2]=cost[vertice2][vertice1]=999;
}
printf("\nsumcost=%d",sumcost);
getch();
return 0;
}

