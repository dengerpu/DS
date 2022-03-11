#include<stdio.h>
#include<malloc.h>
typedef struct stact
{
	int data;
	struct stact *next;
}*seqstact;
void creat_stact(seqstact l)
{
	seqstact p;
	p=l;
	int i,n;
	printf("请输入栈长度\n");
	scanf("%d",&n);
	printf("请输入元素\n");
	for(i=0;i<n;i++)
	{
		p=(seqstact)malloc(sizeof(struct stact));
		scanf("%d",&p->data);
		l->next=p;
		l=p;
		//	p->next=l->next;
		//	l->next=p;
	}
	l->next=NULL;
}
void out_stact(seqstact l)
{
	printf("输出\n");
	seqstact p;
	p=l;
	while(p->next!=NULL)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
	printf("\n");
}
void insert_stact(seqstact l)
{
	seqstact q;
	int i;
	q=(seqstact)malloc(sizeof(struct stact));
	printf("请输入要进栈的元素\n");
	scanf("%d",&i);
	l->next=q;
	l=q;
}
void main()
{
	seqstact l;
	l=(seqstact)malloc(sizeof(struct stact));
	creat_stact(l);
	out_stact(l);
	insert_stact(l);
	out_stact(l);
}