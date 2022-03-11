#include<stdio.h>
#include<algorithm>
using namespace std;
int father[100],min,num;  //������Ÿ��׽ڵ�
int path[100];    //��������ѡ�ߵ�˳��
int n,m;
typedef struct node
{
	int from;    
	int end;
	int dis;   //��¼Ȩֵ
}edged[100];
edged e;
int cmp(node x,node y)  //sort�����е�������
{
	//	if(x.dis!=y.dis)
	return x.dis<y.dis;//����Ȩֵ��С��������
	//return x.from<y.from; //��Ȩֵ�൱�����������С��������
}

int find_root(int x)//���Ҹ��ڵ�
{
	if(x!=father[x])
		father[x]=find_root(father[x]);
	return father[x];
}
int merge(int x,int y)   //�ж��Ƿ���Ժϲ�
{
	int t1=find_root(x);
	int t2=find_root(y);
	if(t1!=t2)   //�������ͬһ�������У��Ϳ��Ժϲ�
	{
		father[t2]=t1;
		return 1;
	}
	return 0;
}
void print(int sum)
{
	if(min<sum)  //sum����min,��ô������Ͳ�����С������
		return;
	if(sum<min)  //�޸���С��������ֵ
		min=sum;
	printf("�� %d ����С��������ȨֵΪ%d:\n",num++,sum);
	for(int i=1;i<=n-1;i++)   //n�����㣬��n-1����
	{
		for(int j=1;j<=i;j++)
		{
			int k=path[j];
			printf("%c-%c:%d  ",'A'+e[k].from-1,'A'+e[k].end-1,e[k].dis);
		}
		printf("\n");
	}
	return;
}
void kruskal(int cur,int num,int sum)   //��cur���ߣ�������������num���ߣ���������Ȩֵ������sum
{
	if (cur>m)
		return ;
	if(num==n)
	{
		print(sum);
		return ;
	}
	int k=cur;
	while(k<=m&&e[k].dis==e[k+1].dis)  //�ߵ�Ȩֵ��ȣ���ȵı���ֻȡһ����
		k++;
	if(k==cur)  //û��Ȩֵ��ȵıߣ������Ȩֵ�ı�ֻ��һ���������Ȩֵ�ı�ֻ��һ��
	{
		if(merge(e[cur].from,e[cur].end))//����һ��������ͼ�����С������
		{
			path[num]=cur;  //����·����
			kruskal(cur+1,num+1,sum+e[cur].dis); //�ж���һ���ߣ��������еıߵ�������1
		}
		else(cur+1,num,sum);  //��ͬһ��������ж���һ����
		return;
	}
	//��������Ȩֵ�ı��ж�����ִ���������
	int temp[100];
	int i;
	for(i=1;i<=n;i++)//���׽ڵ��һ�飬��¼ԭֵ
		temp[i]=father[i];
	for(i=cur;i<=k;i++)
	{
		if(merge(e[i].from,e[i].end))
		{
			path[num]=i;
			if(k!=m&&i==k)
				kruskal(i+1,num+1,sum+e[i].dis);
			else
				kruskal(cur,num+1,sum+e[i].dis);
			for(int i=1;i<=n;i++)  //�ָ�ԭֵ
				father[i]=temp[i];
		}
	}
}
int main()
{
	int i;
	min=99999;
	num=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		father[i]=i;   //��ʼ���Լ��ĸ��׽ڵ�Ϊ�Լ�
	int x,y,z;
	for(i=1;i<=m;i++)
	{scanf("%d%d%d",&x,&y,&z);
	e[i].from=x;
	e[i].end=y;
	e[i].dis=z;
	}
	sort(e+1,e+m+1,cmp);
	kruskal(1,1,0);
	return 0;	
}
/*
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2

6 7
1 2 1
1 3 2
4 6 3
5 6 3
2 4 1
3 4 1
2 5 1
*/