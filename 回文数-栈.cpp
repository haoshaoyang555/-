#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 10
typedef struct data
{
  int a[max];
  int top;
}data;
/*void initstack(data *a)
{   
     s=(data *)malloc(sizeof(data));
    s->top=-1;
}*/
int pushstack(data *a,int b)
{
  if(a->top==max-1)
  {
      return 0;
  }
  else
  {
    a->a[++a->top]=b;
    return 1;
  }
}
int popstack(data *a,int *b)
{
  if(a->top==-1)
  {
      return 0;
  }
  else
  {
    *b=a->a[a->top--];
    return 1;
  }
}
void judge(data *a,int k[],int m)
{ 
  int b;
  int j=0;
  for(int i=0;i<m;i++)
   {
   	pushstack(a,k[i]);
   //	printf("%d",k[i]);
   //	getchar();
   }
   while(popstack(a,&b))
   { 
     printf("%d",b);
     if(b==k[j])
     {
     	j++;
     	printf("##\n");
     	getchar();
     }
     else
     {
     	return ;
     }

   }

}
int main()
{
    data *s;
    int m[max];
    int n;
    //initstack(s);
    s=(data *)malloc(sizeof(data));
    s->top=-1;
    printf("请输入判断的回文数的长度\n");
    scanf("%d",&n);
    printf("请输入判断的回文数\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
        getchar();
    }
    judge(s,m,n);
    if(s->top==-1)
    {  
        printf("yes\n");
    }
    else
    {
        printf("non");
    }

    
}