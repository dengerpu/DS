#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{
	int data;  //数据域
	struct node * next;  //指针域
}lnode,*linklist;   //lnode等价于struct node    ,*linklist等价于 struct node * ;
linklist creat_list(linklist l)  //创建链表
{
	int i,n;
	linklist p;
	p=(linklist)malloc(sizeof(lnode));//分配了一个不存放有效数据的头结点
	if(p==NULL)
	{
		printf("分配失败\n");
		exit(0);
	}
	printf("请输入你需要输入元素的个数\n");
	scanf("%d",&n);
	printf("请输入元素\n");
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		scanf("%d",&p->data);
		p->next=l->next;
		l->next=p;
	}
	return l;
}
void travese_list(linklist l)
{
	linklist p;
	p=l;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void kong(linklist l)     //判断链表是否为空
{
	if(l->next==NULL)
		printf("链表为空");
	else
		printf("链表不空\n");
}
int length_list(linklist l)   //求链表长度
{
	int i=0;
	linklist p;
	p=l;
	while(p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}
linklist  sort_list(linklist l,int n)   //链表排序
{
	int i,j,t;
	linklist p=l,q;
	for(i=0,p=l->next;i<n-1;i++,p=p->next)
		for(j=i+1,q=p->next;j<n;j++,q=q->next)
		{
			if(p->data>q->data)
			{
				t=p->data;
				p->data=q->data;
				q->data=t;
			}
		}
		return l;
}
linklist insert_list(linklist l,int j,int e)   //插入
{
	int i=0;
	linklist p=l,s;
	while(p!=NULL&&i<j-1)
	{
		i++;
		p=p->next;
	}
	if(i>j-1||NULL==p)
	{
		printf("插入错误\n");
		exit(0);
	}
	p=(linklist)malloc(sizeof(lnode));
	if(p==NULL)
	{
		printf("分配错误\n");
		exit(0);
	}
	p->data=e;
	s->next=p->next;
	p->next=s;
	return l;
}
linklist delete_list(linklist l,int j)   //删除
{
	int i=0;
	linklist p=l,s;
	while(p->next!=NULL&&i<j-1)
	{
		i++;
		p=p->next;
	}
	if(i>j-1||NULL==p->next)
	{
		printf("删除错误\n");
		exit(0);
	}
	p=(linklist)malloc(sizeof(lnode));
	if(p==NULL)
	{
		printf("分配错误\n");
		exit(0);
	}
	s=p->next;
	p->next=s->next;
	free(s);
	return l;	
}
int main()
{
	linklist p=NULL,l; //等价于struct node *p=NULL;
	p=creat_list(l);//创建一个非循环单链表，并将该单链表的头结点地址赋给p;
	printf("输出链表元素\n");
	travese_list(p);   //遍历
	kong(l);
	printf("链表长度:%d\n",length_list(l));
	return 0;
}