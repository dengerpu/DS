#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*seqstact;
void creat_stact(seqstact l)
{
	int i,n;
	seqstact p;
	printf("��������ջ��Ԫ�ظ���\n");
	scanf("%d",&n);
	printf("������Ԫ��\n");
	for(i=0;i<n;i++)
	{
		p=(seqstact)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		//l->next=p;    //β�巨
		//l=p;
		p->next=l->next;     //ͷ�巨
		l->next=p;
	}
	//l->next=NULL;
}
void out_stact(seqstact l)
{
	printf("���\n");
	seqstact p;
	p=l->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void enter_stact(seqstact l)
{
	int x;
	seqstact p;
	p=l;
	printf("������Ҫ��ջ��Ԫ��\n");
	scanf("%d",&x);
	p=(seqstact)malloc(sizeof(struct node));
	p->data=x;
	p->next=l->next;
	l->next =p;
	out_stact(l);
}
void dele_stact(seqstact l)
{
	seqstact p;
	p=l->next;
	l->next=p->next ;
	free(p);
	out_stact(l);
}
main()
{
	seqstact l;
	l=(seqstact)malloc(sizeof(struct node));
	l->next =NULL;
	creat_stact(l);
	out_stact(l);
	enter_stact(l);
	dele_stact(l);
}