#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct yuesefu
{
    int mm;
    struct yuesefu *next;
}node;
node *creat()//头插法建立链表
{
    node *pend,*pnew,*tap;
    pnew=(node *)malloc(sizeof(node));
    pnew->next=NULL;
    pend=pnew;
    int a;
    int b=1;
    printf("请输入密码\n");
    while(scanf("%d",&a) && a!=0)
    {
      getchar();
      pnew=(node *)malloc(sizeof(node));
      if(b==1)
      {  
       pnew->mm=a;
       pnew->next=pend->next;
       pend->next=pnew;
       tap=pnew;
       b--;
       printf("请输入密码,0结束\n");
      }
     else{
       pnew->mm=a;
       pnew->next=pend->next;
       pend->next=pnew;
       printf("请输入密码,0结束\n");
     }
    }
    getchar();
    tap->next=pend->next;
    node *head;
    head=pend->next;
    return head;
}
int main()
{
  node *head,*p;
  head=creat();
  int k;
  printf("请输入第一次的密码\n");
  scanf("%d",&k);
  getchar();
  int n[]
  while(head->next!=head)
  {
     for(int i=1;i<k;i++)
     {  
     	p=head;
     	head=head->next;
     }
     k=head->mm;
     printf("%d",k);
     p->next=head->next;
     free(head);
     head=p->next;
  }  
  printf("%d",head->mm);
}