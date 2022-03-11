/*输入一行字符，统计其中有多少个单词，单词之间用空格分隔开。
输入：I am a superman!
输出：4个单词。*/
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
	printf("%d个单词。\n",total);
	return 0;
 }
