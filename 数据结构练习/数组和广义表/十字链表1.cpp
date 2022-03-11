#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int row,col;      //非零元素的行和列下标
	int value;
	struct node *down,*right;     //非零元素所在行，列的后继链域
}Node,*Link;
typedef struct
{
	Link *row_head,*col_head;           //行列链表的头指针
	int m,n,len;                    //行数，列数，非零元素个数
}crosslist;
void creatcrosslist(crosslist *M)
{
	int m,n,t,i,j,e;
	crosslink *p,*q;
	scanf("%d%d%d",&m,&n,&t);  //输入M的行数，列数，非零元素的个数
	M->m=m;M->n=n;M->len=t;
	M->row_head=(Link)malloc((m+1)*sizeof(Link));
	M->col_head=(Link)malloc((m+1)*sizeof(Link));
	M->row_head[]=M->col_head[]=NULL;
	for(scanf("%d%d%d",&i,&j,&e);i!=0;scanf("%d%d%d",&i,&j,&e))
	{
		p=(Node*)malloc(sizeof(Node));
		p->row=i;p->col=j;p->value=e;
		if(M->row_head[i]==NULL)M->row_head[i]=p;
		else
		{
			q=M->row_head[i];
			while(q->right!=NULL&&q->right->col<j)
				q=q->right;
			p->right=q->right;
			q->right=p;
		}
		if(M->col_head[j]==NULL)M->col_head[j]=p;
		else
		{
			q=M->col_head[j];
			while(q->down!=NULL&&q->dow->row<i)
				q=q->down;
			p->down=q->down;
			q->down=p;
		}
	}
}


