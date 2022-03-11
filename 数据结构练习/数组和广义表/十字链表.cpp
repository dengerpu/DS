typedef struct OLnode
{
	int row,col;
	int value;
	struct *right,*down;
}OLNode;*Olink;
typedef struct
{
	Olink *row_head,*col_head;
	int m,n,len;
}crosslink;
void createcrosslist(crosslink *M)
{
	crosslink p;
	int i,j,e,m,n,t;
	scanf("%d%d%d",&m,&n,&t);  //输入M的行数列数和非零元素的个数
	M->m =m;M->n =n;M->len =t;
	M->row_head=(Olink *)malloc((m+1)sizeof(Olink));
	M->col_head=(Olink *)malloc((m+1)sizeof(Olink));
	for()
	{
		p=(Olink *)malloc((m+1)sizeof(Olink));
		p->row=i;p->col=j;p->value=e;
		if(M->row_head[i]==NULL) M->row_head[i]=p;
		else
		{
			q=M->row_head[i];
			while(q->right!=NULL&&q->right->col<j)
				q=q->right;
			p->right=q->right;
			q->right=p;
		}
	}
}