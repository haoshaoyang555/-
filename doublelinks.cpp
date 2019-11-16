////无头节点头插法///
#include<stdio.h>
#include<stdlib.h>
typedef struct doublelink
{
  int a;
  struct doublelink *next;
  struct doublelink *prior;
}Doulink;
Doulink *initlink(){
   Doulink *head=NULL;
   Doulink *pnew;
   int aa;
   while(scanf("%d",&aa)&&aa>=0)
   { 
     if (head==NULL)
     {   
     	 pnew=(Doulink *)malloc(sizeof(Doulink));
         head=pnew;
         pnew->a=aa;
         pnew->next=NULL;
     }
     else
     {  
        pnew=(Doulink *)malloc(sizeof(Doulink));
        pnew->a=aa;
        head->prior=pnew;
        pnew->next=head;
        head=pnew;
     }
   }
   printf("结束");
   return head;
}
void display(Doulink *head)
{
  Doulink *temp=head;
  Doulink *pend;
  while(temp)
  {
    printf("%d\n",temp->a);
    pend=temp;
    temp=temp->next;
  }
  printf("////\n");
  while(pend)
  {
     printf("%d\n",pend->a);
     pend=pend->prior;
  }
}
int main()
{  
  Doulink *head;
  head=initlink();
  display(head);
}



