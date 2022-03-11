#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *LChild;
	struct node *RChild;
}bitnode;
bitnode *creatbitree()
{
	bitnode *t;
	char ch;
	ch=getchar();
	if(ch=='0')
		t=NULL;
	else
	{
		t=(bitnode *)malloc(sizeof(bitnode));
		t->data=ch;
		t->LChild=creatbitree();
		t->RChild=creatbitree();
	}
	return t;
}
void Listbitree(bitnode *t)
{
	if(t!=NULL)
	{
		printf("%c",t->data);
		if(t->LChild!=NULL||t->RChild!=NULL)
		{
			printf("(");
			Listbitree(t->LChild);
			if(t->RChild!=NULL)
				printf(",");
			Listbitree(t->RChild);
			printf(")");
		}
	}
}
void preorder(bitnode *t)
{
	if(t!=NULL)
	{
		printf("%3c",t->data);
		preorder(t->LChild);
		preorder(t->RChild);
	}
}
void main()
{
	bitnode *t=NULL;
	printf("�������������У���ڵ���0��ʾ\n");
	t=creatbitree();
	printf("������ʾ�Ķ��������\n");
	Listbitree(t);
	printf("����������������\n");
	preorder(t);
	printf("\n");
}