//ABDG00H000CE0I00F00
#include<stdio.h>
#include<malloc.h>
int count=0,leafcount,depth=0,h=1,hl,hr,max=0;
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
		root->data=ch;
		root->lchild=creat();
		root->rchild=creat();
	}
	return root;
}
void preorder(bitree root)  //先序遍历输出
{
	if(root==NULL)return;
	else
	{
		printf("%3c",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void inorder(bitree root)      //中序遍历输出
{
	if(root==NULL)return;
	else
	{
		inorder(root->lchild );	
		printf("%3c",root->data );
		inorder(root->rchild );
	}
}
void postorder(bitree root)   //后序遍历输出
{
	if(root==NULL)return;
	else
	{
		preorder(root->lchild );
		preorder(root->rchild );
		printf("%3c",root->data );
	}
}
void yzjd(bitree root)        //输出叶子结点
{
	if(root==NULL) return;
	else
	{
		yzjd(root->lchild );
		yzjd(root->rchild );
		if(root->lchild ==NULL&&root->rchild ==NULL)
			printf("%3c",root->data );	
	}		
}
void  shumu1(bitree root)        //输出叶子结点数目方法一
{
	if(root!=NULL)
	{
		shumu1(root->lchild );
		shumu1(root->rchild );
		if(root->lchild ==NULL&&root->rchild ==NULL)
			count++;
	}
}
int shumu2(bitree root)          //输出叶子结点数目方法二
{
	if(root==NULL)
		leafcount=0;
	else if(root->lchild ==NULL&&root->rchild ==NULL)
		leafcount=1;
	else
		leafcount=shumu2(root->lchild )+shumu2(root->rchild );
	return leafcount;
}
int depth1(bitree root,int h)      //求树的深度1
{
	if(root!=NULL)
	{
		if(depth<h)depth=h;
		depth1(root->lchild ,h+1);
		depth1(root->rchild ,h+1);
	}
	return depth;
}
int depth2(bitree root)      //求树的深度2
{
	if(root!=NULL)
	{
		hl=depth2(root->lchild);
		hr=depth2(root->rchild );
		max=hl>hr?hl:hr;
		return (max+1);
	}
	else
		return 0;
}
void print(bitree root,int n)   //按照树状打印
{
	if(root!=NULL)
	{
		print(root->rchild ,n+1);
		for(int i=0;i<n;i++)
			printf("   ");
		printf("%c\n",root->data );
		print(root->lchild ,n+1);
	}
}
void print1(bitree root)  //按照层次输出
{
	bitree queue[100];
	int front=-1,rear=0;
	if(root==NULL) return;
	queue[rear]=root;
	while(front!=rear)
	{
		front++;
		printf("%3c",queue[front]->data);
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
void list(bitree root)   //以广义表形式输出
{
	if(root==NULL)return;
	else
	{
		printf("%c",root->data );
		if(root->lchild!=NULL||root->rchild !=NULL)
			printf("(");
		list(root->lchild );
		if(root->rchild !=NULL)
			printf(",");
		list(root->rchild );
		printf(")");
	}
}
int like(bitree t1,bitree t2)
{
	int like1,like2;
	if(t1==NULL&&t2==NULL)
		return 1;
	else if(t1==NULL||t2==NULL)
		return 0;
	else
	{
		like1=like(t1->lchild ,t2->lchild );
		like2=like(t1->rchild,t2->rchild );
		return (like1&&like2);
	}
}
void main()
{
	bitree root;
	printf("请输入\n");
	root=creat();
	printf("以广义表形式输出\n");
	list(root);
	printf("\n先序遍历输出为:\n");
	preorder(root);
	printf("\n中序遍历输出为:\n");
	inorder(root);
	printf("\n后序遍历输出为：\n");
	preorder(root);
	printf("\n输出叶子结点\n");
	yzjd(root);
	shumu1(root);
	printf("\n叶子结点数目：%d\n",count);
	printf("\n叶子结点数目：%d\n",shumu2(root));
	printf("\n树的深度为%d\n",depth1(root,h));
	printf("\n树的深度为%d\n",depth2(root));
	printf("以树状输出\n");
	print(root,0);
	print1(root);
	if(like(root,root))
		printf("相似\n");
	else
		printf("不相似\n");
}	