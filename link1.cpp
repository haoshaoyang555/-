////无头节点尾插法///
#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	int a;
	struct link *next;
}link;
link *initlink()
{
  link *head=NULL;
  link *pnew=NULL;
  link *pend;
  int b;
  while(scanf("%d",&b)&&b>=0)
  {
  	if(!pnew)
  	{
     pnew=(link *)malloc(sizeof(link));
     pnew->a=b;
     pnew->next=NULL;
     head=pnew;
     pend=pnew;
    }
     else
     {
     pnew=(link *)malloc(sizeof(link));
     pnew->a=b;
     pend->next=pnew;
     pnew->next=NULL;
     pend=pnew;
     }
  }
   return head;
}
void display(link *head)
{
   link *temp=head;
   while(temp)
   {
     printf("%d\n",temp->a);
     temp=temp->next;

   }
}
int main()
{
  link *head;
  head=initlink();
  display(head);


}


