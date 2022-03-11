#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}*linkstact;
int push(linkstact top)    //进栈
{
	int x;
	printf("请输入要进栈的元素\n");
	scanf("%d",&x);
	linkstact temp;
	temp=(linkstact)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("分配失败\n");
		return 0;
	}
	temp->data=x;
temp->next=top->next;
top->next=temp;
	return 1;
}
int pop(linkstact top)  //出栈
{
	linkstact temp;
	temp=(linkstact)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("栈为空\n");
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
	printf("请输入栈长度\n");
	scanf("%d",&n);
	printf("请输入栈元素\n");
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
	printf("输出\n");
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