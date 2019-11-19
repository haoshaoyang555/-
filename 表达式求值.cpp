#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 10
typedef struct suanshu
{
  char ch;
  int sh;
}suanshu;
suanshu *a;
typedef struct fuhao
{
  suanshu a[max];
  int top;
}fuhao;
typedef struct shuzi
{
	suanshu b[max];
	int top;
}shuzi;
fuhao *inintstack()
{
  fuhao *f;
  f=(fuhao *)malloc(sizeof(fuhao));
  f->top=-1;
  return f;
}
shuzi *initstack2()
{
  shuzi *s;
  s=(shuzi *)malloc(sizeof(shuzi));
  s->top=-1;
  return s;
}
int fuhaopop(fuhao *f,suanshu *a)
{
  if(f->top==max-1)
  {
  	printf("栈满\n");
  	return 0;
  }
  else
  {
    f->a[f->top++].ch=a->ch;
    return 1;
  }
}
int shuzipop(shuzi *s,suanshu *a)
{
  if(s->top==max-1)
  {
  	printf("栈满\n");
  	return 0;
  }
  else
  {
    s->b[s->top++].sh=a->sh;
    return 1;
  }
}
int fuhaopush(fuhao *f,suanshu *a)
{
  if(f->top==-1)
  {
  	printf("栈空\n");
  	return 0;
  }
  else
  {
    a->ch=f->a[f->top--].ch;
    return 1;
  }

}
int shuzipush(shuzi *s,suanshu *a)
{
  if(s->top==-1)
  {
  	printf("栈空\n");
  	return 0;
  }
  else
  {
    a->sh=s->b[s->top--].sh;
    return 1;
  }
}
int main()
{
  fuhao *f;
  shuzi *s;
  char word[10];
  a=(suanshu *)malloc(sizeof(suanshu));
  f=inintstack();
  s=initstack2();
  gets(word);
  puts(word);
  



}
 