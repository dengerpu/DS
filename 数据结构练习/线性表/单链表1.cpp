#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;  //������
	struct node * next;  //ָ����
}lnode,*linklist;   //lnode�ȼ���struct node    ,*linklist�ȼ��� struct node * ;
linklist creat_list(linklist l)  //��������
{
	int i,n;
	linklist p;
	p=(linklist)malloc(sizeof(lnode));//������һ���������Ч���ݵ�ͷ���
	if(p==NULL)
	{
		printf("����ʧ��\n");
		exit(0);
	}
	printf("����������Ҫ����Ԫ�صĸ���\n");
	scanf("%d",&n);
	printf("������Ԫ��\n");
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		p->next=l->next;
		l->next=p;
	}
	return l;
}
void travese_list(linklist l)
{
	linklist p;
	p=l;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void kong(linklist l)     //�ж������Ƿ�Ϊ��
{
	if(l->next==NULL)
		printf("����Ϊ��");
	else
		printf("������\n");
}
int length_list(linklist l)   //��������
{
	int i=0;
	linklist p;
	p=l;
	while(p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
linklist  sort_list(linklist l,int n)   //��������
{
	int i,j,t;
	linklist p=l,q;
	for(i=0,p=l->next;i<n-1;i++,p=p->next)
		for(j=i+1,q=p->next;j<n;j++,q=q->next)
		{
			if(p->data>q->data)
			{
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
		}
		return l;
}
linklist insert_list(linklist l,int j,int e)   //����
{
	int i=0;
	linklist p=l,s;
	while(p!=NULL&&i<j-1)
	{
		i++;
		p=p->next;
	}
	if(i>j-1||NULL==p)
	{
		printf("�������\n");
		exit(0);
	}
	p=(linklist)malloc(sizeof(lnode));
	if(p==NULL)
	{
		printf("�������\n");
		exit(0);
	}
	p->data=e;
	s->next=p->next;
	p->next=s;
	return l;
}
linklist delete_list(linklist l,int j)   //ɾ��
{
	int i=0;
	linklist p=l,s;
	while(p->next!=NULL&&i<j-1)
	{
		i++;
		p=p->next;
	}
	if(i>j-1||NULL==p->next)
	{
		printf("ɾ������\n");
		exit(0);
	}
	p=(linklist)malloc(sizeof(lnode));
	if(p==NULL)
	{
		printf("�������\n");
		exit(0);
	}
	s=p->next;
	p->next=s->next;
	free(s);
	return l;	
}
int main()
{
	linklist p=NULL,l; //�ȼ���struct node *p=NULL;
	p=creat_list(l);//����һ����ѭ�������������õ������ͷ����ַ����p;
	printf("�������Ԫ��\n");
	travese_list(p);   //����
	kong(l);
	printf("������:%d\n",length_list(l));
	return 0;
}