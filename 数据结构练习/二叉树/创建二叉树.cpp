typedef struct node
{
	int data;
	struct node *LChild;
	struct node *RChild;
}Bitnode,*Bitree;
void CreatBitree(Bitree *bt)   //先序创建二叉树
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
int Posttreedepth(Bitree bt)   //后序遍历求二叉树高度
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
void pretreedepth(Bitree bt,int h)  //先序遍历求二叉树高度的递归算法   h初始值为1，depth初始值为0；
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