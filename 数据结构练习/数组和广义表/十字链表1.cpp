#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int row,col;      //����Ԫ�ص��к����±�
	int value;
	struct node *down,*right;     //����Ԫ�������У��еĺ������
}Node,*Link;
typedef struct
{
	Link *row_head,*col_head;           //���������ͷָ��
	int m,n,len;                    //����������������Ԫ�ظ���
}crosslist;
void creatcrosslist(crosslist *M)
{
	int m,n,t,i,j,e;
	crosslink *p,*q;
	scanf("%d%d%d",&m,&n,&t);  //����M������������������Ԫ�صĸ���
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


