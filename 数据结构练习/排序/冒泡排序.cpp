#include<stdio.h>
void main()
{
	int i,j,a[10],t;
	printf("��������Ҫ�����10����\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<9;i++)
		for(j=0;j<9-i;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
			printf("ð������������\n");
			for(i=0;i<10;i++)
				printf("%d ",a[i]);
			printf("\n");
}