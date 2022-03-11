#include<stdio.h>
#include<stdlib.h>
struct node
{
	char name[20];
	int age;
}stud[3];
void main()
{
	FILE *fp;
	char a[100];
	struct node stud[3];
	if((fp=fopen("file1.txt","w"))==NULL)
	{
		printf("can not open file\n");
		exit(0);
	}
	for(int i=0;i<3;i++)
	{
		scanf("%s%d",&stud[i].name,&stud[i].age);
		fprintf(fp,"%s,%d",stud[i].name,stud[i].age );
	}
	fclose(fp);
	if((fp=fopen("file1.txt","r"))==NULL)
	{
		printf("can not open file\n");
		exit(0);
	}
	int sum=0;
	for(i=0;i<3;i++)
	{
		fscanf(fp,"%d",&stud[i].age  );
		sum+=stud[i].age ;
	}
	printf("%d\n",sum);
	fclose(fp);
}