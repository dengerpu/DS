#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*seqstact;
void creatstact(seqstact l)
{
	seqstact p;
	int n,i;
	printf("������ջ����\n");
	scanf("%d",&n);
	printf("������ջԪ��\n");
	for(i=0;i<n;i++)
	{
		p=(seqstact)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->next =l->next ;
		l->next =p;
	}
}
void outstact(seqstact l)
{
	seqstact p;
	p=l->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
void insertstact(seqstact l)
{
	seqstact p,s;
	p=l;
	while(p->next !=NULL)
	{
		p=p->next;
	}
	s=(seqstact)malloc(sizeof(struct node));
	s->data=0;
	p->next =s;
	p=s;
	s->next=NULL;
	outstact(l);
}
void deletestact(seqstact l)
{
	seqstact p;
	p=l->next ;
	l->next =p->next ;
	free(p);
	outstact(l);
}
int isempty(seqstact l)
{
	seqstact p;
	p=l->next;
	if(p==NULL)
		return 1;
	else
		return 0;
}
void main()
{
	seqstact l;
	l=(seqstact)malloc(sizeof(struct node));
	l->next =NULL;
	creatstact(l);
	outstact(l);
	insertstact(l);
	deletestact(l);
	if(isempty(l))
		printf("��ջΪ��\n");
	else
		printf("��ջ����\n");
}

