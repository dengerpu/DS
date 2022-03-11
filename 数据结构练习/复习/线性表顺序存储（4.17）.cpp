#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define maxsize 100
typedef struct node
{
	int a[maxsize];
	int length;
}Node,*SeqList;
void creat_list(SeqList L)   //创建
{
	printf("请输入数组长度\n");
	int n,i;
	scanf("%d",&n);
	L->length=n;
	if(n>maxsize-1)
	{
		printf("超出范围\n");
		exit(0);
	}
	printf("请输入数据元素\n");
	for(i=0;i<L->length;i++)
	{
		scanf("%d",&L->a[i]);
	}
}
void out_list(SeqList L)  //输出
{
	printf("输出\n");
	int i;
	for(i=0;i<L->length;i++)
		printf("%d ",L->a [i]);
	printf("\n");
}
void insert_list(SeqList L)   //插入
{
	int i,j,x;
	printf("请输入要插在第几个数前以及要插入的数\n");
	scanf("%d%d",&i,&x);
	if(i<=0||i>L->length+1)
	{
		printf("插入错误\n");
		exit(0);
	}
	L->a [i-1]=x;
	for(j=L->length ;j>i-1;j--)
		L->a [j]=L->a [j-1];
	L->length++;
	out_list(L);		
}
void delete_list(SeqList L)  //删除
{
	int i,j;
	printf("请输入要删除第几个数\n");
	scanf("%d",&i);
	if(i<=0||i>=L->length+1)
	{
		printf("删除错误\n");
		exit(0);
	}
	for(j=i-1;j<L->length;j++)
		L->a [j]=L->a [j+1];
	L->length --;
	out_list(L);
}
void loc1_list(SeqList L)  //按位查找
{
	printf("请输入要查找第几个数\n");
	int i;
	scanf("%d",&i);
	if(i<=0||i>=L->length)
	{
		printf("查找错误\n");
		exit(0);
	}
	printf("%d\n",L->a [i-1]);
}
void loc2_list(SeqList L)  //按值查找
{
	int x,i,j=1;
	printf("请输入要查找的数\n");
	scanf("%d",&x);
	for(i=0;i<L->length ;i++)
		if(x==L->a [i])
		{
			j=0;
			printf("%d为第%d个数\n",x,i+1);
		}
		if(j==1)
			printf("查无此数\n");
}
void length_list(SeqList L)  //表长
{
	printf("长度为%d\n",L->length );
}
main()
{
	SeqList L;
	L=(SeqList)malloc(sizeof(Node));
	creat_list(L);
	out_list(L);
	insert_list(L);
	length_list(L);
	delete_list(L);
	loc1_list(L);
	loc2_list(L);
}

/*查找
void loc_list()
{
 int e，i=0;
 printf("请输入要查找的数\n");
  scanf("%d",&e);
while(i<L->length&&L->a[i]!=e)
    i++;
if(i<L->length)
  return (i+1);
else
  return -1;
}
*/