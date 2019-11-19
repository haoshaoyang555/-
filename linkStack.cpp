#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
   char zifu[20];
   int top;
}Stack;
//初始栈
Stack *initstack()
{
   Stack *s;
   s=(Stack *)malloc(sizeof(Stack));
   s->top=-1;
   return s;
}
//判空栈
int Fullstack(Stack *a)
{
  if (a->top==19)
  {
  	return -1;
  }
  return 1;

}//
int Emptystack(Stack *a)
{
  if (a->top==-1)
  {
    return -1;
  }
   return 1;
}
int Pushstack(Stack *a,char c)
{
  if (Fullstack(a))
  {
     a->zifu[++a->top]=c;
     printf("%c\n",a->zifu[a->top]);
     return 1;
  }
  return -1;

}
int Popstack(Stack *a,char *c)
{
  if (Emptystack(a))
  {
  	*c=a->zifu[a->top--];
  	return 1;
  }
  return -1;
}
int main()
{
  Stack *s;
  s=initstack();
  char b[20];
  char c;
  int flog=0;
  printf("请输入要判断的字符\n");
  scanf("%s",b);
  for(int i=0;b[i]!='\0';i++)
  {
  	Pushstack(s,b[i]);
  }
  for(int j=0;b[j]!='\0';j++)
  {
  	Popstack(s,&c);
  	printf("%c,%c",c,b[j]);
  	if(c==b[j])
  	{   
  		flog=1;
  		continue;
  	}
  	else
  	{  
  	    flog=0;
  		break;
  	}
  }
  if (flog==1){
    printf("yes!");
   }
  else{
  	printf("no!");
  }

}