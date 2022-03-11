#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (void)
{
	int j, k,b=0;
	int n,m,q;
	srand(time(NULL));								//以时间为种子产生不同的随机数
	scanf("%d%d",&n,&m);   //n为顶点数，m为边数
	printf ("digraph \n");	
		for (j = 1; j < n; j++)
		{
			for (k=j+1; k <=n; k++)
				if ( (rand () % 100) <50) //百分之50的概率产生
				{	
					b++;
					if(b<=m)
					{
						q=rand()%100+1;
						printf ("(%d,%d) %d\n", j,k,q); /* An Edge.  *///输出j,k+nodes;
					}
				}
		}			
	printf ("\n");
	return 0;
}