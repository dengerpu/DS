/*顺序表的常用操作*/
#include<stdio.h>
#include<stdlib.h>
#define INIT_SIZE 100	/*线性表存储空间的初始分配量*/
#define INCREMENT 10	/*线性表存储空间的分配增量*/
typedef int ElemType;	/*定义元素类型为int*/
/*线性表顺序存储结构的定义*/
typedef struct
{
	ElemType * elem;	/*存储空间的基地址*/
	int length;	/*当前长度*/
	int listsize;	/*当前分配的存储容量（以sizeof(ElemType)为单位）*/
}SqList;
/*【算法2.1 顺序表的初始化】*/
/*初始化顺序表，若成功返回1，否则返回0*/
int InitList_Sq(SqList *L)
{
	L->elem=(ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
	if(!L->elem)
		return -1;
	L->length=0;
	L->listsize=INIT_SIZE;
	return 1;
}
/*打印顺序表的各个元素*/
void PrintSqList(SqList L)
{
	int i;
	printf("\n该线性表的元素依次为：\n");
	for(i=0;i < L.length;i++)
		printf("%d ",L.elem[i]);
	printf("\n");
}
/*输入顺序表各个元素的值*/
void InputSqList(SqList * L)
{
	int i,n;
	printf("请输入该线性表的元素个数：n=");
	scanf("%d",&n);
	while(n>L->listsize)
	{
		printf("超出了线性表的存储空间，请重新输入：\n");
		scanf("%d",&n);
	}
	L->length=n;
	printf("请依次输入该线性表各元素的值：\n");
	for(i=0;i<n;i++)
		scanf("%d",&L->elem[i]);
}
/*【算法2.2 顺序表的插入】*/
/*在顺序表L的第i个位置之前插入新的元素e，若成功则返回1，否则返回0*/
int ListInsert_Sq(SqList * L,int i,ElemType e)
{
	int j;
	ElemType * newbase;
	if(i<0||i>L->length)	/*插入位置不合法*/
		return 0;
	if(L->length >= L->listsize)	/*当前存储空间已满，增加分配*/
	{
		newbase=(ElemType *)realloc(L->elem,(L->listsize + INCREMENT)*sizeof(ElemType));
		if(!newbase)	/*存储分配失败*/
			return 0;
		L->elem = newbase;
		L->listsize += INCREMENT;
	}
	for(j=L->length-1;j>=i;j--)
		L->elem[j+1]=L->elem[j];	/*插入位置及之后的元素后移*/
	L->elem[i]=e;	/*插入e*/
	++L->length;	/*表长增1*/
	return 1;
}
/*【算法2.3 顺序表的删除】*/
/*在顺序表L中删除第i个元素，并用e返回其值，若成功则返回1，否则返回0*/
int ListDelete_Sq(SqList * L,int i,ElemType * e)
{
	int j;
	if(i<0||i>L->length-1)	/*i值不合法*/
		return 0;
	* e=L->elem[i];	/*被删除元素的值赋给e*/
	for(j=i+1;j<=L->length-1;j++)
		L->elem[j-1]=L->elem[j];	/*被删元素之后的元素前移*/
	--L->length;
	return 1;
}
/*【算法2.4 顺序表的查找】*/
/*在顺序线性表L中查找第i个值与e相等的元素位序，若找到，则返回其在L中的位序，否则返回0*/
int LocateElem_Sq(SqList L,ElemType e)
{
	int i=0;	/*i的初值为第一个元素的位序*/
	while(i<L.length&&L.elem[i]!=e)
		i++;
	if(L.elem[i]==e)
		return i;
	else
		return -1;
}
/*【算法2.5 读取顺序表中的元素】*/
/*在顺序线性表L中取第i个元素存入e中，若成功，则返回1，否则返回0*/
int Get_SqList(SqList L,int i,ElemType * e)
{
	if(i<0||i>L.length-1)	/*没有第i个元素，读取失败*/
		return 0;
	* e=L.elem[i];
	return 1;	/*读取成功*/
}
int main()
{
	SqList L;
	int status,e,i;
	status=InitList_Sq(&L);
	if(status)
		printf("顺序表初始化成功！\n");
	else
	{
		printf("顺序表初始化失败！\n");
		return 0;
	}
	InputSqList(&L);
	PrintSqList(L);
	printf("请输入插入位置：");
	scanf("%d",&i);
	status=ListInsert_Sq(&L,i,30);	/*在第i个元素之前插入30*/
	if(status)
	{
		printf("进行插入操作后");
		PrintSqList(L);
	}
	else
	{
		printf("\n插入失败！");
		return 0;
	}
	printf("请输入删除的位置：");
	scanf("%d",&i);
	status=ListDelete_Sq(&L,i,&e);	/*删除线性表的第i个元素，用e返回其值*/
	if(status)
	{
		printf("\n被删除元素的值为：%d",e);
		printf("\n进行删除操作后");
		PrintSqList(L);
	}
	else
	{
		printf("\n删除失败！");
		return 0;
	}
	i=LocateElem_Sq(L,15);
/*在顺序表L中查找第i个值与15相等的元素的位序*/
	printf("其值与15相等的元素在线性表中的位序为：%d\n",i);
	i=LocateElem_Sq(L,36);
/*在顺序表L中查找第i个值与36相等的元素的位序*/
	printf("其值与36相等的元素在线性表中的位序为：%d\n",i);
	printf("请输入读取元素的位置：");
	scanf("%d",&i);
	status=Get_SqList(L,i,&e);
	if(status)
		printf("\n读取相应位置的元素的值为：%d\n",e);
	free(L.elem);
	return 0;
}