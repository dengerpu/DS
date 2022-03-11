#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *LChild;
	struct node *RChild;
}*Bitree;
void creatbitree(Bitree bt)
{
	char ch;
	ch=getchar();
	if(ch=='.') bt=NULL;
	else
	{
		bt=(Bitree)malloc(sizeof(struct node));
		bt->data=ch;
		creatbitree(bt->LChild);
		creatbitree(bt->RChild);
	}
	
}
int  printtree(Bitree bt,int n)
{
	int i;
	if(bt==NULL) return 0;
	printtree(bt->RChild,n+1);
	for(i=0;i<n;i++)
		printf(" ");
	printf("%c\n",bt->data);
	printtree(bt->LChild,n+1);
	return 1;
}
void main()
{
	Bitree bt;
	int n;
	scanf("%d",&n);
	creatbitree(bt);
	printtree(bt,n);
}
