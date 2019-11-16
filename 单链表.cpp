#include <stdio.h>
#include <stdlib.h>
#include <cstring>

typedef struct node{
	int data;
	struct node *next;
}ElemSN;

void CreatList(ElemSN **pHead);              //建立单链表
void InsertListHead(ElemSN *pHead,int data); //头插法
void InsertListTail(ElemSN *pHead,int data); //尾插法
void DelData(ElemSN *pHead,int data);        //删除节点
ElemSN *FindData(ElemSN *pHead,int data);    //查找
void Print(ElemSN *pHead);                   //输出
void DistoryList(ElemSN **pHead);            //销毁链表

int main() {
	ElemSN *pHead;
	CreatList(&pHead);
	InsertListTail(pHead,1);
	InsertListTail(pHead,2);
	InsertListTail(pHead,3);
	InsertListTail(pHead,4);
	InsertListTail(pHead,5);
	DelData(pHead,6);
	//printf("%d\n",FindData(pHead,5)->data);
	Print(pHead);
	DistoryList(&pHead);
	Print(pHead);
	return 0;
}

void DistoryList(ElemSN **pHead) {
	while(*pHead) {
		ElemSN *p=(*pHead)->next;
		free(*pHead);
		*pHead=p;
	}
}

void DelData(ElemSN *pHead,int data) {
	ElemSN *p;
	if(!(p=FindData(pHead,data))) return;
	while(pHead->next!=p) pHead=pHead->next;
	pHead->next=p->next;
	free(p);
}

ElemSN *FindData(ElemSN *pHead,int data) {
	pHead=pHead->next;
	while(pHead&&pHead->data!=data) pHead=pHead->next;
	return pHead;
}

void CreatList(ElemSN **pHead) {
	(*pHead)=(ElemSN *)malloc(sizeof(ElemSN));
	(*pHead)->next=NULL;
}

void InsertListHead(ElemSN *pHead,int data) {
	ElemSN *pNew=(ElemSN *)malloc(sizeof(ElemSN));
	pNew->data=data;
	pNew->next=pHead->next;
	pHead->next=pNew;
}

void InsertListTail(ElemSN *pHead,int data) {
	ElemSN *pNew=(ElemSN *)malloc(sizeof(ElemSN));
	while(pHead->next) pHead=pHead->next;
	pNew->data=data;
	pNew->next=NULL;
	pHead->next=pNew;
}

void Print(ElemSN *pHead) {
	if(!pHead) return;
	for(pHead=pHead->next;pHead;pHead=pHead->next) 
		printf("%d ",pHead->data);
}