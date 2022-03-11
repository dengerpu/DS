#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 500000
int KeyList[max];
int main()
{
	clock_t start,end;
	int i,t,n,x,j;
	srand(time(NULL));
	printf("请输入要产生的数的个数");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		KeyList[i]=i;
	for(i=1;i<=n;i++)          
	{
		x=rand()%n+1;
		t=KeyList[x];
		KeyList[x]=KeyList[i];
		KeyList[i]=t;
	}
	start=clock();
	for(i=2;i<=n;i++)           //直接插入排序
	{
		KeyList[0]=KeyList[i];j=i-1;
		while(KeyList[0]<KeyList[j])
		{
			KeyList[j+1]=KeyList[j];
			j--;
		}
		KeyList[j+1]=KeyList[0];
	}
	end = clock();
	printf("共用时:%dms",(end-start)*1000/CLOCKS_PER_SEC);
	return 0;
}
