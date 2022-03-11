#include <stdio.h>
#include<string.h>
int main()
{
	int i,sum = 0;
	char str[20];
	gets(str);
	for(i=0;str[i]!='\0';i++)
		if(str[i] >= '0' && str[i] <= '9')
			sum = sum*10 + int(str[i]-48);
		printf("%d",sum);
		return 0;
}