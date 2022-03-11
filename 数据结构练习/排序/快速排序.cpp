#include<stdio.h>
typedef struct
{
	int key;
	char data;
}record;
int okpass(record r[],int low,int high)
{
	record x=r[low] ;
	while(low<high)
	{
		while(low<high&&r[high].key>=x.key)
			high--;
		if(low<high)
		{
			r[low]=r[high];
			low++;
		}
		while(low<high&&r[low].key<x.key)
			low++;
		if(low<high)
		{
			r[high]=r[low];
			high--;
		}
	}
	r[low]=x;
	return low;
}
void oksort(record r[],int low,int high)
{
	int pos;
	if(low<high)
	{
		pos=okpass(r,low,high);
		oksort(r,low,pos-1);
		oksort(r,pos+1,high);
	}
}

void main()
{
	int i,len;
	record r[20];
	printf("ÇëÊäÈë³¤¶È\n");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
		scanf("%d",&r[i].key);
	oksort(r,1,len);
	for(i=1;i<=len;i++)
		printf("%d ",r[i].key);
}