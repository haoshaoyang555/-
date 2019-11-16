////无头节点尾插法///
#include<stdio.h>
#include<stdlib.h>
typedef struct doublelinks
{
  int a;
  struct doublelinks *next;
  struct doublelinks *prior;
}Doblinks;
Doblinks *initlinks()
{
   Doblinks *head=NULL;
   Doblinks *pnew,*pend;
   int b;
   while(scanf("%d",&b)&&b>0)
   {
     if(!head)
     {
      pnew=(Doblinks *)malloc(sizeof(Doblinks));
      pnew->a=b;
      pnew->next=NULL;
      head=pnew;
      pend=pnew;
     }
     else
     {
      pnew=(Doblinks *)malloc(sizeof(Doblinks));
      pnew->a=b;
      pnew->next=NULL;
      pnew->prior=pend;
      pend->next=pnew;
      pend=pnew;
     }
   }
     return head;
}
void display(Doblinks *head)
{
 Doblinks *temp=head;
 Doblinks *pend;
 while(temp)
 {
   printf("%d\n",temp->a);
   pend=temp;
   temp=temp->next;
 }
 printf("结束\n");
 while(pend)
 {
   printf("%d\n",pend->a);
   pend=pend->prior;
 }
}
int main()
{
  Doblinks *head;
  head=initlinks();
  display(head);


}