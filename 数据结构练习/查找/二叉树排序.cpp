#include<stdio.h>
typedef struct node
{
	int key;       //�ؼ��ֵ�ֵ
	struct node *lchild,*rchild;
}bstnode,*bstree;
void insertbst(bstree bst,int key)   //��������������ĵݹ��㷨
{
	bitree s;
	if(bst==NULL)
	{
		s=(bstree)malloc(sizeof(sizeof(bstnode)));  //�����µĽ��
		s->key=key;
		s->lchild=NULL,s->rchild=NULL;
		b=s;
	}
	else if(key<bst->key)
		insertbst(&bst->lchild,key);
	else if(key>bst->key)
		insertbst(&bst->rchild,key);
}
void creatbst(bstree bst)   //����������
{
	int key;
	bst=NULL;
	scanf("%d",&key);
	while(key!=ENDKEY)  //ENDKEYΪ�Զ��峣��
	{
		insertbst(bst,key);
		scanf("%d",&key);
	}
}
bstree searchbst(bstree bst,int key)  //���������ҵݹ��㷨
{
	if(!bst) return NULL;
	else if(bst->key==key)  return bst;  //���ҳɹ�
	else if(bst->key>key) return searchbst(bst->lchild,key); //���������������� 
	else
		return searchbst(bst->rchild,key);          //����������������
} 
bstree searchbst(bstree bst,int key)  //���������ҵķǵݹ��㷨
{
	bstree q;
	q=bst;
	while(q)
	{
		if(q->key==key) return q;  //���ҳɹ�
		if(q->key>key)q=q->lchild;
		else
			q=q->rchild;
	}
	return NULL;;
}
bstnode *delbst(bstree t,int k)
{
bstnode *p,*f,*s,*q;
p=t
}