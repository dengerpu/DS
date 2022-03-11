#include<stdio.h>
#include<malloc.h>
int hl,hr,max,leafcount,count=0;int h=1,depth=0;
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
bitree creatbitree()   //���򴴽�������
{
	bitree root;
	char ch;
	ch=getchar();
	if(ch=='0')root=NULL;
	else
	{
		root=(bitree)malloc(sizeof(struct node));
		root->data=ch;
		root->lchild=creatbitree();
		root->rchild=creatbitree();
	}
	return root;
} 
void listbitree(bitree root)   //�������ʽ���
{
	if(root!=NULL)
	{
		printf("%c",root->data );
		if(root->lchild !=NULL||root->rchild !=NULL)
			printf("(");
		listbitree(root->lchild );
		if(root->rchild !=NULL)
			printf(",");
		listbitree(root->rchild );
		printf(")");
	}
}
void preorder(bitree root)   //����������
{
	if(root!=NULL)
	{
		printf("%3c",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void inorder(bitree root)   //����������
{
	if(root!=NULL)
	{
		inorder(root->lchild );
		printf("%3c",root->data );
		inorder(root->rchild );
	}
}
void postorder(bitree root)  //����������
{
	if(root!=NULL)
	{
		postorder(root->lchild );
		postorder(root->rchild );
		printf("%3c",root->data );
	}
}
void yezijiedian(bitree root)  //���Ҷ�ӽ����Ŀ
{
	if(root!=NULL)
	{
		yezijiedian(root->lchild );
		yezijiedian(root->rchild );
		if(root->lchild ==NULL&&root->rchild ==NULL)
			printf("%3c",root->data );
	}
}
int yezijiedianshumu(bitree root)   //��Ҷ�ӽ����Ŀ����1
{
	if(root==NULL)
		leafcount=0;
	else if(root->lchild ==NULL&&root->rchild ==NULL)
		leafcount=1;
	else
		leafcount=yezijiedianshumu(root->lchild )+yezijiedianshumu(root->rchild );
	return leafcount;
}
void yezijiedianshumu1(bitree root)  //��Ҷ�ӽ����Ŀ����2
{
	if(root!=NULL)
	{
		yezijiedianshumu(root->lchild );
		yezijiedianshumu(root->rchild );
		if(root->lchild ==NULL&&root->rchild ==NULL)
			count++;
	}
	
}
int depth1(bitree root)  //������ȷ���һ
{
	if(root!=NULL)
	{
		hl=yezijiedianshumu(root->lchild );
		hr=yezijiedianshumu(root->rchild );
		max=hl>hr?hl:hr;
		return (max+1);
	}
	else return (0);
}
void depth2(bitree root,int h)  //������ȷ�����
{
	if(root!=NULL)
	{
		if(h>depth)depth=h;
		depth2(root->lchild,h+1);
		depth2(root->rchild,h+1);
	}
}
void print(bitree root,int n)   //��ӡ��״������
{
	if(root==NULL)return;
	print(root->rchild ,n+1);
	for(int i=1;i<=n;i++)
		printf("   ");
	printf("%c\n",root->data );
	print(root->lchild ,n+1);
	
}
void main()
{
	bitree root=NULL;
	printf("��������������룬��ڵ���0��ʾ\n");
	root=creatbitree();
	printf("\n�Թ������ʽ���Ϊ\n");
	listbitree(root);
	printf("����������Ϊ:\n");
	preorder(root);
	printf("\n����������Ϊ��\n");
	inorder(root);
	printf("\n����������Ϊ��\n");
	postorder(root);
	printf("\nҶ�ӽ��Ϊ:\n");
	yezijiedian(root);
	yezijiedianshumu(root);
	printf("\nҶ�ӽ����ĿΪ��%d\n",leafcount);
	yezijiedianshumu1(root);
	printf("\nҶ�ӽ����ĿΪ:%d\n",count);
	depth1(root);
	printf("\n�������Ϊ%d\n",max+1);
	depth2(root,h);
	printf("�������Ϊ%d\n",depth);
	print(root,0);
}