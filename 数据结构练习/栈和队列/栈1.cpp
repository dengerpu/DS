#include<stdio.h>
#include<malloc.h>
typedef struct stact
{
	int a[100];
	int top;
}*seqstact;
void creat_stact(seqstact L)   //����ջ
{
	int i,n;
	printf("������ջ����\n");
	scanf("%d",&n);
	L->top=n;
	printf("������Ԫ��\n");
	for(i=0;i<L->top;i++)
	{
		scanf("%d",&L->a[i]);
	}
}
void out_stact(seqstact L)  //���ջ
{
	int i;
	printf("���\n");
	for(i=0;i<L->top;i++)
		printf("%d ",L->a[i]);
	printf("\n");
}
void insert_stact(seqstact L)  //��ջ
{int n;
printf("������Ҫ�������\n");
scanf("%d",&n);
L->a[L->top]=n;
L->top++;
out_stact(L);
}
void dele_stact(seqstact L)
{
	L->top--;
	out_stact(L);
}
void main()
{
	seqstact L;
	L=(seqstact)malloc(sizeof(struct stact));
	creat_stact(L);
	out_stact(L);
	insert_stact(L);
	dele_stact(L);
}