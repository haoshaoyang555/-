#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[5][8]={
    {0,0,1,1,1,1,1,1},
    {1,0,0,0,1,1,1,1},
    {1,0,1,0,1,1,1,1},
    {1,0,1,0,0,0,1,1},
    {1,0,1,1,1,0,1,1}
};
int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int book[51][51];
int n=4,m=7,p=4,q=5,min=99999999;
void dfs(int x,int y,int step)
{
  int tx,ty,k;
  if(x==p && y==q)
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(book[i][j] == 1)
                    printf("(%d,%d)",i,j);
            }
        }
        if(step<min)
            min=step;
        return;
    }
    for(k=0;k<=3;k++)
     {
       tx=x+next[k][0];
       ty=y+next[k][1];
       if(tx<0||tx>n||ty<0||ty>m)
            continue;
       if(map[tx][ty]==0 && book[tx][ty]==0)
       {
           book[tx][ty]=1;
           dfs(tx,ty,step+1);
           book[tx][ty]=0;
       }
     }
     return;
}
   int main()
   {


       int startx=0;
       int starty=0;
       book[startx][startx]=1;
       dfs(startx,starty,0);
       printf("%d",min);
       getchar();getchar();
       return 0;
   }