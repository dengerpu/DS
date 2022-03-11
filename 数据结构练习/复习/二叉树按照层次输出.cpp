#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creat()
{
	bitree root;
	char ch;
	ch=getchar();
	if(ch=='0')root=NULL;
	else
	{
		root=(bitree)malloc(sizeof(struct node));
		root->data =ch;
		root->lchild =creat();
		root->rchild =creat();
	}
	return(root);
}
void print(bitree root)
{
	bitree queue[100];
	int front,rear;
	if(root==NULL) return;
	front=-1;
	rear=0;
	queue[rear]=root;
	while(front!=rear)
	{
		front++;
		printf("%c",queue[front]->data );
		if(queue[front]->lchild !=NULL)
		{
			rear++;
			queue[rear]=queue[front]->lchild ;
		}
		if(queue[front]->rchild !=NULL)
		{
			rear++;
			queue[rear]=queue[front]->rchild;
		}
	}
	printf("\n");
}
void main()
{
	bitree root;
	root=creat();
	print(root);
}