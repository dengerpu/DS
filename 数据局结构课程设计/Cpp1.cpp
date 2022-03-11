/*
思路：
在主函数中通过prim算法判断是否有最小生成树，如果有求出其权值，然后通过深搜，调用prim函数，
将其与主函数中权值相比较，求出其所有最小生成树，同时记录构造树的过程（out存边的起点，in存边的终点
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define M 1100
int n,m,t,ans,Cas=1,flag;
int book[M],mapp[M][M],dis[M],vis[M],dis1[M],book1[M];
int out[M],in[M],value[M],pre[M]; //pre数组存每个顶点的上一个离他最近的点就是每个顶点的上一个顶点
struct edge
{
    int u,v,w; //存储边的起点，终点和权值
} e[M];
int prim()
{
    int i,j;
    int sum=0,k=1,idex;
    memset(book,0,sizeof(book));
    for(i=1; i<=n; i++)//初始化
    {
        for(j=1; j<=n; j++)
        {
            if(i==j)
                mapp[i][j]=0;
            else
                mapp[i][j]=inf;
        }
    }
    for(i=0; i<m; i++)
    {
        if(vis[i]==1)
            mapp[e[i].u][e[i].v]=mapp[e[i].v][e[i].u]=e[i].w;
    }
    for( i=1; i<=n; i++)
        pre[i]=1; //最开始最小生成树里只有一个1号顶点,
    //继续向最小生成树里添加顶点，不管是添加哪一个，它的前一个点都是一号顶点，也只能是一号顶点
    for( i=1; i<=n; i++)
        dis[i]=mapp[i][1];
    book[1]=1;
    int min;
    for( i=1; i<n; i++)
    {
        min=inf;
        for(j=1; j<=n; j++)
        {
            if(!book[j]&&dis[j]<min)
            {
                min=dis[j];
                idex=j;
            }
        }
        book[idex]=1;
        //已经找到下一个点是idex了，对吧，很明显需要记录的就是 index 和它的 上一个顶点
        //已及这两个顶点所连边的权值，即Min
        out[k]=pre[idex];
        //index为这条边的终点，已知pre数组存的是每个顶点的上一个离他最近的顶点
        //它的上一个顶点，不就是这条边的起点，存到out数组里
        in[k]=idex; //这个点就是选取边的终点，存到in数组里
        value[k++]=min; //选取边的权值，存到value数组里
        sum+=min;
        if(min==inf)
        {
            return -1;
        }
        for(int r=1; r<=n; r++)
        {
            if(!book[r]&&dis[r]>mapp[idex][r])
            {
                dis[r]=mapp[idex][r];//这句话代表能够通过idex顶点松弛到r顶点的距离
                //既然已经通过idex顶点，把最小生成树到r的距离变得更短了
                //很明显，距离r顶点最近的上一个顶点就是idex了
                pre[r]=idex; //更新
            }
        }
    }
    return sum;
}
void Print(int n)
{
    printf("第%d棵最小生成树:\n",Cas++);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(j==i)
                printf("%d - %d : %d\n",out[j],in[j],value[j]);
            else
                printf("%d - %d : %d ,",out[j],in[j],value[j]);
        }//控制格式
    }
}
void Dfs(int t,int num,int sum)
{
    if(sum>ans||num>n-1)
        return ; //和超过最小生成树权值或者，边的数量超过n-1显然不符合，直接结束本轮搜索
    if(t==m)                //搜过所有边，结束
    {
        if(num==n-1&&sum==ans)  //排出掉一些权值小于最小生成树权值，和边不够的搜索结果
        {
            int temp=prim();  //边的和符合最小生成树了，看能否由这些边组成最小生成树
            if(temp==ans)
                Print(n-1);  //满足，打印此路径
        }
        return ;
    }
    vis[t]=1;  //标记为1，代笔此边被选用过
    Dfs(t+1,num+1,sum+e[t].w); //选用当前边
    vis[t]=0;  //取消标记
    Dfs(t+1,num,sum);  //不选用当前边
}

int main()
{
    scanf("%d %d",&n,&m);
    int i,j,r;
    for(i=1; i<=n; i++)//初始化
    {
        for(j=1; j<=n; j++)
        {
            if(i==j)
                mapp[i][j]=0;
            else
                mapp[i][j]=inf;
        }
    }
    flag=0;
    ans=0;
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
        mapp[e[i].u][e[i].v]=mapp[e[i].v][e[i].u]=e[i].w;
    }
    int idex1;
    //用prim判断是否有最小生成树，有就求出最小的最小生成树的权值
    memset(book1,0,sizeof(book1));
    for( i=1; i<=n; i++)
        dis1[i]=mapp[i][1];
    book1[1]=1;
    int min1;
    for(i=1; i<n; i++)
    {
        min1=inf;
        for(j=1; j<=n; j++)
        {
            if(!book1[j]&&dis1[j]<min1)
            {
                min1=dis1[j];
                idex1=j;
            }
        }
        book1[idex1]=1;
        ans+=min1;
        if(min1==inf)
        {
            flag=1;
        }
        for(r=1; r<=n; r++)
        {
            if(!book1[r]&&dis1[r]>mapp[idex1][r])
            {
                dis1[r]=mapp[idex1][r];
            }
        }
    }
    printf("%d\n",ans);
    if(flag)
        printf("没有最小生成树，请重新输入!\n");
    else
        Dfs(0,0,0);  //深搜寻找最小生成树的不同路径
    return 0;
}
/*
3 3
1 2 1
2 3 2
3 1 3
一条
4 4
1 2 2
2 3 2
3 4 2
4 1 2
四条
6 9
1 2 1
1 4 1
4 3 1
2 3 1
4 5 1
2 6 1
3 5 1
3 6 1
5 6 1
六十六条
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
一条
//
9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 9 7
2 8 11
3 9 2
7 9 6
3 6 4
4 6 14
1 8 8
37
两条
*/
