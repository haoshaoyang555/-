#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}ElemSN;

void CreatList(ElemSN **pHead);
void InsertListHead(ElemSN **pHead,int data);
void InsertListTail(ElemSN **pHead,int data);
void DelData(ElemSN **pHead,int data);
ElemSN *FindData(ElemSN *pHead,int data);
void Print(ElemSN *pHead);
void DistoryList(ElemSN **pHead);

int main() {
	ElemSN *pHead;
	CreatList(&pHead);
	InsertListTail(&pHead,1);
	InsertListTail(&pHead,2);
	InsertListTail(&pHead,3);
	InsertListTail(&pHead,4);
	InsertListTail(&pHead,5);
	DelData(&pHead,1);
	//cout<<FindData(pHead,5)->data;
	DistoryList(&pHead);
	Print(pHead);
	return 0;
}

void CreatList(ElemSN **pHead) {
	*pHead=NULL;
}

void InsertListHead(ElemSN **pHead,int data) {
	ElemSN *pNew=(ElemSN *)malloc(sizeof(ElemSN));
	pNew->data=data;
	if(*pHead) {
		pNew->next=*pHead;
		*pHead=pNew;
	} else {
		*pHead=pNew;
		pNew->next=NULL;
	}
}

void InsertListTail(ElemSN **pHead,int data) {
	ElemSN *pNew=(ElemSN *)malloc(sizeof(ElemSN));
	pNew->data=data;
	pNew->next=NULL;
	if(*pHead) {
		ElemSN *p=*pHead;
		while(p->next) p=p->next;
		p->next=pNew;
	} else {
		*pHead=pNew;
	}
}

void DelData(ElemSN **pHead,int data) {
	ElemSN *p;
	if(!(p=FindData(*pHead,data))) return;
	if(p==*pHead) *pHead=p->next;
	else {
		ElemSN *t=*pHead;
		while(t->next!=p) t=t->next;
		t->next=p->next;
	}
	free(p);
}

ElemSN *FindData(ElemSN *pHead,int data) {
	while(pHead&&pHead->data!=data) pHead=pHead->next;
	return pHead;
}

void Print(ElemSN *pHead) {
	while(pHead) {
		printf("%d ",pHead->data);
		pHead=pHead->next;
	}
}

void DistoryList(ElemSN **pHead) {
	while(*pHead) {
		ElemSN *t=(*pHead)->next;
		free(*pHead);
		*pHead=t;
	}
}