
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node
{
	int date;
	int next;
}s[100010];
int book[100010];
int main()
{
	int a[100010];
	memset(a,0,sizeof a);
	memset(book,0,sizeof book);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		s[x].date=y;
		s[x].next=z;
	}
	int p=n;
	printf("%05d %d",n,s[n].date);
	book[abs(s[n].date)]=1;
	int k=0;
	while(1)
	{
		p=s[p].next;
		if(p==-1)
		{
			printf(" -1\n");
			break;
		}
		int pp=abs(s[p].date);
		if(!book[pp])
		{
			book[pp]=1;
			printf(" %05d\n%05d %d",p,p,s[p].date);
		}
		else
		a[k++]=p;
	}
	if(k>0){
	
	printf("%05d %d",a[0],s[a[0]].date);
	for(int i=1;i<k;i++)
	
		printf(" %05d\n%05d %d",a[i],a[i],s[a[i]].date);
		printf(" -1\n");
	}
	return 0;
}

