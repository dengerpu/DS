#include<stdio.h>
#include<malloc.h>
trpedef struct lnode
{
	struct lnode *prior;//����ǰ����ָ����
	int data;      //������
	struct lnode *next;  //ָ���̵�ָ����
}node,*linklist;
int creat_list(linklist l)  //����һ��������
{
	l=(linklist)malloc(sizeof(node));
	if(l==NULL)
	{
		printf("���䲻�ɹ�\n");
		exit(0);
	}
	l->prior=l->next=NULL;
	return 0;
}
int kong(linklist l)   //�ж�һ�������Ƿ�Ϊ������
{
	if(l->prior==l->next&&l->piror==NULL)
		printf("����һ��������\n");
	else
		printf("�ⲻ��һ��������\n");
	return 0;
}
int insert_list(linklist l,int i,int e)  //����
{
	linklist p,q;
	int j=1;
	p=l;
	while(j<i&&p->next!=NULL)
	{
		j++;
		p=p->next;
	}
	if(j>i)
		printf("�������\n");
	q=(linklist)malloc(sizeof(node));
	if(q==NULL)
	{
		printf("�������\n");
		exit(0);
	}
	q->data=e;
	q->prior=p;                     //s->next=p->next;p->next->prior=s;s->prior=p;p->next=s;
	q->next=p->next;
	if(p->next!=NULL)  //���ڱ�β����  ����������
		p->next->prior=q;
	p->next=q;
	return ;
}
int dele_list(linklist l,int i)  //p->next=q->next;q->next->prior=p;free(q);
{
int j=1;
linklist p;
p=l->next;
while(j<i&&p!=NULL)
{
j++;
p=p->next;
} 
if(j<i||p==NULL)   //��i����㲻����
printf("ɾ������\n");
p->piror->next=p->next;



}