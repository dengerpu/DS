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
	printf("��������ұ�ĳ���\n");
	scanf("%d",&len);
	st.length=len;
	printf("����%d����¼�Ĺؼ���ֵ\n",len);
	for(i=1;i<=len;i++)
	{
		scanf("%d",&ch);
		st.r[i].key=ch;
	}
	printf("������Ҫ���ҵ�Ԫ��\n");
	scanf("%d",&k);
	rec=seqsearch(st,k);
	if(rec==0)
		printf("��Ԫ�ز�����\n");
	else
		printf("��Ԫ���ڱ��е�λ��Ϊ��%d\n",rec);
}