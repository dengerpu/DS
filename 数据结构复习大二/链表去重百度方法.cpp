#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct node{
    int data;
    int next;
}list[100005];
int main()
{
    int head, n;
    scanf("%d%d",&head,&n);
    while(n--)
    {
        int adress;
        scanf("%d",&adress);
        scanf("%d%d",&list[adress].data,&list[adress].next);
    }
    int ans[100005], k1 = 0;
    int res[100005], k2 = 0;
    bool vis[100005];
    memset(vis, 0, sizeof(vis));    //��bool���͵�����ȫֵΪ0
    int p = head;                   //�ҵ�ͷ�ڵ�
    while(p != -1)
    {
        int m = abs(list[p].data);
        if(!vis[m])                 //����������ֵ�������vis�������±�Ϊm����Ӧ��ֵ�У���¼������Ϊ1
        {                           //ͬ�������ַp���ans�У�Ȼ��Ƚϣ����ظ��Ļ��Ͱ������ַp�ŵ�res������
            ans[k1++] = p;
            vis[m] = 1;
        }
        else
        {
            res[k2++] = p;
        }
        p = list[p].next;
    }
    printf("%05d", head);
    for(int i = 1; i < k1; i++)
    {
        printf(" %d %05d\n%05d", list[ans[i-1]].data, ans[i], ans[i]);
    }
    printf(" %d -1\n", list[ans[k1-1]].data);
    if(k2 > 0)
    {
        printf("%05d", res[0]);
        for(int i = 1; i < k2; i++)
        {
            printf(" %d %05d\n%05d", list[res[i-1]].data, res[i], res[i]);
        }
        printf(" %d -1", list[res[k2-1]].data);
    }
    return 0;
}
