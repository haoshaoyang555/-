#include<stdio.h>
#include<stdlib.h>
typedef struct brackets_stack
{
  char a;
  struct brackets_stack *next;
}Brackets;
Brackets *s;
void init()
{
  s=(Brackets *)malloc(sizeof(Brackets));
  s->next=NULL;
}
void Pushstack(char b)
{   
	Brackets *pnew;
    pnew=(Brackets *)malloc(sizeof(Brackets));
    pnew->a=b;
    pnew->next=s->next;
    s->next=pnew;
}
int pop(char *c)
{  
   if(s->next==NULL)
   {
   	*c='1';
   	return -1;
   } 
   else
   {
    Brackets *temp=s->next;
    *c=temp->a;
    s->next=temp->next;
    free(temp);
    return 1 ; 
    }

}
int main()
{
  char c[10];
  int flog;
  scanf("%s",c);
  init();
  for(int i=0;c[i]!='\0';i++)
  {
   if (c[i]=='(')
   {
     Pushstack(c[i]);
   }
   else
   {
  	 char b;
  	 pop(&b);
  	 printf("%c",b);
     if(b=='(')
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
}
 if(flog==1&&s->next==NULL)
 {
 	printf("yes");
 }
 else
 {
 	printf("no");
 }



}