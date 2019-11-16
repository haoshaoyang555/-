////无头节点头插法////
#include<stdio.h>
#include<stdlib.h>
typedef struct a1
{
  int a;
  struct a1 *next;
}sta;
sta *save()
{
   sta *head=NULL;
   sta *pnew;
   int a;

   while(scanf("%d",&a)&&a>0)
   {
    pnew=(sta *)malloc(sizeof(sta));
    pnew->a=a;
   	if(!head) {
   		head=pnew;
   		pnew->next=NULL;
   	}
    else{
    	pnew->next=head;
    	head=pnew;         
	}

   }
   return head;

}
void show(sta *a1)
{
  sta *temp=a1;
  while(temp!=NULL)
  {
    printf("%d\n",temp->a);
    temp=temp->next;

  }
   printf("结束\n");
}
void delet(sta *a,int m,int n)
{
  sta *temp=a;
  sta *end=temp;
  m=m-1;
  while(m--)
  {
    end=temp;
    temp=temp->next;
  }
  while(n--)
  {
    temp=temp->next;
    free(temp);
  }
  if (temp->next==NULL)
    {
     end->next=NULL;
    }
  else
 {
  end->next=temp;
  }
}
void insert(sta *head1,sta *head,int k)
{
  sta *lb=head1;
  sta *la=head;
  sta *laa=la;
  sta *end=lb;
  while(k--)
  { 
    end=lb;
    lb=lb->next;
  }
  while(la->next!=NULL)
  {
    la=la->next;
  }
   la->next=lb ;
   end->next=laa;
}
int main()
{    sta *head;
     sta *head1;
	 head=save();
   head1=save();
     show(head);
     show(head1);
     int m,n,k;
     printf("输入要删除的位置，长度\n");
     scanf("%d,%d",&m,&n);
     delet(head,m,n);
     show(head);
     printf("输入要插入的位置\n");
     scanf("%d",&k);
     insert(head1,head,k);
     show(head1);

}