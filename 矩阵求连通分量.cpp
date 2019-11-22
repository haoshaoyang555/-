#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 20
typedef struct graphy
{
	int a[max+1][max+1];
	char b[max];
	int node_number;
	int vex_number;
}graphy;
typedef struct queue
{
	int data[max+1];
	//char ch;
	int rear;
	int front;
}queue;
int visted[max]={0};
queue *inint_queue()
{
	queue *q;
	q=(queue *)malloc(sizeof(queue));
	q->front=-1;
	q->rear=-1;
	return q;
}
int push_queue(queue *q,int a)
{
   if(q->rear+1==max)
   {
   	return 0;
   }
   q->data[++q->rear]=a;
   return 1;
}
int pop_queue(queue *q,int *a)
{
	if(q->rear==q->front)
	{
		return 0;
	}
	*a=q->data[++q->front];
	return 1;
}
int select(char a[],char b)
{   
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]==b)
		{
			return i;
		}
	}
	return 0;
}
void look_od_id(graphy *gra1,char b)
{
    graphy *gra=gra1;
    int k;
    int od=0;
    int id=0;
    k=select(gra->b,b);
    for(int i=1;i<=gra->node_number;i++)
    {
    	if(gra1->a[k+1][i]==1)
    	{
    		od++;
    	}
    	if(gra1->a[i][k+1]==1)
    	{
    		id++;
    	}
    }
   printf("%c %d %d %d\n",b,od,id,od+id);
   return ;
}
void dfs_graphy(graphy *gra1,int v0)
{
    graphy *gra=gra1;
    visted[v0-1]=1;
    for(int i=1;i<=gra->node_number;i++)
    {
    	if(gra->a[v0][i]==1&&visted[i-1]==0)
    	{
         dfs_graphy(gra,i);
    	}
    }
}
void dfs(graphy *gra)
{ 
  int k=0;
  for(int i=1;i<=gra->node_number;i++)
  { 
  	if(visted[i-1]==0)
  	{ 
  		dfs_graphy(gra,i);
      k++;
  	}
  }
   printf("%d",k);
  
}
/*void bfs_graphy(graphy *gra1)
{
	graphy *gra=gra1;
	queue *q;
	q=inint_queue();
	for(int i=0;i<max+1;i++)
	{
		visted[i]=0;
	}
    int k=0;
    int m=1;
    printf("%c",gra->b[k]);
    visted[k]=1;
    k=1;
	while(m)
	{  
       for(int i=1;i<=gra->node_number;i++)
		{
             if(visted[i-1]==0&&gra->a[k][i]==1)
             {
             	push_queue(q,i);
             }
		}
		m=pop_queue(q,&k);
		if(m!=0&&visted[k-1]==0)
		{
			printf("%c",gra->b[k-1]);
			visted[k-1]=1;
		}
	}
}*/
int main()
{
   graphy *gra;
   char ga[4];
   char m,n;
   int x,y;
   gra=(graphy *)malloc(sizeof(graphy));
   for(int i=0;i<max+1;i++)
   {
   	 for(int j=0;j<max+1;j++)
   	 {
   	 	gra->a[i][j]=0;
   	 }
   }
  // printf("请输入结点的个数,边个数\n");
   scanf("%d %d",&gra->node_number,&gra->vex_number);
   getchar();
  // printf("输入结点值:\n");
   gets(gra->b);
   for(int i=1;i<=gra->vex_number;i++)
   {
   //	printf("输入边信息\n");
    gets(ga);
    m=ga[0];
    n=ga[1];
    x=select(gra->b,m);
    y=select(gra->b,n);
    gra->a[x+1][y+1]=1;
    gra->a[y+1][x+1]=1;
   }
   /*for(int i=0;i<gra->node_number;i++)
   {
   	 look_od_id(gra,gra->b[i]);
   }*/
   dfs(gra);
  // printf("\n");
   //bfs_graphy(gra);
   return 0;
}