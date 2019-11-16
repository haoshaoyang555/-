#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct yuesefu
{
  int mm;
  int nub;
  struct yuesefu *next;
}node;

int b;

node *creat()//尾插法建立链表
{
  int a, c;
  scanf("%d %d", &a, &b);
  node *pend, *pnew, *head, *tap;
  pnew = (node *)malloc(sizeof(node));
  pend = pnew;
  tap = pnew;
  for (int i = 0; i < a; i++)
  {
    scanf("%d", &c);
    pnew = (node *)malloc(sizeof(node));
    pnew->next = NULL;
    pend->next = pnew;
    pnew->mm = c;
    pnew->nub = i + 1;
    pend = pnew;
  }
  pend->next = tap->next;
  head = pend->next;
  return head;
}
int main()
{
  node *head, *p;
  head = creat();
  int k = b;
  for (p = head->next; p->next != head; p = p->next);
  while (head->next != head)
  {
    for (int i = 1; i < k; i++)
    {
      p = head;
      head = head->next;
    }
    k = head->mm;
    printf("%d ", head->nub);
    p->next = head->next;
    free(head);
    head = p->next;
  }
  printf("%d ", head->nub);
}