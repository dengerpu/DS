#include<stdio.h>
int SeqSearch(int a[],int length,int k)   //���ü��ӵ�˳����ҷ���,a[0]�����Ԫ�أ�Ԫ�ش�a[1]��ʼ��š�
{
	int i=length;
	a[0]=k;  
	while(a[i]!=k)
		i--;
	return i;
	
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
	if(k!=0)
		printf("Ҫ���ҵ���Ϊ��%d��\n",k);
	else
		printf("û�в��ҵ������\n");
	return 0;
}
//˼�� ���a[0]�����Ԫ����ô�죿
//�𰸣�a[-1]����Ϊ�����ڣ����û���ҵ������ص�ֵΪ-1��