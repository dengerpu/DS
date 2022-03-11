#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAXN 26+10
#define MAXM 100+10
#define INF 0x3f3f3f3f

int n,m,Min,num;//����������������¼����������СȨֵ����������Ȩֵ��
int f[MAXN];//���游�ڵ�
int path[MAXM];//����ѡ�ߵ�˳��

struct node
{
    int u;//��㣻
    int v;//�յ㣻
    int w;//Ȩֵ��
} e[MAXM];

void init()//��ʼ��
{
	int i;
    Min=INF;//���ֵ��
    num=1;//��С�������ĸ�����1��ʼ��
    for(i=1; i<=m; i++)//��ʼ��Ϊ0��
        e[i].u=e[i].v=e[i].w=0;
    for(i=1; i<=n; i++)//��ʼ��ÿ������ĸ��׽ڵ㶼���Լ���
        f[i]=i;
}

int cmp(node a,node b)//sort�����е�������
{
    if(a.w!=b.w)
        return a.w<b.w;//����Ȩֵ��С�������У�
    return a.u<b.u;//��Ȩֵ��ȣ����������С�������У�
}

int getf(int x)// ���Ҹ��ڵ�
{
    if(x!=f[x])
       f[x]=getf(f[x]);
    return f[x];
}

bool merge(int a,int b)//�жϺϲ�
{
    int t1=getf(a);
    int t2=getf(b);
    if(t1!=t2)//����ͬһ�������У��ͺϲ�������true
    {
        f[t1]=t2;
        return true;
    }
    return false;//���򷵻�false��
}

void Print(int sum)
{
    if(Min<sum)//sum����Min����ô������Ͳ�����С��������
        return ;
    if(sum<Min)//�޸���С��������ֵ��
        Min=sum;
    printf("�� %d ����С��������ȨֵΪ %d:\n",num++,sum);
    for(int i=1; i<=n-1; i++)//n�����㣬��n-1���ߣ�
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

void Kruskal(int cur,int num,int sum)//��cur���ߣ�������������num���ߣ���������Ȩֵ������sum�����׽ڵ�����飻
{
    if(cur>m)
        return ;
    if(num==n)
    {
        Print(sum);
        return ;
    }
    int k=cur;
    while(k<=m&&e[k].w==e[k+1].w)//�ߵ�Ȩֵ��ȣ���ȵı���ֻȡһ���ߣ�
        k++;
    if(k==cur)//û��Ȩֵ��ȵıߣ������Ȩֵ�ı�ֻ��һ����
    {
        if(merge(e[cur].u,e[cur].v))//����һ��������ͼ�����С��������
        {
            path[num]=cur;//����·���У�
            Kruskal(cur+1,num+1,sum+e[cur].w);//�ж���һ���ߣ��������еıߵ�������1���������е�Ȩֵ������e[cur].w;
        }
        else
            Kruskal(cur+1,num,sum);//��ͬһ����������ж���һ���ߣ�
        return ;
    }
    //������Ȩֵ�ı��ж�����ִ������Ĵ��룻
    int temp[MAXN];
	int i;
    for(i=1; i<=n; i++)//���׽ڵ��һ�飻��¼ԭֵ��
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
            for(int i=1; i<=n; i++)//�ָ�ԭֵ��
                f[i]=temp[i];
        }
    }
    return ;
}

int main()
{
    while(~scanf("%d %d",&n,&m))//����ͼ�Ķ���������ߵ�������
    {
        init();    // ��ʼ��
        for(int i=1; i<=m; i++)//m���ߣ�
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e+1,e+m+1,cmp);//sort���ţ�
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
