#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAXN 26+10
#define MAXM 100+10
#define INF 0x3f3f3f3f

int n,m,Min,num;//顶点数，边数，记录生成树的最小权值，生成树的权值；
int f[MAXN];//保存父节点
int path[MAXM];//保存选边的顺序

struct node
{
    int u;//起点；
    int v;//终点；
    int w;//权值；
} e[MAXM];

void init()//初始化
{
	int i;
    Min=INF;//最大值；
    num=1;//最小生成树的个数从1开始；
    for(i=1; i<=m; i++)//初始化为0；
        e[i].u=e[i].v=e[i].w=0;
    for(i=1; i<=n; i++)//初始，每各顶点的父亲节点都是自己；
        f[i]=i;
}

int cmp(node a,node b)//sort函数中的排序函数
{
    if(a.w!=b.w)
        return a.w<b.w;//按照权值由小到大排列；
    return a.u<b.u;//当权值相等，按照起点由小到大排列；
}

int getf(int x)// 查找根节点
{
    if(x!=f[x])
       f[x]=getf(f[x]);
    return f[x];
}

bool merge(int a,int b)//判断合并
{
    int t1=getf(a);
    int t2=getf(b);
    if(t1!=t2)//不在同一个集合中，就合并，返回true
    {
        f[t1]=t2;
        return true;
    }
    return false;//否则返回false；
}

void Print(int sum)
{
    if(Min<sum)//sum大于Min，那么这棵树就不是最小生成树；
        return ;
    if(sum<Min)//修改最小生成树的值；
        Min=sum;
    printf("第 %d 棵最小生成树，权值为 %d:\n",num++,sum);
    for(int i=1; i<=n-1; i++)//n个顶点，有n-1条边；
    {
        for(int j=1; j<=i; j++)
        {
            int k=path[j];
            printf("%c-%c:%d  ",'A'+e[k].u-1,'A'+e[k].v-1,e[k].w);
        }
        printf("\n");
    }
    return ;
}

void Kruskal(int cur,int num,int sum)//第cur条边，生成树中已有num条边，生成树的权值现在是sum，父亲节点的数组；
{
    if(cur>m)
        return ;
    if(num==n)
    {
        Print(sum);
        return ;
    }
    int k=cur;
    while(k<=m&&e[k].w==e[k+1].w)//边的权值相等，相等的边中只取一个边；
        k++;
    if(k==cur)//没有权值相等的边，即这个权值的边只有一条；
    {
        if(merge(e[cur].u,e[cur].v))//不在一个集合里，就加入最小生成树；
        {
            path[num]=cur;//存入路径中；
            Kruskal(cur+1,num+1,sum+e[cur].w);//判断下一条边，生成树中的边的条数加1，生成树中的权值和增加e[cur].w;
        }
        else
            Kruskal(cur+1,num,sum);//在同一个集合里，就判断下一条边；
        return ;
    }
    //如果相等权值的边有多条，执行下面的代码；
    int temp[MAXN];
	int i;
    for(i=1; i<=n; i++)//父亲节点存一遍；记录原值；
        temp[i]=f[i];
    if(k!=m)
        k++;
    for(i=cur; i<=k; i++)
    {
        if(merge(e[i].u,e[i].v))
        {
            path[num]=i;
            if(k!=m&&i==k)
                Kruskal(i+1,num+1,sum+e[i].w);
            else
                Kruskal(cur,num+1,sum+e[i].w);
            for(int i=1; i<=n; i++)//恢复原值；
                f[i]=temp[i];
        }
    }
    return ;
}

int main()
{
    while(~scanf("%d %d",&n,&m))//输入图的顶点个数，边的条数；
    {
        init();    // 初始化
        for(int i=1; i<=m; i++)//m条边；
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e+1,e+m+1,cmp);//sort快排；
        Kruskal(1,1,0);
    }
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
