#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define M 1100
int n,m,t,ans,cas=1,flag;
int book[M],mapp[M][M],dis[M],vis[M];
int out[M],in[M],value[M],pre[M];//pre�����û���������һ����������ĵ����ÿ���������һ������
struct edge
{
	int u,v,w;  //�洢�ߵ���㣬�յ��Ȩֵ
}e[M];
int prime()
{
	int i,j;
	int sum=0,k=1,idex;
	memset(book,0,sizeof(book));
	for(i=1;i<=n;i++)   //��ʼ��
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				mapp[i][j]=0;
			else
				mapp[i][j]=inf;
		}
	}
	for(i=0;i<m;i++)
	{
		if(vis[i]==1)
			mapp[e[i].u][e[i].v]=mapp[e[i].v][e[i].u]=e[i].w;
	}
	for(i=1;i<=n;i++)
		pre[i]=1;  //�ʼ��С��������ֻ��һ��1�Ŷ���
	for(i=1;i<=n;i++)
		dis[i]=mapp[i][1];
	book[1]=1;
	int min;
	for(i=1;i<n;i++)
	{
		min=inf;
		for(j=1;j<=n;j++)
			if(!book[j]&&dis[j]<min)
			{
				min=dis[j];
				idex=j; 
			}
			
			book[idex]=j;//�Ѿ��ҵ���һ������idex�ˣ���Ҫ��¼idex������һ������
			out[k]=pre[idex];  //
			in[k]=idex;
			value[k++]=min;   //ѡȡ�ߵ�Ȩֵ���浽value������
			sum+=min;
			if(min==inf)
			{
				return -1;
			}
			for(int r=1;r<=n;r++)
			{
				if(!book[r]&&dis[r]>mapp[idex][r])
				{
					dis[r]=mapp[idex][r];
					pre[r]=idex;
				}
			}
	}
	return sum;
}
void print(int n)
{
	printf("��%d����С��������\n",cas++);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==i)
				printf("%d-%d :%d \n",out[j],in[j],value[j]);
			else
				printf("%d-%d :%d  ",out[j],in[j],value[j]);
		}
	}	
	
}
void dfs(int t,int num,int sum)
{
	if(sum>ans||num>n-1)
		return;
	if(t==m)
	{
		if(num==n-1&&sum==ans)//�ߵĸ���
		{
			int temp=prime();
			if(temp==ans)
				print(n-1);  //����������ӡ��·��
		}
		return;
	}
	vis[t]=1;  //���Ϊ1,
	dfs(t+1,num+1,sum+e[t].w); //ѡ�õ�ǰ��
	vis[t]=0;  //ȡ�����
	dfs(t+1,num,sum);
}

int main()
{
    scanf("%d %d",&n,&m);
    int i,j,r;
    for(i=1; i<=n; i++)//��ʼ��
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
    //��prim�ж��Ƿ�����С���������о������С����С��������Ȩֵ
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
        printf("û����С������������������!\n");
    else
        dfs(0,0,0);  //����Ѱ����С�������Ĳ�ͬ·��
    return 0;
}
/*
3 3
1 2 1
2 3 2
3 1 3
һ��
4 4
1 2 2
2 3 2
3 4 2
4 1 2
����
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
��ʮ����
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
һ��
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
����
*/