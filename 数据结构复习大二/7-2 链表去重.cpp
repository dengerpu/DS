#include<stdio.h>
#include<malloc.h>
#include<math.h>					//调用fabs();绝对值函数会用到
#include<string.h>
#define max 10000
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
	char b[5];									//尾地址
	int flag;										//用来标记是否被选过
}array[max];
void enter(array v,int n)								//输入数据
{
	for(int i=0;i<n;i++)
	{
		int temp;
		temp=scanf("%s%d%s",v[i].a,&v[i].data1,v[i].b);
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
		{
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
		}
			x--;
	}
	
}
void quchong(Linklist L,Linklist a,Linklist b)				//a存储去重后的数据，存储删去的数去
{
    Linklist p,q,s,c,l;int sign=0;
	s=a;p=L->next ;c=b;
	while(p!=NULL)
	{
		q=(Linklist)malloc(sizeof(Node));					//q为待插入结点
		q->data =p->data ;
		strcpy(q->firstaddress,p->firstaddress);
		strcpy(q->endaddress ,p->endaddress );
		s->next =q;
		s=q;
		s->next =NULL;
		p=p->next ;	
		if(p!=NULL)
		{
			l=a->next;
			while(l!=NULL)
			{
				if(fabs(p->data )==fabs(l->data ))			//第一次运行，L链表中第一个数已经进入a中，L第二个数要和a中的数比较，如果重复进入b中，不重复进入a中
				{
					sign=1;
					q=(Linklist)malloc(sizeof(Node));		//q为待插入结点
					q->data =p->data ;
					if(p->next !=NULL)
						strcpy(l->endaddress ,p->next->firstaddress );    //将重复数的尾地址传给上一个数					
					strcpy(q->firstaddress,p->firstaddress);
					if(p->next!=NULL)
						strcpy(q->endaddress ,p->next->endaddress );
					else
						strcpy(q->endaddress,"-1");
					c->next =q;
					c=q;
					c->next =NULL;
				}
				l=l->next ;
			}
		}	
		if(sign==1)
			{
				p=p->next ;
				sign=0;
			}
		
	}
	strcpy(s->endaddress ,"-1");
	
	
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
	int temp;
	temp=scanf("%s %d",firstaddress,&n);					//输入首地址和要输入数的数量
	enter(v,n);	
    creat(L,firstaddress,n,v);
	quchong(L,a,b);	
	print(a);
	print(b);
	return 0;
}