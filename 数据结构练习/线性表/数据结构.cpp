//ͷ���-���׽��-��-��-��β���  ��ͷ������ã�������������������Ч���ݡ���
//ͷָ�룺ָ��ͷ����ָ�����
//βָ�룺ָ��β����ָ���
#include<stdio.h>
typedef struct lnode
{
int data; //������
struct lnode *next; //ָ����
}node ,*linklist;  //node�ȼ���struct lnode ,linklist�ȼ���struct lnode *;
//Ҫ����һ��qָ�룻
1.
r=p->next;    //д��һ
p->next=q;
q->next=r;
2.
q->next=p->next;   //д����
p->next=q;

