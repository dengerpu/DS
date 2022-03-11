#define OK 1
#define ERROR 0
typedef int ElemType
#define MAXSIZE 100
/* ˳������ͽṹ���� */
typedef struct
{
	ElemType elem[MAXSIZE];	/* ���Ա�ռ�õ�����ռ� */
	int last;	/* ��¼���Ա������һ��Ԫ��������elem[]�е�λ�ã��±�ֵ�����ձ���Ϊ-1 */
}SeqList;
/* ���㷨2.1�� ˳���İ����ݲ������� */
int Locate(SeqList L,ElemType e)
/*��˳���L�в�����e��ȵ�Ԫ�أ���L.elem[i]==e�����ҵ���Ԫ�أ�������i+1�����Ҳ������򷵻�-1*/
{
	int i=0;	/*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while((i<=L.last)&&(L.elem[i]!=e))	/*˳��ɨ���ֱ���ҵ�ֵΪe��Ԫ�أ���ɨ�赽��β��û�ҵ�*/
		i++;
	if(i<=L.last)
		return (i+1);	/*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
	else
		return (-1);	/*��û�ҵ����򷵻ؿ����*/
}
/* ���㷨2.2�� ˳���Ĳ������� */
int InsList(SeqList * L,int i,ElemType e)
/* ��˳���L�е�i������Ԫ��֮ǰ����һ��Ԫ��e��i�ĺϷ�ȡֵ��Χ��1<=i<=L->last+2 */
{
	int k;
	if((i<0)||(i>L->last+2))	/* �����жϲ���λ���Ƿ�Ϸ� */
	{
		printf("����λ��iֵ���Ϸ�");
		return (ERROR);
	}
	if(L->last>=MAXSIZE-1)
	{
		printf("���������޷�����");
		return (ERROR);
	}
	for(k=L->last;k>=i-1;k--)	/* Ϊ����Ԫ�ض��ƶ�λ�� */
		L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;	/* ��C���������У���i��Ԫ�ص��±�Ϊi-1 */
	L->last++;
	return (OK);
}
/* ���㷨2.3�� ˳����ɾ������*/
int DelList(SeqList * L,int i,ElemType * e)
/* ��˳���L��ɾ����i������Ԫ�أ�����ָ�����e������ֵ��i�ĺϷ�ȡֵΪ1<=i<=L.last+1 */
{
	int k;
	if((i<1)||(i>L->last+1))
	{
		printf("ɾ��λ�ò��Ϸ���");
		return (ERROR);
	}
	* e=L->elem[i-1];	/* ��ɾ����Ԫ�ش�ŵ�e��ָ��ı����� */
	for(k=i;k<=L->last;k++)
		L->elem[k-1]=L->elem[k];	/* �������Ԫ������ǰ�� */
	L->last--;
	return (OK);
}
/* ���㷨2.4�� ���Ա�ĺϲ����� */
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
	while(i<LA->last)	/* ����LA��ʣ��Ԫ��ʱ���򽫱�LA���µ�Ԫ�ظ�����LC */
		LC->elem[k++]=LA->elem[i++];
	while(j<LB->last)	/* ����LB��ʣ��Ԫ��ʱ���򽫱�LB���µ�Ԫ�ظ�����LC */
		LC->elem[k++]=LB->elem[j++];
	LC->last=LA->last+LB->last+1;
}
/***************************************************************/
/* ���������ͽṹ���� */
typedef int ElemType
typedef struct Node	/* ������Ͷ��� */
{
	ElemType data;
	struct Node * next;
}Node,* LinkList;	/* LinkListΪ�ṹ��ָ������ */
/* ���㷨2.5�� ��ʼ��������*/
int InitList(LinkList * L)
{
	* L=(LinkList)malloc(sizeof(LinkList));	/* ����ͷ��� */
	(* L)->next=NULL;	/* �����յĵ�����L */
}
/* ���㷨2.6�� ��ͷ�巨���������� */
void CreateFromHead(LinkList L)
/* L�Ǵ�ͷ���Ŀ�����ͷָ�룬ͨ�������������Ԫ��ֵ������ͷ�巨��������L */
{
	Node * s;
	char c;
	int flag=1;
	while(flag)	/* flag��ֵΪ1�������롰$��ʱ����flagΪ0��������� */
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node *)malloc(sizeof(Node));	/* �����½�� */
			s->data=c;
			s->next=L->next;	/* ��s�������ͷ */
			L->next=s;
		}
		else
			flag=0;
	}
}
/* ���㷨2.7�� ��β�巨���������� */
void CreateFromTail(LinkList L)
/* L�Ǵ�ͷ���Ŀ�����ͷָ�룬ͨ����������Ԫ��ֵ������β�巨��������L */
{
	Node * r,* s;
	int flag=1;	/* ����һ����־����ֵΪ1�������롰$��ʱ��flagΪ0��������� */
	r=L;	/* rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ��� */
	while(flag)	/* ѭ���������Ԫ��ֵ���������½��s�����β */
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
			r->next=NULL;	/* �����һ������next������Ϊ�գ���ʾ����Ľ��� */
		}
	}	/* while */
}	/* CreateFromTail */
/* ���㷨2.8�� �ڵ�����L�в��ҵ�i����� */
Node * Get(LinkList L,int i)
/* �ڴ�ͷ���ĵ�����L�в��ҵ�i����㣬���ҵ�(1<=i<=n),�򷵻ظý��Ĵ洢λ�ã����򷵻�NULL */
{
	int j;
	Node * p;
	if(i<=0) return NULL;
	p=L;j=0;	/* ��ͷ��㿪ʼɨ�� */
	while((p->next!=NULL)&&j<i)
	{
		p=p->next;	/* ɨ����һ����� */
		j++;	/* ��ɨ��������� */
	}
	if(i==j)	return p;	/* �ҵ��˵�i����� */
	else return NULL;	/* �Ҳ�����i<=0��i>n */
}	/* Get */
/* ���㷨2.9�� �ڵ�����L�в���ֵΪkey�Ľ�� */
Node * Locate(LinkList L,ElemType key)
/* �ڴ�ͷ���ĵ�����L�в�������ֵ����key�ĵ�һ����㣬���ҵ��򷵻ظý���λ��p�����򷵻�NULL */
{
	Node * p;
	p=L->next;	/* �ӱ��е�һ����㿪ʼ */
	while(p!=NULL)	/* ��ǰ��δ���� */
	{
		if(p->data!=key)
			p=p->next;
		else
			break;	/* �ҵ����ֵ=keyʱ�˳�ѭ�� */
	}
	return p;
}	/* Locate */
/* ���㷨2.10�� ������ĳ��� */
int ListLength(LinkList L)
/* ���ͷ���ĵ�����L�ĳ��� */
{
	Node * p;
	p=L->next;
	j=0;	/* ������ŵ�����ĳ��� */
	while(p!=NULL)
	{
		p=p->next;
		j++;
	}
	return j;	/* jΪ��õĵ������� */
}	/* ListLength */
/* ���㷨2.11�� ������������ */
void InsList(LinkList L,int i,ElemType e)
/* �ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½�� */
{
	Node * pre,* s;
	int k;
	if(i<=0)
		return ERROR;
	pre=L;k=0;	/* �ӡ�ͷ����ʼ���ҵ�i-1���ڵ� */
	while(pre!=NULL&&k<i-1)	/* ��δ������δ�鵽��i-1��ʱ�ظ����ҵ�preָ��ĵ�i-1�� */
	{
		pre=pre->next;
		k++;
	}	/* ���ҵ�i-1����� */
	if(pre==NULL)	/* �統ǰλ��preΪ�ձ�ʾ�����꣬����δ������i����˵������λ�ò����� */
	{
		printf("����λ�ò�����");
		return ERROR;
	}
	s=(Node *)malloc(sizeof(Node));	/* ����һ���½��s */
	s->data=e;	/* ֵe����s�������� */
	s->next=pre->next;	/* �޸�ָ�룬��ɲ������ */
	pre->next=s;
	return OK;
}
/* ���㷨2.12�� ������ɾ������ */
int DelList(LinkList L,int i,ElemType * x)
/* �ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����ɾ����Ԫ�ر��浽����* e�� */
{
	Node * pre,* r;
	int k;
	pre=L;k=0;
	while(pre->next!=NULL&&k<i-1)
	/* Ѱ�ұ�ɾ�����i��ǰ�����i-1ʹpָ���� */
	{
		pre=pre->next;
		k++;
	}	/* ���ҵ�i-1����� */
	if(pre->next==NULL)	/* whileѭ������Ϊp->next=NULL��i<1���������ģ���Ϊpre->nextΪ�գ�û���ҵ��Ϸ���ǰ��λ�ã�˵��ɾ��λ��i���Ϸ� */
	{
		printf("ɾ������λ��i������");
		return ERROR;
	}
	r=pre->next;
	pre->next=r->next;	/* �޸�ָ�룬ɾ�����r */
	* e=r->data;
	free(r);	/* �ͷű�ɾ���Ľ����ռ���ڴ�ռ� */
	return OK;
}
/* ���㷨2.13�� �ϲ���������ĵ�����*/
LinkList MergeLinkList(LinkList LA,LinkList LB)
/* ����������ĵ�����LA��LB�ϲ���һ����������ĵ�����LC */
{
	Node * pa,* pb,* r;
	LinkList LC;
	/* ��LC��ʼ�ÿձ�pa��pb�ֱ�ָ������������LA��LB�еĵ�һ����㣬r��ֵΪLC��rʼ��ָ��LC�ı�β */
	pa=LA->next;
	pb=LB->next;
	LC=LA;
	LC->next=NULL;
	r=LC;
	/* ���������о�δ������ʱ,�Ƚ�ѡ�񽫽�Сֵ�����뵽�±�LC�С� */
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->data<=pb->data)
		{ r->next=pa; r=pa; pa=pa->next }
		else
		{ r->next=pb; r=pb; pb=pb->next }
	}
	if(pa)	/* ����LAδ�꣬����LA�к���Ԫ�������±�LC��β */
		r->next=pa;
	else	/* ���򽫱�LB�к���Ԫ�������±�LC��β */
		r->next=pb;
	free(LB);
	return LC;
}	/* MergeLinkList */
/***************************************************************/
/* ѭ������ */
/* ��ʼ��ѭ�������� */
void InitCLinkList(LinkList * CL)
/* CL�������մ���ʼ����ѭ���������ͷָ������ĵ�ַ */
{
	* CL=(LinkList)malloc(sizeof(Node));	/* ����ͷ��� */
	(* CL)->next=* CL;	/* �����յ�ѭ��������CL */
}
/* ����ѭ�������� */
void CreateCLinkList(LinkList CL)
/* CL���Ѿ���ʼ���õġ���ͷ���Ŀ�ѭ�������ͷָ�룬ͨ����������Ԫ��ֵ������β�巨����ѭ��������CL */
{
	Node * rear,* s;
	char c;
	rear=CL;	/* rearָ�붯ָ̬������ĵ�ǰ��β�����ֵָ��ͷ��� */
	c=getchar();	/* �����һ��Ԫ�� */
	while(c!='$')	/* ֻҪ�����Ԫ�ز��ǽ�����־���ʹ����½��s��������β��ֱ�����������־ */
	{
		s=(Node *)malloc(sizeof(Node));
		s->data=c;
		rear->next=s;
		rear=s;
		c=getchar();
	}
	rear->next=CL;	/* �����һ������next����ָ��ͷ��� */
}
/* ���㷨2.14�� ѭ��������ĺϲ��㷨(1) */
LinkList Merge_1(LinkList LA,LinkList  LB)
/* ���㷨����������ͷָ���ѭ�����������β�������� */
{
	Node * p,* q;
	p=LA;
	q=LB;
	while(p->next!=LA)	p=p->next;	/* �ҵ���LA�ı�β����pָ���� */
	while(q->next!=LB)	q=q->next;	/* �ҵ���LB�ı�β����qָ���� */
	q->next=LA;	/* �޸ı�LB��βָ�룬ʹָ֮���LA��ͷ��� */
	p->next=LB->next;	/* �޸ı�LA��βָ�룬ʹָ֮���LB�ĵ�һ����� */
	free(LB);
	return (LA);
}
/* ���㷨2.15�� ѭ��������ĺϲ��㷨(1) */
/* RA��RBΪ������ı�βָ�� */
LinkList Merge_2(LinkList RA,LinkList RB)
{	/* ���㷨����������βָ���ѭ��������β�������� */
	Node * p;
	p=RA->next;	/* ��������RA��ͷ����ַ */
	RA->next=RB->next->next;	/* ����RB�Ŀ�ʼ�����������RA���ն˽��֮�� */
	free(RB->next);	/* �ͷ�����RB��ͷ��� */
	RB->next=p;	/* ����RA��ͷ�����������RB���ն˽��֮�� */
	return RB;
}
/***************************************************************/
/* ˫�������ͽṹ���� */
#define TRUE 1
#define FALSE 0
typedef int ElemType
typedef struct DNode
{
	ElemType data;
	struct DNode * prior,* next;
}DNode,* DoubleList;
/* ���㷨2.16�� ˫������Ĳ������ */
int DLinkIns(DoubleList L,int i,ElemType e)
{
	DNode * s,* p;
	......	/* �ȼ��������λ��i�Ƿ�Ϸ���ʵ�ַ���ͬ�������ǰ������� */
	......	/* ��λ��i�Ϸ������ҵ���i����㲢��ָ��pָ���� */
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
/* ���㷨2.17�� ˫�������ɾ������ */
int DLinkDel(DoubleList L,int i,ElemType * e)
{
	DNode * p;
	......	/* �ȼ��������λ��i�Ƿ�Ϸ���ʵ�ַ���ͬ�������ɾ�������� */
	......	/* ��λ��i�Ϸ������ҵ���i����㲢��ָ��pָ���� */
	* e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return TRUE;
}
/***************************************************************/
/* ��̬�������ͽṹ���� */
#define MAXSIZE 50
typedef int ElemType
typedef struct
{
	ElemType data;
	int cursor;
}Component,StaticList[MAXSIZE];
/* ���㷨2.18�� ��̬�������ʼ�� */
void initial(Static space,int * av)
{
	int k;
	space[0].cursor=-1;	/* �������þ�̬�������ͷָ��ָ��space�ռ�λ��0��space[0]�൱��ͷ��� */
	for(k=1;k<MXASIZE-1;k++)
		space[k].cursor=k+1;	/* ���� */
	space[MAXSIZE-1].cursor=-1;	/* �����β */
	* av=1;
}	/* initial */
/* ���㷨2.19�� ������ */
int getnode(StaticList space,int * av)
/* �ӱ�������ժ��һ�����ռ䣬����������뾲̬�����е�Ԫ�� */
{
	int i;
	i=* av;
	* av=space[* av].cursor;
	return i;
}
/* ���㷨2.20�� �ռ������ */
void freenode(StaticList space,int * av,int k)
/* ��space���������л������Ϊk�Ľ�㣬avΪ���������ͷָ�� */
{
	space[k].cursor=* av;
	* av=k;
}
/***************************************************************/
/* ����ʽ��ʽ���ͽṹ���� */
typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode * next;
}Polynode,* Polylist;
/* ���㷨2.21�� ��β�巨����һԪ����ʽ������ */
Polylist PolyCreate()
{
	Polynode * head,* rear,* s;
	int c,e;
	head=(Polynode *)malloc(sizeof(Polynode));	/* ��������ʽ��ͷ��� */
	rear=head;	/* rearʼ��ָ�������β������β�巨���� */
	scanf("%d%d",&c,&e);	/* �������ʽ��ϵ����ָ���� */
	while(c!=0)	/* ��c=0����������ʽ��������� */
	{
		s=(Polynode *)malloc(sizeof(Polynode));
		s->coef=c;
		s->exp=e;
		rear->next=s;	/* �ڵ�ǰ��β������ */
		rear=s;
		scanf("%d%d",&c,&e);
	}
	rear->next=NULL;	/* ��������һ������next��NULL����ʾ����� */
	return (head);
}
/* ���㷨2.22�� ����ʽ��� */
void PolyAdd(Polylist polya,Polylist polyb)
/* ����������ʽ��ӣ�Ȼ�󽫺Ͷ���ʽ����ڶ���ʽpolya�У���������ʽpolybɾ�� */
{
	Polynode * p,* q,* tail,* temp;
	int sum;
	p=polya->next;	/* ��p��q�ֱ�ָ��polya��polyb����ʽ�����еĵ�һ����� */
	q=polyb->next;
	tail=polya;	/* tailָ��Ͷ���ʽ��β��� */
	while(p!=NULL&&q!=NULL)	/* ����������ʽ��δɨ�����ʱ */
	{
		if(p->exp<q->exp)
		/* ����(1):pָ��Ķ���ʽ��ָ��С��q��ָ������p�����뵽�Ͷ���ʽ�� */
		{ tail->next=p; tail=p; p=p->next }
		else if(p->exp==q->exp)	/* ����(2):��ָ����ȣ�����Ӧ��ϵ����� */
		{
			sum=p->coef+q->coef;
			if(sum!=0)	/* ϵ���ͷ��㣬��ϵ����������p��p���뵽�Ͷ���ʽ���ͷŽ��q������ָ����� */
			{
				p->coef=sum;
				tail->next=p;
				tail=P;
				p=p->next;
				temp=q; q=q->next; free(temp);
			}
			else	/* ��ϵ����Ϊ�㣬��ɾ�����p��q������ָ��ָ����һ����� */
			{
				temp=p; p=p->next; free(temp);
				temp=q; q=q->next; free(temp);
			}
		}
		else
		{
			tail->next=q; tail=q;	/* ����(3):��q�����뵽���Ͷ���ʽ�С� */
			q=q->next;
		}
	}
	if(p!=NULL)	/* ����ʽA�л���ʣ�࣬��ʣ��Ľ����뵽�Ͷ���ʽ�� */
		tail->next=p;
	else	/* ���򣬽�B�еĽ����뵽�Ͷ���ʽ�� */
		tail->next=q;
}