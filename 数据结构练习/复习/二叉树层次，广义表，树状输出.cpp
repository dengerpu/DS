#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creat()   //创建二叉树
{
	bitree root;
	char ch;
	ch=getchar();
	if(ch=='0')root=NULL;
	else
	{
		root=(bitree)malloc(sizeof(struct node));
		root->data=ch;
		root->lchild=creat();
		root->rchild=creat();
	}
	return root;
} 
void list(bitree root)   //以广义表形式输出
{
	if(root==NULL) return;
	else
	{
		printf("%c",root->data);
		if(root->lchild!=NULL||root->rchild!=NULL)
			printf("(");
		list(root->lchild);
		if(root->rchild!=NULL)
			printf(",");
		list(root->rchild);
		printf(")");
	}
}
void print1(bitree root ,int n)  //按树状打印
{
	if(root==NULL)return;
	else
	{
		print1(root->rchild,n+1);
		for(int i=0;i<n;i++)
			printf("	");
		printf("%c\n",root->data);
		print1(root->lchild,n+1);
	}
}
void print(bitree root)   //按照层次打印
{
	bitree queue[100];
	int front,rear;
	front=-1;
	rear=0;
	queue[rear]=root;
	while(front!=rear)
	{
		front++;
		printf("%c",queue[front]->data);
		if(queue[front]->lchild!=NULL)
		{
			rear++;
			queue[rear]=queue[front]->lchild;
		}
		if(queue[front]->rchild!=NULL)
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
	list(root);
	printf("\n");
	print1(root,0);
	print(root);
}