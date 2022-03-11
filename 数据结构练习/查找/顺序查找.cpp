#include<stdio.h>
#define max 20
typedef struct
{
	int key;
	char data;
}record;
typedef struct
{
	record r[max+1];
	int length;
}seqtable;
int seqsearch(seqtable st,int k)
{
	int i;
	st.r[0].key=k;
	i=st.length;
	while(st.r[i].key!=k)
		i--;
	return i;
}
void main()
{
	seqtable st;
	int rec,k,i,len,ch;
	printf("请输入查找表的长短\n");
	scanf("%d",&len);
	st.length=len;
	printf("输入%d个记录的关键字值\n",len);
	for(i=1;i<=len;i++)
	{
		scanf("%d",&ch);
		st.r[i].key=ch;
	}
	printf("请输入要查找的元素\n");
	scanf("%d",&k);
	rec=seqsearch(st,k);
	if(rec==0)
		printf("该元素不存在\n");
	else
		printf("该元素在表中的位置为：%d\n",rec);
}