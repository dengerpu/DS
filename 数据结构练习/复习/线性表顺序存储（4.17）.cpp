#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define maxsize 100
typedef struct node
{
	int a[maxsize];
	int length;
}Node,*SeqList;
void creat_list(SeqList L)   //����
{
	printf("���������鳤��\n");
	int n,i;
	scanf("%d",&n);
	L->length=n;
	if(n>maxsize-1)
	{
		printf("������Χ\n");
		exit(0);
	}
	printf("����������Ԫ��\n");
	for(i=0;i<L->length;i++)
	{
		scanf("%d",&L->a[i]);
	}
}
void out_list(SeqList L)  //���
{
	printf("���\n");
	int i;
	for(i=0;i<L->length;i++)
		printf("%d ",L->a [i]);
	printf("\n");
}
void insert_list(SeqList L)   //����
{
	int i,j,x;
	printf("������Ҫ���ڵڼ�����ǰ�Լ�Ҫ�������\n");
	scanf("%d%d",&i,&x);
	if(i<=0||i>L->length+1)
	{
		printf("�������\n");
		exit(0);
	}
	L->a [i-1]=x;
	for(j=L->length ;j>i-1;j--)
		L->a [j]=L->a [j-1];
	L->length++;
	out_list(L);		
}
void delete_list(SeqList L)  //ɾ��
{
	int i,j;
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&i);
	if(i<=0||i>=L->length+1)
	{
		printf("ɾ������\n");
		exit(0);
	}
	for(j=i-1;j<L->length;j++)
		L->a [j]=L->a [j+1];
	L->length --;
	out_list(L);
}
void loc1_list(SeqList L)  //��λ����
{
	printf("������Ҫ���ҵڼ�����\n");
	int i;
	scanf("%d",&i);
	if(i<=0||i>=L->length)
	{
		printf("���Ҵ���\n");
		exit(0);
	}
	printf("%d\n",L->a [i-1]);
}
void loc2_list(SeqList L)  //��ֵ����
{
	int x,i,j=1;
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&x);
	for(i=0;i<L->length ;i++)
		if(x==L->a [i])
		{
			j=0;
			printf("%dΪ��%d����\n",x,i+1);
		}
		if(j==1)
			printf("���޴���\n");
}
void length_list(SeqList L)  //��
{
	printf("����Ϊ%d\n",L->length );
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

/*����
void loc_list()
{
 int e��i=0;
 printf("������Ҫ���ҵ���\n");
  scanf("%d",&e);
while(i<L->length&&L->a[i]!=e)
    i++;
if(i<L->length)
  return (i+1);
else
  return -1;
}
*/