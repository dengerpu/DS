#include<stdio.h>
typedef struct
{
	int d[100];
	int top;
}stack;
void initstack(stack *s)  //初始化顺序栈
{
	s->top=-1;
}
void push(stack *s, int e)   //进栈
{
	s->top++;
	s->d[s->top]=e;
}
void pop(stack *s,int *e)		//出栈
{
	*e=s->d[s->top];
	s->top--;
}
void findid(int a[6][6],int b[])	//求各顶点的入度
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
		while(s.top!=-1)  //栈不为空
		{
			pop(&s,&e);
			printf("%d ",s.d[e-1]);
			count++;
			p=e-1;
			for(i=0;i<6;i++)
			{
				if(a[p][i]==1)
					b[i]--;
				if(b[i]==0)//会造成无限循环，因为不能确定有没有被输出了
					push(&s,i+1);
			}
			
		}
		if(count<6) printf("存在回路\n");
		else
			printf("不存在回路\n");
}
int main()
{
	int a[6][6]={{0,1,1,1,0,0},{0,0,0,0,0,0},{0,1,0,0,1,0},{0,0,0,0,1,0},{0,0,0,0,0,0},{0,0,0,1,1,0}};
	int b[6];
	findid(a,b);
	toposort(a,b);
	return 0;
}