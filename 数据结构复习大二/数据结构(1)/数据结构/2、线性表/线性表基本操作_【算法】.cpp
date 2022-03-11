#define OK 1
#define ERROR 0
typedef int ElemType
#define MAXSIZE 100
/* 顺序表类型结构定义 */
typedef struct
{
	ElemType elem[MAXSIZE];	/* 线性表占用的数组空间 */
	int last;	/* 记录线性表中最后一个元素在数组elem[]中的位置（下标值），空表置为-1 */
}SeqList;
/* 【算法2.1】 顺序表的按内容查找运算 */
int Locate(SeqList L,ElemType e)
/*在顺序表L中查找与e相等的元素，若L.elem[i]==e，则找到该元素，并返回i+1，若找不到，则返回-1*/
{
	int i=0;	/*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while((i<=L.last)&&(L.elem[i]!=e))	/*顺序扫描表，直到找到值为e的元素，或扫描到表尾而没找到*/
		i++;
	if(i<=L.last)
		return (i+1);	/*若找到值为e的元素，则返回其序号*/
	else
		return (-1);	/*若没找到，则返回空序号*/
}
/* 【算法2.2】 顺序表的插入运算 */
int InsList(SeqList * L,int i,ElemType e)
/* 在顺序表L中第i个数据元素之前插入一个元素e。i的合法取值范围是1<=i<=L->last+2 */
{
	int k;
	if((i<0)||(i>L->last+2))	/* 首先判断插入位置是否合法 */
	{
		printf("插入位置i值不合法");
		return (ERROR);
	}
	if(L->last>=MAXSIZE-1)
	{
		printf("表已满，无法插入");
		return (ERROR);
	}
	for(k=L->last;k>=i-1;k--)	/* 为插入元素而移动位置 */
		L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;	/* 在C语言数组中，第i个元素的下标为i-1 */
	L->last++;
	return (OK);
}
/* 【算法2.3】 顺序表的删除运算*/
int DelList(SeqList * L,int i,ElemType * e)
/* 在顺序表L中删除第i个数据元素，并用指针参数e返回其值。i的合法取值为1<=i<=L.last+1 */
{
	int k;
	if((i<1)||(i>L->last+1))
	{
		printf("删除位置不合法！");
		return (ERROR);
	}
	* e=L->elem[i-1];	/* 将删除的元素存放到e所指向的变量中 */
	for(k=i;k<=L->last;k++)
		L->elem[k-1]=L->elem[k];	/* 将后面的元素依次前移 */
	L->last--;
	return (OK);
}
/* 【算法2.4】 线性表的合并运算 */
void MergeList(SeqList * LA,SeqList * LB,SeqList * LC)
{
	int i,j,k,l;
	i=0;j=0;k=0;
	while(i<LA->last&&j<LB->last)
	{
		if(LA->elem[i]<=LB->elem[j])
			LC->elem[k++]=LA->elem[i++];
		else
			LC->elem[k++]=LB->elem[j++];
	}
	while(i<LA->last)	/* 当表LA有剩余元素时，则将表LA余下的元素赋给表LC */
		LC->elem[k++]=LA->elem[i++];
	while(j<LB->last)	/* 当表LB有剩余元素时，则将表LB余下的元素赋给表LC */
		LC->elem[k++]=LB->elem[j++];
	LC->last=LA->last+LB->last+1;
}
/***************************************************************/
/* 单链表类型结构定义 */
typedef int ElemType
typedef struct Node	/* 结点类型定义 */
{
	ElemType data;
	struct Node * next;
}Node,* LinkList;	/* LinkList为结构体指针类型 */
/* 【算法2.5】 初始化单链表*/
int InitList(LinkList * L)
{
	* L=(LinkList)malloc(sizeof(LinkList));	/* 建立头结点 */
	(* L)->next=NULL;	/* 建立空的单链表L */
}
/* 【算法2.6】 用头插法建立单链表 */
void CreateFromHead(LinkList L)
/* L是带头结点的空链表头指针，通过键盘输入表中元素值，利用头插法建单链表L */
{
	Node * s;
	char c;
	int flag=1;
	while(flag)	/* flag初值为1，当输入“$”时，置flag为0，建表结束 */
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node *)malloc(sizeof(Node));	/* 建立新结点 */
			s->data=c;
			s->next=L->next;	/* 将s结点插入表头 */
			L->next=s;
		}
		else
			flag=0;
	}
}
/* 【算法2.7】 用尾插法建立单链表 */
void CreateFromTail(LinkList L)
/* L是带头结点的空链表头指针，通过键盘输入元素值，利用尾插法建单链表L */
{
	Node * r,* s;
	int flag=1;	/* 设置一个标志，初值为1，当输入“$”时，flag为0，建表结束 */
	r=L;	/* r指针动态指向链表的当前表尾，以便于做尾插入，其初值指向头结点 */
	while(flag)	/* 循环输入表中元素值，将建立新结点s插入表尾 */
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node *)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			flag=0;
			r->next=NULL;	/* 将最后一个结点的next链域置为空，表示链表的结束 */
		}
	}	/* while */
}	/* CreateFromTail */
/* 【算法2.8】 在单链表L中查找第i个结点 */
Node * Get(LinkList L,int i)
/* 在带头结点的单链表L中查找第i个结点，若找到(1<=i<=n),则返回该结点的存储位置，否则返回NULL */
{
	int j;
	Node * p;
	if(i<=0) return NULL;
	p=L;j=0;	/* 从头结点开始扫描 */
	while((p->next!=NULL)&&j<i)
	{
		p=p->next;	/* 扫描下一个结点 */
		j++;	/* 已扫描结点计数器 */
	}
	if(i==j)	return p;	/* 找到了第i个结点 */
	else return NULL;	/* 找不到，i<=0或i>n */
}	/* Get */
/* 【算法2.9】 在单链表L中查找值为key的结点 */
Node * Locate(LinkList L,ElemType key)
/* 在带头结点的单链表L中查找其结点值等于key的第一个结点，若找到则返回该结点的位置p，否则返回NULL */
{
	Node * p;
	p=L->next;	/* 从表中第一个结点开始 */
	while(p!=NULL)	/* 当前表未查完 */
	{
		if(p->data!=key)
			p=p->next;
		else
			break;	/* 找到结点值=key时退出循环 */
	}
	return p;
}	/* Locate */
/* 【算法2.10】 求单链表的长度 */
int ListLength(LinkList L)
/* 求带头结点的单链表L的长度 */
{
	Node * p;
	p=L->next;
	j=0;	/* 用来存放单链表的长度 */
	while(p!=NULL)
	{
		p=p->next;
		j++;
	}
	return j;	/* j为求得的单链表长度 */
}	/* ListLength */
/* 【算法2.11】 单链表插入操作 */
void InsList(LinkList L,int i,ElemType e)
/* 在带头结点的单链表L中第i个位置插入值为e的新结点 */
{
	Node * pre,* s;
	int k;
	if(i<=0)
		return ERROR;
	pre=L;k=0;	/* 从“头”开始查找第i-1个节点 */
	while(pre!=NULL&&k<i-1)	/* 表未查完且未查到第i-1个时重复，找到pre指向的第i-1个 */
	{
		pre=pre->next;
		k++;
	}	/* 查找第i-1个结点 */
	if(pre==NULL)	/* 如当前位置pre为空表示已找完，但还未数到第i个，说明插入位置不合理 */
	{
		printf("插入位置不合理！");
		return ERROR;
	}
	s=(Node *)malloc(sizeof(Node));	/* 申请一个新结点s */
	s->data=e;	/* 值e置入s的数据域 */
	s->next=pre->next;	/* 修改指针，完成插入操作 */
	pre->next=s;
	return OK;
}
/* 【算法2.12】 单链表删除操作 */
int DelList(LinkList L,int i,ElemType * x)
/* 在带头结点的单链表L中删除第i个元素，并将删除的元素保存到变量* e中 */
{
	Node * pre,* r;
	int k;
	pre=L;k=0;
	while(pre->next!=NULL&&k<i-1)
	/* 寻找被删除结点i的前驱结点i-1使p指向它 */
	{
		pre=pre->next;
		k++;
	}	/* 查找第i-1个结点 */
	if(pre->next==NULL)	/* while循环是因为p->next=NULL或i<1而跳出来的，因为pre->next为空，没有找到合法的前驱位置，说明删除位置i不合法 */
	{
		printf("删除结点的位置i不合理！");
		return ERROR;
	}
	r=pre->next;
	pre->next=r->next;	/* 修改指针，删除结点r */
	* e=r->data;
	free(r);	/* 释放被删除的结点所占的内存空间 */
	return OK;
}
/* 【算法2.13】 合并两个有序的单链表*/
LinkList MergeLinkList(LinkList LA,LinkList LB)
/* 将递增有序的单链表LA和LB合并成一个递增有序的单链表LC */
{
	Node * pa,* pb,* r;
	LinkList LC;
	/* 将LC初始置空表。pa和pb分别指向两个单链表LA和LB中的第一个结点，r初值为LC且r始终指向LC的表尾 */
	pa=LA->next;
	pb=LB->next;
	LC=LA;
	LC->next=NULL;
	r=LC;
	/* 当两个表中均未处理完时,比较选择将较小值结点插入到新表LC中。 */
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->data<=pb->data)
		{ r->next=pa; r=pa; pa=pa->next }
		else
		{ r->next=pb; r=pb; pb=pb->next }
	}
	if(pa)	/* 若表LA未完，将表LA中后续元素链到新表LC表尾 */
		r->next=pa;
	else	/* 否则将表LB中后续元素链到新表LC表尾 */
		r->next=pb;
	free(LB);
	return LC;
}	/* MergeLinkList */
/***************************************************************/
/* 循环链表 */
/* 初始化循环单链表 */
void InitCLinkList(LinkList * CL)
/* CL用来接收待初始化的循环单链表的头指针变量的地址 */
{
	* CL=(LinkList)malloc(sizeof(Node));	/* 建立头结点 */
	(* CL)->next=* CL;	/* 建立空的循环单链表CL */
}
/* 建立循环单链表 */
void CreateCLinkList(LinkList CL)
/* CL是已经初始化好的、带头结点的空循环链表的头指针，通过键盘输入元素值，利用尾插法建立循环单链表CL */
{
	Node * rear,* s;
	char c;
	rear=CL;	/* rear指针动态指向链表的当前表尾，其初值指向头结点 */
	c=getchar();	/* 读入第一个元素 */
	while(c!='$')	/* 只要读入的元素不是结束标志，就存入新结点s并链到表尾，直到读入结束标志 */
	{
		s=(Node *)malloc(sizeof(Node));
		s->data=c;
		rear->next=s;
		rear=s;
		c=getchar();
	}
	rear->next=CL;	/* 让最后一个结点的next链域指向头结点 */
}
/* 【算法2.14】 循环单链表的合并算法(1) */
LinkList Merge_1(LinkList LA,LinkList  LB)
/* 此算法将两个采用头指针的循环单链表的首尾连接起来 */
{
	Node * p,* q;
	p=LA;
	q=LB;
	while(p->next!=LA)	p=p->next;	/* 找到表LA的表尾，用p指向它 */
	while(q->next!=LB)	q=q->next;	/* 找到表LB的表尾，用q指向它 */
	q->next=LA;	/* 修改表LB的尾指针，使之指向表LA的头结点 */
	p->next=LB->next;	/* 修改表LA的尾指针，使之指向表LB的第一个结点 */
	free(LB);
	return (LA);
}
/* 【算法2.15】 循环单链表的合并算法(1) */
/* RA和RB为单链表的表尾指针 */
LinkList Merge_2(LinkList RA,LinkList RB)
{	/* 此算法将两个采用尾指针的循环链表首尾连接起来 */
	Node * p;
	p=RA->next;	/* 保存链表RA的头结点地址 */
	RA->next=RB->next->next;	/* 链表RB的开始结点链到链表RA的终端结点之后 */
	free(RB->next);	/* 释放链表RB的头结点 */
	RB->next=p;	/* 链表RA的头结点链到链表RB的终端结点之后 */
	return RB;
}
/***************************************************************/
/* 双链表类型结构定义 */
#define TRUE 1
#define FALSE 0
typedef int ElemType
typedef struct DNode
{
	ElemType data;
	struct DNode * prior,* next;
}DNode,* DoubleList;
/* 【算法2.16】 双向链表的插入操作 */
int DLinkIns(DoubleList L,int i,ElemType e)
{
	DNode * s,* p;
	......	/* 先检查待插入的位置i是否合法（实现方法同单链表的前插操作） */
	......	/* 若位置i合法，则找到第i个结点并让指针p指向它 */
	s=(DNode *)malloc(sizeof(DNode));
	if(s)
	{
		s->data=e;
		s->prior=p->prior;
		p->prior->next=s;
		s->next=p;
		p->prior=s;
		return TRUE;
	}
	else
		return FALSE;
}
/* 【算法2.17】 双向链表的删除操作 */
int DLinkDel(DoubleList L,int i,ElemType * e)
{
	DNode * p;
	......	/* 先检查待插入的位置i是否合法（实现方法同单链表的删除操作） */
	......	/* 若位置i合法，则找到第i个结点并让指针p指向它 */
	* e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return TRUE;
}
/***************************************************************/
/* 静态链表类型结构定义 */
#define MAXSIZE 50
typedef int ElemType
typedef struct
{
	ElemType data;
	int cursor;
}Component,StaticList[MAXSIZE];
/* 【算法2.18】 静态单链表初始化 */
void initial(Static space,int * av)
{
	int k;
	space[0].cursor=-1;	/* 设置已用静态单链表的头指针指向space空间位置0，space[0]相当于头结点 */
	for(k=1;k<MXASIZE-1;k++)
		space[k].cursor=k+1;	/* 连链 */
	space[MAXSIZE-1].cursor=-1;	/* 标记链尾 */
	* av=1;
}	/* initial */
/* 【算法2.19】 分配结点 */
int getnode(StaticList space,int * av)
/* 从备用链表摘下一个结点空间，分配给待插入静态链表中的元素 */
{
	int i;
	i=* av;
	* av=space[* av].cursor;
	return i;
}
/* 【算法2.20】 空间结点回收 */
void freenode(StaticList space,int * av,int k)
/* 从space备用链表中回收序号为k的结点，av为备用链表的头指针 */
{
	space[k].cursor=* av;
	* av=k;
}
/***************************************************************/
/* 多项式链式类型结构定义 */
typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode * next;
}Polynode,* Polylist;
/* 【算法2.21】 用尾插法建立一元多项式的链表 */
Polylist PolyCreate()
{
	Polynode * head,* rear,* s;
	int c,e;
	head=(Polynode *)malloc(sizeof(Polynode));	/* 建立多项式的头结点 */
	rear=head;	/* rear始终指向单链表的尾，便于尾插法建表 */
	scanf("%d%d",&c,&e);	/* 输入多项式的系数和指数项 */
	while(c!=0)	/* 若c=0，则代表多项式的输入结束 */
	{
		s=(Polynode *)malloc(sizeof(Polynode));
		s->coef=c;
		s->exp=e;
		rear->next=s;	/* 在当前表尾做插入 */
		rear=s;
		scanf("%d%d",&c,&e);
	}
	rear->next=NULL;	/* 将表的最后一个结点的next置NULL，以示表结束 */
	return (head);
}
/* 【算法2.22】 多项式相加 */
void PolyAdd(Polylist polya,Polylist polyb)
/* 将两个多项式相加，然后将和多项式存放在多项式polya中，并将多项式polyb删除 */
{
	Polynode * p,* q,* tail,* temp;
	int sum;
	p=polya->next;	/* 令p和q分别指向polya和polyb多项式链表中的第一个结点 */
	q=polyb->next;
	tail=polya;	/* tail指向和多项式的尾结点 */
	while(p!=NULL&&q!=NULL)	/* 当两个多项式均未扫描结束时 */
	{
		if(p->exp<q->exp)
		/* 规则(1):p指向的多项式项指数小于q的指数，将p结点加入到和多项式中 */
		{ tail->next=p; tail=p; p=p->next }
		else if(p->exp==q->exp)	/* 规则(2):若指数相等，则相应的系数相加 */
		{
			sum=p->coef+q->coef;
			if(sum!=0)	/* 系数和非零，则系数和置入结点p，p加入到和多项式，释放结点q，并将指针后移 */
			{
				p->coef=sum;
				tail->next=p;
				tail=P;
				p=p->next;
				temp=q; q=q->next; free(temp);
			}
			else	/* 若系数和为零，则删除结点p与q，并将指针指向下一个结点 */
			{
				temp=p; p=p->next; free(temp);
				temp=q; q=q->next; free(temp);
			}
		}
		else
		{
			tail->next=q; tail=q;	/* 规则(3):将q结点加入到“和多项式中” */
			q=q->next;
		}
	}
	if(p!=NULL)	/* 多项式A中还有剩余，则将剩余的结点加入到和多项式中 */
		tail->next=p;
	else	/* 否则，将B中的结点加入到和多项式中 */
		tail->next=q;
}