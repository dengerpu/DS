#include<stdio.h>
#include<algorithm>
using namespace std;
int father[100],min,num;  //用来存放父亲节点
int path[100];    //用来保存选边的顺序
int n,m;
typedef struct node
{
	int from;    
	int end;
	int dis;   //记录权值
}edged[100];
edged e;
int cmp(node x,node y)  //sort函数中的排序函数
{
	//	if(x.dis!=y.dis)
	return x.dis<y.dis;//按照权值由小到大排列
	//return x.from<y.from; //当权值相当，按照起点由小到大排列
}

int find_root(int x)//查找根节点
{
	if(x!=father[x])
		father[x]=find_root(father[x]);
	return father[x];
}
int merge(int x,int y)   //判断是否可以合并
{
	int t1=find_root(x);
	int t2=find_root(y);
	if(t1!=t2)   //如果不在同一个集合中，就可以合并
	{
		father[t2]=t1;
		return 1;
	}
	return 0;
}
void print(int sum)
{
	if(min<sum)  //sum大于min,那么这棵树就不是最小生成树
		return;
	if(sum<min)  //修改最小生成树的值
		min=sum;
	printf("第 %d 棵最小生成树，权值为%d:\n",num++,sum);
	for(int i=1;i<=n-1;i++)   //n个顶点，有n-1条边
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
void kruskal(int cur,int num,int sum)   //第cur条边，生成树中已有num条边，生成树的权值现在是sum
{
	if (cur>m)
		return ;
	if(num==n)
	{
		print(sum);
		return ;
	}
	int k=cur;
	while(k<=m&&e[k].dis==e[k+1].dis)  //边的权值相等，相等的边中只取一个边
		k++;
	if(k==cur)  //没有权值相等的边，即这个权值的边只有一条，即这个权值的便只有一条
	{
		if(merge(e[cur].from,e[cur].end))//不在一个集合里，就加入最小生成树
		{
			path[num]=cur;  //存入路径中
			kruskal(cur+1,num+1,sum+e[cur].dis); //判断下一条边，生成树中的边的条数加1
		}
		else(cur+1,num,sum);  //在同一集合里，就判断下一条边
		return;
	}
	//如果有相等权值的边有多条，执行下面代码
	int temp[100];
	int i;
	for(i=1;i<=n;i++)//父亲节点存一遍，记录原值
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
			for(int i=1;i<=n;i++)  //恢复原值
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
		father[i]=i;   //初始化自己的父亲节点为自己
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