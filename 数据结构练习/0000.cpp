#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int a[100];
	int length;
}seqlist;
void initlist(seqlist *l)   //��ʼ��
{
	l=(seqlist *)malloc(sizeof(struct node));
	l->length=0;
}
void outlist(seqlist *l)
{
	int i;
	for(i=0;i<l->length;i++)
		printf("%d ",l->a[i]);
	printf("\n");
}
void listlength(seqlist *l)   //��������
{
	printf("%d\n",l->length);
}
void getdata(seqlist *l)
{
	int i;
	printf("������Ҫ��ȡ�ڼ���Ԫ��");
	scanf("%d",&i);
	printf("%d\n",l->a[i-1]);
}
void insertlist(seqlist *l)
{
	int i,e,j;
	printf("��������ڵڼ����Լ�Ҫ�������");
		scanf("%d%d",&i,&e);
	for(j=l->length;j>=i;j--)
		l->a[j]=l->a[j-1];
	l->a[i-1]=e;
	l->length++;
	outlist(l);
}
void dellist(seqlist *l)
{
	int i,j;
	printf("������Ҫɾ���ڼ�����\n");
	scanf("%d",&i);
	for(j=i-1;j<l->length;j++)
		l->a[j]=l->a[j+1];
	l->length --; 
	outlist(l);
}
void creatlist(seqlist *l)
{
	int n,i;
	printf("���������鳤��\n");
	scanf("%d",&n);
	l->length=n;
	for(i=0;i<l->length;i++)
		scanf("%d",&l->a[i]);
	outlist(l);
}

main()
{
seqlist l;
//l=(seqlist)malloc(sizeof(struct node));
initlist(&l);
creatlist(&l);
outlist(&l);
listlength(&l);
getdata(&l);
insertlist(&l);
dellist(&l);
}