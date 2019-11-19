#include<stdio.h>
#define MAXSIZE  X
typedef struct stack
{
  int date[X];
  int top;
}Seqstack;
Seqstack *s;

Seqstack *Init_stack()//置空栈
{
  Seqstack *s;
  s=malloc(sizeof(Seqstack));
  s->top=-1;
  return s;
}


int main()
{




}