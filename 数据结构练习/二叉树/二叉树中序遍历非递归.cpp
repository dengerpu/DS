////ABDG00H000CE0I00F00
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}*bitree;
typedef struct Node
{
	bitree data;
	struct Node *next;
}seqstack;
bitree creatbitree()
{
	bitree root;
	char ch;
	ch=getchar();
	if(ch=='0')root=NULL;
	else
	{
		root=(bitree)malloc(sizeof(struct node));
		root->data=ch;
		root->lchild =creatbitree();
		root->rchild =creatbitree();
	}
	return root;
}
void initstack(seqstack *s)
{
	s=(seqstack *)malloc(sizeof(struct Node));
	s->next=NULL;
}
void push(seqstack *s,bitree p)
{
	seqstack *r,*a;
	a=s;
	r=(seqstack *)malloc(sizeof(struct Node));
	r->data=p;
	r->next=a->next;
	a->next=r;
}
void pop(seqstack *s,bitree p)
{
	seqstack *a;
	a=s->next;
	p=a->data;
	s->next=a->next;
	free(a);
}

void inorder(bitree root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf("%3c",root->data);
		inorder(root->rchild);
	}
}
int isempty(seqstack *s)
{
	if(s->next==NULL)
		return 1;
	else
		return 0;
}
void Inorder(bitree root)
{
	seqstack *s;
	//initstack(&s);
	s=(seqstack *)malloc(sizeof(struct Node));
	s->next=NULL;
	bitree p;
	p=root;
	while(p!=NULL||!isempty(s))
	{
		if(p!=NULL)
		{
			push(s,p);
			p=p->lchild;
		}
		else{
			pop(s,p);
			printf("%d",p->data);
			p=p->rchild;
		}
	}
}
void main()
{
	
	bitree root=NULL;
	
	printf("请输入先序序列，虚节点用0表示\n");
	root=creatbitree();
	printf("\n中序遍历输出:\n");
	inorder(root);
	printf("\n中序遍历非递归输出:\n");
	Inorder(root);
	
	
}
