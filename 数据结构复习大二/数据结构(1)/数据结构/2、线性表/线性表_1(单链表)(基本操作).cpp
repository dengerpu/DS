#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;	/*����Ԫ������Ϊint*/
/*���Ա����ʽ����ṹ����*/
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LNode,* LinkList;
/*���㷨2.9 ͨ��β���뷨������ͷ�ڵ�ĵ�����*/
/*������ͷ�ڵ�ĵ�����L������n��Ԫ�ص�ֵ*/
LinkList Creat_LinkList(int n)
{
	LNode * L,* p,* q;
	int i;
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;	/*�Ƚ���һ������ͷ���ĵ�����*/
	q=L;	/*q�ĳ�ʼֵָ��ͷ�ڵ�*/
	for(i=0;i<=n-1;i++)
	{
		p=(LNode *)malloc(sizeof(LNode));	/*�����½ڵ�*/
		printf("�������%d��Ԫ�ص�ֵ��",i);
		scanf("%d",&p->data);	/*����Ԫ��ֵ*/
		p->next=NULL;	q->next=p;	q=p;	/*���ýڵ���뵽��β*/
	}
	return L;
}
/*��ӡ�����и�Ԫ�ص�ֵ*/
void Print_LinkList(LinkList L)
{
	LNode * p;
	p=L->next;
	printf("\n�������и�Ԫ�ص�ֵΪ��");
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
/*���㷨2.14 ������Ĳ��롿*/
/*�ڴ�ͷ�ڵ�ĵ�����L�еĵ�i��λ��֮ǰ����Ԫ��e��������ɹ����򷵻�1�����򷵻�0*/
int Insert_LinkList(LinkList L,int i,ElemType e)
{
	LNode * p,* s;
	int j;
	p=L;j=-1;
	while(p&&j<i-1)	/*Ѱ�ҵ�i-1���ڵ�*/
	{ 
		p=p->next;
		j++; 
	}	
	if(!p||j>i-1)	
		return 0;	/*iֵ���Ϸ�*/
	s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next; p->next=s;
	return 1;
}
/*���㷨2.15 �������ɾ����*/
/*��ͷ�ڵ�ĵ�����L�У�ɾ����i��Ԫ�أ�����e������ֵ����ɾ���ɹ����򷵻�1�����򷵻�0*/
int Delete_LinkList(LinkList L,int i,ElemType * e)
{
	LNode * p,* q;
	int j;
	p=L; j=0;
	while(p->next&&j<i-1) /*Ѱ�ҵ�i���ڵ㣬����pָ����ǰ��*/
	{
		p=p->next; 
		j++;
	}	
	if(!(p->next)||j>i-1) 
		return 0;	/*ɾ��λ�ò�����*/
	q=p->next;
	* e=q->data;	/*��e���ر�ɾ�ڵ��������ֵ*/
	p->next=q->next; 
	free(q);	/*ɾ�����ͷŽڵ�*/
	return 1;
}
/*���㷨2.13 ������İ�ֵ���ҡ�*/
/*�ڴ�ͷ�ڵ�ĵ�����L�в��������ֵ��ͬ��Ԫ�ص�λ��*/
int Locate_LinkElem(LinkList L,ElemType e)
{
	LNode * p;
	int i;
	p=L->next; i=0;
	while(p!=NULL&&p->data!=e) 
	{ 
		p=p->next; 
		i++;
	}
	if(p->data!=e) 
		return -1;
	else 
		return i;
}
int main()
{
	LinkList L;	/*����һ��ͷָ�룬��ָʾһ��������*/
	int n,i,e,status;
	printf("�����뵥����ĳ��ȣ�n=");
	scanf("%d",&n);
	L=Creat_LinkList(n);	/*����һ����n��Ԫ�صĵ�����*/
	Print_LinkList(L);	/*����������Ա��Ԫ�ص�ֵ*/
	status=Insert_LinkList(L,4,27);	/*�ڵ�4��Ԫ��֮ǰ����ֵ27*/
	if(status) 
	{ 
		printf("\n\n���в��������"); 
		Print_LinkList(L);
	}
	else 
	{
		printf("\n����ʧ�ܣ�");
		return 0;
	}
	status=Delete_LinkList(L,5,&e);
	if(status)
	{
		printf("\n\n��ɾ����Ԫ�ص�ֵΪ��%d",e);
		printf("\n\n����ɾ��������");
		Print_LinkList(L);
	}
	else 
	{ 
		printf("\nɾ��ʧ�ܣ�"); 
		return 0;
	}
	printf("\n\n������Ҫ���ҵ�ֵ��e=");
	scanf("%d",&e);
	i=Locate_LinkElem(L,e);
	if(i>=0) 
		printf("��Ԫ�������Ա��е�λ��Ϊ��%d\n",i);
	else 
		printf("��Ԫ�������Ա��в�����\n");
	return 0;
}