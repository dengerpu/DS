#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*linkstact;
int push(linkstact top)    //��ջ
{
	int x;
	printf("������Ҫ��ջ��Ԫ��\n");
	scanf("%d",&x);
	linkstact temp;
	temp=(linkstact)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("����ʧ��\n");
		return 0;
	}
	temp->data=x;
temp->next=top->next;
top->next=temp;
	return 1;
}
int pop(linkstact top)  //��ջ
{
	linkstact temp;
	temp=(linkstact)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("ջΪ��\n");
		return 0;
	}
	temp=top->next;
	top->next=temp->next;
	free(temp);
	return 1;
}
void creat_stact(linkstact l)
{
	int i,n,t;
	linkstact p;
	p=l;
	printf("������ջ����\n");
	scanf("%d",&n);
	printf("������ջԪ��\n");
	for(i=0;i<n;i++)
	{
		p=(linkstact)malloc(sizeof(struct node));
		scanf("%d",&t);
		p->data=t;
		p->next=l->next;
		l->next=p;
	}
}
void out_stact(linkstact l)
{
	printf("���\n");
	linkstact p;
	p=l;
	while(p->next!=NULL)
	{
		printf("%d ",p->next->data);
		p=p->next;
	}
	printf("\n");
}
void main()
{
	linkstact l;
	l=(linkstact)malloc(sizeof(struct node));
	l->next=NULL;
	creat_stact(l);
	out_stact(l);
	push(l);
	out_stact(l);
	pop(l);
	out_stact(l);

}