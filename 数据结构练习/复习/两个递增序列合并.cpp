#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int a[100];
	int length;
}*SeqList;
void creat_list(SeqList L)   //����
{
	printf("���������鳤��\n");
	int n,i;
	scanf("%d",&n);
	L->length=n;
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
main()
{
	SeqList A,B,C;
	A=(SeqList)malloc(sizeof(struct node));
	B=(SeqList)malloc(sizeof(struct node));
    C=(SeqList)malloc(sizeof(struct node));
	creat_list(A);
	creat_list(B);
	int i=0,j=0,k=0;
	while(i<A->length&&j<B->length)
	{
		if(A->a[i]<=B->a[j])
		{
			C->a[k]=A->a[i];
			i++;
			k++;
		}
		else
		{
			C->a[k]=B->a[j];
			j++;
			k++;
		}
	}
	while(i<A->length)
	{
		C->a[k]=A->a[i];
		i++;
		k++;
	}
	while(j<B->length)
	{
		C->a[k]=B->a[j];
		j++;
		k++;
	}
	C->length=k;
	out_list(C);	
}