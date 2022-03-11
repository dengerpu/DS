#include<stdio.h>
#include<malloc.h>
#include<math.h>					//调用fabs();绝对值函数会用到
#include<string.h>
#define max 100
typedef struct node
{
	char firstaddress[5];				//首地址
	int data;
	char endaddress[5];					//尾地址
	struct node *next;
}*Linklist,Node;
typedef struct node1				//这个结构体用来存放输入的数据
{
	char a[5];							//首地址
	int data1;
	char b[5];							//尾地址
	int flag;						//用来标记是否被选过
}array[max];
void enter(array v,int n)					//输入数据
{
	for(int i=0;i<n;i++)
	{
		scanf("%s%d%s",&v[i].a,&v[i].data1,&v[i].b);
		v[i].flag=0;
	}
}
void creat(Linklist L,char address[],int n,array v)
{
	Linklist p,s;
	p=L;
	int x=n,i;
	while(x!=0)
	{
		for(i=0;i<n;i++)
			if(v[i].flag==0)
			{
				if(strcmp(v[i].a,address)==0)
				{
					s=(Linklist)malloc(sizeof(Node));
					s->data=v[i].data1;
					strcpy(s->firstaddress,v[i].a);
					strcpy(s->endaddress,v[i].b);
					p->next=s;
					p=s;
					p->next=NULL;
					strcpy(address,v[i].b);
					v[i].flag=1;
				}
			}
			x--;
	}
	
}
void quchong(Linklist L,Linklist a,Linklist b)
{
    Linklist p,q,s,c,l;
	s=a;p=L->next ;c=b;
	while(p!=NULL)
	{
		q=(Linklist)malloc(sizeof(Node));    //q为待插入结点
		q->data =p->data ;
		strcpy(q->firstaddress,p->firstaddress);
		strcpy(q->endaddress ,p->endaddress );
		s->next =q;
		s=q;
		s->next =NULL;
		free(q);
		p=p->next ;
			l=a->next ;
			while(l!=NULL)
			{
				if(fabs(p->data )==fabs(l->data ))
				{
					q=(Linklist)malloc(sizeof(Node));    //q为待插入结点
					q->data =p->data ;
					strcpy(q->firstaddress,p->firstaddress);
					strcpy(q->endaddress ,p->endaddress );
					c->next =q;
					c=q;
					c->next =NULL;
				}
				else
				{
					break;
				}
				l=l->next ;
			}
		}
	
	
}
void print(Linklist L)    //输出链表
{
	Linklist p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%s %d %s\n",p->firstaddress,p->data,p->endaddress);
		p=p->next;
	}
}
int main()
{
	int n;
	char firstaddress[5];
	Linklist L,a,b;
	array v;
	L=(Linklist)malloc(sizeof(Node));
	a=(Linklist)malloc(sizeof(Node));
	b=(Linklist)malloc(sizeof(Node));
	scanf("%s %d",firstaddress,&n);					//输入首地址和要输入数的数量
	enter(v,n);
    creat(L,firstaddress,n,v);
	quchong(L,a,b);
	print(a);
	print(b);
//	print(L);
	return 0;
}