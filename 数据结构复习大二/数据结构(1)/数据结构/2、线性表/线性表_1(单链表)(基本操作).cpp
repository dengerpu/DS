#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;	/*定义元素类型为int*/
/*线性表的链式储存结构定义*/
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LNode,* LinkList;
/*【算法2.9 通过尾插入法建立带头节点的单链表】*/
/*建立带头节点的单链表L，输入n个元素的值*/
LinkList Creat_LinkList(int n)
{
	LNode * L,* p,* q;
	int i;
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;	/*先建立一个带有头结点的单链表*/
	q=L;	/*q的初始值指向头节点*/
	for(i=0;i<=n-1;i++)
	{
		p=(LNode *)malloc(sizeof(LNode));	/*生成新节点*/
		printf("请输入第%d个元素的值：",i);
		scanf("%d",&p->data);	/*输入元素值*/
		p->next=NULL;	q->next=p;	q=p;	/*将该节点插入到表尾*/
	}
	return L;
}
/*打印链表中各元素的值*/
void Print_LinkList(LinkList L)
{
	LNode * p;
	p=L->next;
	printf("\n单链表中各元素的值为：");
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
/*【算法2.14 单链表的插入】*/
/*在带头节点的单链表L中的第i个位置之前插入元素e，若插入成功，则返回1，否则返回0*/
int Insert_LinkList(LinkList L,int i,ElemType e)
{
	LNode * p,* s;
	int j;
	p=L;j=-1;
	while(p&&j<i-1)	/*寻找第i-1个节点*/
	{ 
		p=p->next;
		j++; 
	}	
	if(!p||j>i-1)	
		return 0;	/*i值不合法*/
	s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next; p->next=s;
	return 1;
}
/*【算法2.15 单链表的删除】*/
/*在头节点的单链表L中，删除第i个元素，并由e返回其值，若删除成功，则返回1，否则返回0*/
int Delete_LinkList(LinkList L,int i,ElemType * e)
{
	LNode * p,* q;
	int j;
	p=L; j=0;
	while(p->next&&j<i-1) /*寻找第i个节点，并令p指向其前驱*/
	{
		p=p->next; 
		j++;
	}	
	if(!(p->next)||j>i-1) 
		return 0;	/*删除位置不合理*/
	q=p->next;
	* e=q->data;	/*用e返回被删节点数据域的值*/
	p->next=q->next; 
	free(q);	/*删除并释放节点*/
	return 1;
}
/*【算法2.13 单链表的按值查找】*/
/*在带头节点的单链表L中查找与给定值相同的元素的位序*/
int Locate_LinkElem(LinkList L,ElemType e)
{
	LNode * p;
	int i;
	p=L->next; i=0;
	while(p!=NULL&&p->data!=e) 
	{ 
		p=p->next; 
		i++;
	}
	if(p->data!=e) 
		return -1;
	else 
		return i;
}
int main()
{
	LinkList L;	/*定义一个头指针，以指示一个单链表*/
	int n,i,e,status;
	printf("请输入单链表的长度：n=");
	scanf("%d",&n);
	L=Creat_LinkList(n);	/*建立一个含n个元素的单链表*/
	Print_LinkList(L);	/*依次输出线性表各元素的值*/
	status=Insert_LinkList(L,4,27);	/*在第4个元素之前插入值27*/
	if(status) 
	{ 
		printf("\n\n进行插入操作后"); 
		Print_LinkList(L);
	}
	else 
	{
		printf("\n插入失败！");
		return 0;
	}
	status=Delete_LinkList(L,5,&e);
	if(status)
	{
		printf("\n\n被删除的元素的值为：%d",e);
		printf("\n\n进行删除操作后");
		Print_LinkList(L);
	}
	else 
	{ 
		printf("\n删除失败！"); 
		return 0;
	}
	printf("\n\n请输入要查找的值：e=");
	scanf("%d",&e);
	i=Locate_LinkElem(L,e);
	if(i>=0) 
		printf("该元素在线性表中的位序为：%d\n",i);
	else 
		printf("该元素在线性表中不存在\n");
	return 0;
}