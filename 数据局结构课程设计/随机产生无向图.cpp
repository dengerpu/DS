#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (void)
{
	int j, k,b=0;
	int n,m,q;
	srand(time(NULL));								//��ʱ��Ϊ���Ӳ�����ͬ�������
	scanf("%d%d",&n,&m);   //nΪ��������mΪ����
	printf ("digraph \n");	
		for (j = 1; j < n; j++)
		{
			for (k=j+1; k <=n; k++)
				if ( (rand () % 100) <50) //�ٷ�֮50�ĸ��ʲ���
				{	
					b++;
					if(b<=m)
					{
						q=rand()%100+1;
						printf ("(%d,%d) %d\n", j,k,q); /* An Edge.  *///���j,k+nodes;
					}
				}
		}			
	printf ("\n");
	return 0;
}