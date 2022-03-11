typedef struct node
{
	int data;
	struct node *LChild;
	struct node *RChild;
}Bitnode,*Bitree;
void CreatBitree(Bitree *bt)   //���򴴽�������
{
	char ch;
	ch=getchar();
	if(ch=='.') *bt=NULL;
	else
	{
		*bt=(Bitree)malloc(sizeof(Bitnode));
		(*bt)->data=ch;
		CreatBitree(&((*bt)->LChild));
		CreatBitree(&((*bt)->RChild));
	}
}
int Posttreedepth(Bitree bt)   //���������������߶�
{
	int hl,hr,max;
	if(bt!=NULL)
	{
		hl=posttreedepth(bt->LChild);
		hr=posttreedepth(bt->RChild);
		max=hl>hr?hl:hr;
		return (max+1);
	}
	else
		return (0);
} 
void pretreedepth(Bitree bt,int h)  //���������������߶ȵĵݹ��㷨   h��ʼֵΪ1��depth��ʼֵΪ0��
{
	if(bt!=NULL)
	{
		if(h>depth)  depth=h;
		pretreedepth(bt->LChild,h+1);
		pretreedepth(bt->RChild,h+1);
	}
}
void printtree(Bitree bt,int n)
{
	if(bt==NULL) return ;
	printftree(bt->RChild,n+1);
	for(int i=0;i<n;i++)
		printf(" ");
	printf("%c\n",bt->data);
	printtree(bt->LChild,n+1);
}