#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 30
int map[7][7]={///棋盘
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
             };
typedef struct zuobiao
{
  int x,y;
}zuobiao;
typedef struct stack
{
  zuobiao a[max];
  int top;
}stack;
////构造栈
stack *initstack()
{
   stack *s;
   s=(stack *)malloc(sizeof(stack));
   s->top=-1;
   return s;
}
int push(stack *s,zuobiao *a)//入栈
{
     if(s->top==max-1)
     {
     	printf("栈满!\n");
     	return 0;
     }
     else
     {
       s->a[++s->top].x=a->x;
       s->a[s->top].y=a->y;
       return 1;
     }
}
int pop(stack *s,zuobiao *a)
{
  if(s->top==-1)
  {
  	printf("栈空\n");
  	return 0;
  }
  else
  {
  a->x=s->a[s->top].x;
  a->y=s->a[s->top--].y;
  return 1;
 }
}
void xiaqi(stack *s)
{
   int a,b;
   int x,y,k;
   int l=1;
   zuobiao *zb;
   zb=(zuobiao *)malloc(sizeof(zuobiao));
   printf("请输入开始位置x,y\n");
   scanf("%d,%d",&a,&b);
   zb->x=a;
   zb->y=b;
   map[a][b]=l++;
   k=push(s,zb);
   //printf("%d",k);
   int yy[8]={-2,-1,1,2,2,1,-1,-2};
   int xx[8]={1,2,2,1,-1,-2,-2,-1};
   while(k)
   {
     for(int i=0;i<8;i++)
     {
       x=a+xx[i];
       y=b+yy[i];  
       //printf("%d,%d\n",x,y);
       if(x<7&&y<7&&x>=0&&y>=0&&map[x][y]==0&&k)
       {
       	 zb->x=x;
       	 zb->y=y;
       	 map[x][y]=l++;
       	 printf("%d,%d\n",x,y);
         k=push(s,zb);
       }
     }
     k=pop(s,zb);
     a=zb->x;
     b=zb->y;
   }
}
int main()
{
   stack *s;
   s=initstack();
   xiaqi(s);
   for(int i=0;i<7;i++)
   {
   	for(int j=0;j<7;j++)
   	{
       printf("%d,",map[i][j]);

   	}
   	 printf("\n");
   }
}