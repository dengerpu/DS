#include<stdio.h>
int SeqSearch(int a[],int length,int k)   //�����ü��ӵ�˳����ҷ���,a[0]�����Ԫ��
{
	int i=length;
	while(i>=1&&a[i]!=k)
		i--;
	if(i>=1)
		return i;
	else
		return 0;	
}
int main()
{
	int a[100],n,i,key,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("������Ҫ���ҵ���\n");
	scanf("%d",&key);
	k=SeqSearch(a,n,key);
	if(k>=1)
		printf("Ҫ���ҵ���Ϊ��%d��\n",k);
	else
		printf("û�в��ҵ������\n");
	return 0;
}
//�������ַ���������ͨ��forѭ��.do whileѭ����ʵ��