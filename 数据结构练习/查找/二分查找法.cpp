#include<stdio.h>
#define max 100
typedef struct
{
	int key;
	char data;
}record;
typedef struct
{
	record r[max];
	int length;
}seqtable;
int binarysearch(seqtable sq,int k)
{
	int low,high,mid;
	low=1;
	high=sq.length;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(sq.r[mid].key<k)
			low=mid+1;
		else
		{
			if(sq.r[mid].key>k)
				high=mid-1;
			else
				break;
		}
	}
	if(low>high)
		return 0;
	else
		return mid;
}
void main()
{
	seqtable sq;
	int rec,k,i,len,ch;
	printf("��������ұ�ĳ���:");
	scanf("%d",&len);
	sq.length=len;
	printf("����%d����¼�Ĺؼ���ֵ\n",len);
	for(i=1;i<=len;i++)
	{
		scanf("%d",&ch);
		sq.r[i].key=ch;
	}
	printf("������Ҫ���ҵ�Ԫ��\n");
	scanf("%d",&k);
	rec=binarysearch(sq,k);
	if(rec==0)
		printf("�ò��ұ���û��������¼\n");
	else
		printf("��Ԫ���ڱ��е�λ��Ϊ%d\n",rec);
}