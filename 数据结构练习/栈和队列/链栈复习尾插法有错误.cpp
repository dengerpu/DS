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
		l->next=p;    //β�巨
		l=p;
		//p->next=l->next;     //ͷ�巨
		//	l->next=p;
	}
	l->next=NULL;
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
void enter_stact(seqstact l,int n)
{
	int x,i=0;
	seqstact p,q;
	p=l->next;
	printf("������Ҫ��ջ��Ԫ��\n");
	scanf("%d",&x);
	while(i<n-1)
	{
		p=p->next ;
		i++;
	}
	q=(seqstact)malloc(sizeof(struct node));
	q->data=x;
	p->next =q;
	p=q;
	/*p->next=l->next;
	l->next =p;*/          //ͷ�巨��
	out_stact(l);
}
void dele_stact(seqstact l)
{
	int i=0;
	seqstact p,q;
	while(i<2)
	{
		p=p->next ;
		i++;
	}	
	q=p->next;
	p->next=NULL;
	free(q);
	out_stact(l);
}
main()
{
	seqstact l;
	l=(seqstact)malloc(sizeof(struct node));
	//	l->next =NULL;    //ͷ�巨��
	creat_stact(l);
	out_stact(l);
	enter_stact(l,3);
	dele_stact(l);
}