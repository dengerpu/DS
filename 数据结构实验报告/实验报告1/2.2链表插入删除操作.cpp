#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int date;
	struct node *next;
}Node,Linklist;
void initlist(Linklist *L)           //��ʼ������
{
	L=(Linklist *)malloc(sizeof(struct node));
	L->next=NULL;
}
void creatlist(Linklist *L)        //��������
{
	int n,i,e;
	Linklist *p,*s;
	p=L;
	printf("����������ĳ���\n");
	scanf("%d",&n);
	printf("�����������е�Ԫ��\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		s=(Linklist *)malloc(sizeof(struct node));
		s->date=e;
		p->next=s;
		p=s;
		p->next=NULL;
	}
}
void printlist(Linklist *L)   //�������
{
	Linklist *p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->date);
		p=p->next;
	}
	printf("\n");
}
Linklist * get(Linklist *L,int i) //�������в��ҵ�i��Ԫ��
{
	Linklist *p;int j;
	if(i<0)
	{printf("���Ҳ��Ϸ�");return NULL;}
	p=L;j=0;
	while(p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(i==j)
		return p;
	else
		return NULL;
}
int insertlist(Linklist *L,int i,int e)         //�������
{
	Linklist *p,*s;
	int k;
	if(i<0) return 0;
	p=L;k=0;
	while(p!=NULL&&k<i-1)
	{
		p=p->next;
		k++;
	}
	if(p==NULL)
	{
		printf("����λ�ò��Ϸ�\n");return 0;
	}
	s=(Linklist *)malloc(sizeof(struct node));
	s->date=e;
	s->next=p->next;
	p->next=s;
	return 1;
}
int dellist(Linklist *L,int i,int *e)    //ɾ������
{
	Linklist *p,*s;
	int k;
	p=L;k=0;
	while(p->next!=NULL&&k<i-1)
	{
		p=p->next;k++;
	}
	if(p->next==NULL)
	{
		printf("ɾ������λ��i������");
		return 0;
	}
	s=p->next;
	p->next=s->next;
	*e=s->date;
	free(s);
	return 1;
}
int main()
{
	int i,e;
	Linklist L,*p;
	initlist(&L);
	creatlist(&L);
	printf("����������Ϊ:");
	printlist(&L);
	printf("������Ҫ���������еĵڼ�����\n");
	scanf("%d",&i);
	p=get(&L,i);
	printf("��%d��Ԫ��Ϊ%d\n",i,p->date);
	printf("��������ڵڼ������Լ�Ҫ�����ֵ\n");
	scanf("%d%d",&i,&e);
    insertlist(&L,i,e);
	printf("����������Ϊ:");
	printlist(&L);
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&i);
	dellist(&L,i,&e);
	printf("ɾ���������Ϊ\n");
	printlist(&L);
	return 0;
}
