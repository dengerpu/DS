#include<stdio.h>

void soll(char *a)
{
	int i=0;
	int sort[129]={0};int n=0;
	while(a[i]!='\0')
	{
		sort[a[i]]++;
		if(sort[a[i]]==1)
			n++;
		i++;
	}
	int max,l;

	for( i=1;i<=n;i++)
	{
		max=1;l=0;
		for(int j=0;j<128;j++)
		{
			if(sort[j]>=max)
			{
				l=j;max=sort[j];
			}
		}
		printf("%c ",l);
		sort[l]=0;
	}
	return;
}
int main()
{
	char b[110];
	gets(b);
	soll(b);
	return 0;
}