#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	int date;
	struct node *next;
}lnode,*linklist;
linklist creat_list(linklist L)   //��������
{
	linklist p;
	int i,n,t;
	printf("������������\n");
	scanf("%d",&n);
	printf("����������Ԫ��\n");
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&t);
		p->date=t;
		//L->next=p;
		//L=p;
		p->next=L->next;
		L->next=p;
	}
	//L->next=NULL;
	return 0;
}
void out_list(linklist L)   //�������
{
	printf("���\n");
	linklist p;
	p=L;
	while(p->next!=NULL)
	{
		printf("%d ",p->next->date);
		p=p->next;	
	}
	printf("\n");
}
void insert_list(linklist L)   //����
{
	int i,n,j=0;
	linklist p,s;
	p=L;
	
	printf("������Ҫ���ڵڼ������Լ�Ҫ�������\n");
	scanf("%d%d",&i,&n);
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i-1||p==NULL)
	{
		printf("�������\n");
		exit(0);
	}
	s=(linklist)malloc(sizeof(lnode));
	s->date=n;
	s->next=p->next;
	p->next=s;
	out_list(L);
}
void dele_list(linklist L)   //ɾ��
{
	int i,j=0;
	linklist p,q;
	p=L;
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&i);
	while(j<i-1&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i-1||p==NULL)
	{
		printf("ɾ������\n");
		exit(0);
	}
	q=p->next;
	p->next=q->next;
	free(q);
	out_list(L);	
}
void loc_list(linklist L)  //����Ų���
{
	int i,j=0,k;linklist p;
	printf("������Ҫ���ҵڼ�����\n");
	p=L;
	scanf("%d",&i);
	while(j<i&&p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(j>i||p==NULL||j<=0)
	{
		printf("���Ҵ���\n");
		exit(0);
	}
	k=p->date;
	printf("��%d����Ϊ%d\n",i,k);
}
void loc1_list(linklist L)   //����ֵ����
{
	int j=0,k;
	linklist p;
	p=L;
	printf("��������Ҫ���ҵ���ֵ\n");
	scanf("%d",&k);
	while(p!=NULL&&p->date!=k)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)
	{
		printf("����ʧ��\n");
		exit(0);
	}
	printf("%dΪ��%d����\n",k,j);
}
void length_list(linklist L)  //������
{
	linklist p;
	p=L;
	int i=0;
	while(p->next!=NULL)
	{
		p=p->next;
		i++;
	}
	printf("������Ϊ%d\n",i);
}
void main()
{
	linklist L;
	L=(linklist)malloc(sizeof(lnode));
	creat_list(L);
	out_list(L);
	//length_list(L);
	insert_list(L);
	//dele_list(L);
	//loc_list(L);
	//loc1_list(L);
}