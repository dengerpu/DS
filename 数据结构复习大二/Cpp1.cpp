/*����һ���ַ���ͳ�������ж��ٸ����ʣ�����֮���ÿո�ָ�����
���룺I am a superman!
�����4�����ʡ�*/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int i,l,total=1;
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++)
		if(a[i]==' ')
			total++;
	printf("%d�����ʡ�\n",total);
	return 0;
 }
