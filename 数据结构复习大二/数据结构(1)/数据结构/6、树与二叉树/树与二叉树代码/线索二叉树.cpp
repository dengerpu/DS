#include "stdio.h"											//**************************************//
#include "stdlib.h"											//
typedef struct node											//�ô��밴����ʾ���ģ�����ȫ����������������
{															//���е�覴ã���֪�����ġ�//ע�������ϵĴ��룬���������㷢�����������
	int ltag,rtag;											//
	char data;												//**************************************//
	struct node * lchild;
	struct node * rchild;
}bitnode,* bitree;
bitree p;
bitree pre=NULL;
bitree creat()												//����
{
	bitree t;
	char e;
	scanf("%c",&e);
	if(e=='.')
		t=NULL;
	else
	{
		t=(bitree)malloc(sizeof(bitnode));												
		t->data=e;
		t->lchild=creat();
		t->rchild=creat();
	}
	return t;
}
void inthread(bitree p)										//������
{
	if(p)
	{
		p->ltag=0;
		p->rtag=0;
		inthread(p->lchild);
		if(p->lchild == NULL)
		{
			p->ltag=1;
			p->lchild=pre;
		}
		if(pre && pre->rchild == NULL)
		{
			pre->rtag=1;
			pre->rchild=p;
		}
		pre=p;
		inthread(p->rchild);
	}
}
bitree inpre(bitree p)											//ǰ��
{
	bitree q,k;
	if(p->ltag==1)
		k=p->lchild;
	else
	{
		for(q=p->lchild;q->rtag==0;q=q->rchild)
			k=q;
	}
	return k;
}
bitree innext(bitree p)											//���
{
	bitree k,q;
	if(p->rtag==1)
		k=p->rchild;
	else
	{
		for(q=p->rchild;q->ltag==0;q=q->lchild);
			k=q;
	}
	return k;
}
bitree infirst(bitree p)									//���innext  �����tinorder
{
	bitree k=p;
	if(!k) return NULL;
	while(k->ltag==0)
		k=k->lchild;
	return k;
}
void tinorder(bitree p)
{
	bitree k;
	k=infirst(p);					//����infirst
	while(k)
	{
		printf("%c",k->data);
		k=inpre(k);				//����innext			�����inpreҪ�Լ���һ��inlast�Ӻ��濪ʼ������ǰ����
	}
}
void main()
{
	p=creat();
	inthread(p);
	tinorder(p);
}