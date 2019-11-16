/////无节点双向循环列表尾插法//////
#include<stdio.h>
#include<stdlib.h>
typedef struct doublecirclelinks
{
	int a;
	struct doublecirclelinks *next;
	struct doublecirclelinks *prior;
}DouCirlinks;
DouCirlinks *inintlinks()
{
  DouCirlinks *head=NULL;
  DouCirlinks *pnew;
  int b;
  while(scanf("%d",&b)&&b>0)
  {
   if (!head)
   {  
   	////初始化第一个节点,前后指针都先指向自身///
      pnew=(DouCirlinks *)malloc(sizeof(DouCirlinks));
      pnew->a=b;
      pnew->next=pnew;
      pnew->prior=pnew;
      head=pnew;
   }
   else
   {
    pnew=(DouCirlinks *)malloc(sizeof(DouCirlinks));
    pnew->a=b; 
   
    pnew->prior=head->prior;
    head->prior->next=pnew;
    pnew->next=head;
    /////改变原来的一定放后面///
    head->prior=pnew;
    head=pnew;
   }
  }
  return head;
}
void display(DouCirlinks *head)
{ 
   DouCirlinks *temp=head;
   int b=10;
   while(b--)
   {
     printf("%d\n",temp->a);
     temp=temp->next;
   }

}
int main()
{
  DouCirlinks *head;
  head=inintlinks();
  display(head);




}