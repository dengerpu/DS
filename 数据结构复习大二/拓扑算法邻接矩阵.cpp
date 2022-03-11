#include<stdio.h>
typedef struct
{
	int d[100];
	int top;
}stack;
void initstack(stack *s)  //��ʼ��˳��ջ
{
	s->top=-1;
}
void push(stack *s, int e)   //��ջ
{
	s->top++;
	s->d[s->top]=e;
}
void pop(stack *s,int *e)		//��ջ
{
	*e=s->d[s->top];
	s->top--;
}
void findid(int a[6][6],int b[])	//�����������
{
	int i,j;
	for(i=0;i<6;i++)
		b[i]=0;
	for(i=0;i<6;i++)		
		for(j=0;j<6;j++)
			if(a[i][j]==1)
				b[j]++;
}
void toposort(int a[6][6],int b[])
{
	int i,count=0,e,p;
	stack s;
	initstack(&s);
	for(i=0;i<6;i++)
		if(b[i]==0)
			push(&s,i+1);
		while(s.top!=-1)  //ջ��Ϊ��
		{
			pop(&s,&e);
			printf("%d ",s.d[e-1]);
			count++;
			p=e-1;
			for(i=0;i<6;i++)
			{
				if(a[p][i]==1)
					b[i]--;
				if(b[i]==0)//���������ѭ������Ϊ����ȷ����û�б������
					push(&s,i+1);
			}
			
		}
		if(count<6) printf("���ڻ�·\n");
		else
			printf("�����ڻ�·\n");
}
int main()
{
	int a[6][6]={{0,1,1,1,0,0},{0,0,0,0,0,0},{0,1,0,0,1,0},{0,0,0,0,1,0},{0,0,0,0,0,0},{0,0,0,1,1,0}};
	int b[6];
	findid(a,b);
	toposort(a,b);
	return 0;
}