//ABDG00H000CE0I00F00
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creat()     //创建二叉树
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
void print(bitree root,int n)   //按树状逆时针90度打印二叉树
{
	if(root==NULL)return;
	else
	{
		print(root->rchild,n+1);
		for(int i=0;i<n;i++)
			printf("   ");
		printf("%c\n",root->data);
		print(root->lchild,n+1);
	}
}
void list(bitree root)  //广义表形式打印二叉树
{
	if(root==NULL)return;
	else
	{
		printf("%c",root->data );
		if(root->lchild !=NULL||root->rchild !=NULL)
			printf("(");
		list(root->lchild );
		if(root->rchild !=NULL)
			printf(",");
		list(root->rchild );
		printf(")");
	}
}
void print1(bitree root)  //按层次打印二叉树
{
	bitree queue[100];
	int front,rear;
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
			queue[rear]=queue[front]->rchild ;
		}
	}
	printf("\n");
}
void main()
{
	bitree root;
	root=creat();
	printf("以广义表形式输出：\n");
	list(root);
	printf("\n树状输出：\n");
	print(root,0);
	printf("层次输出为:\n");
	print1(root);
}