
#include<stdio.h>
#include<stdlib.h>
#define N 10
struct Student
{
	char name[20];
	long num;
	int score;
};
typedef struct Student student;
void save(student st[])
{
	FILE *fp;
	int i; 
	if((fp=fopen("file4.txt","w"))==NULL)
	{
		printf("cannot open file\n");
		return;
	}
	for(i=0;i<N;i++)
	{
		fwrite(&st[i],sizeof(student),1,fp);
	} 
	fclose(fp);
}
float ave()
{
	student st;
	float s=0;
	int i;
	FILE *fp;
	if((fp=fopen("file4.txt","r"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
   for(i=0;i<N;i++)
	{
		fread(&st,sizeof(struct Student),1,fp);
			s+=st.score;
	}
	s=s/N;
	return s;
}
int main()
{
	student stud[N]={"zy",1001,0,"sl",1002,0,"zhj",1003,0,"zzs",1004,0,"ly",1005,0,"jm",1006,0,"lf",1007,0,"zl",1008,0,"yl",1009,0,"hy",1010,0};
	int i;
	float s;
	for(i=0;i<N;i++)
		scanf("%d",&stud[i].score);
	//建立数据文件
	save(stud);     
	s=ave();
	printf("平均成绩为：%.2f\n",s);
	return 0;
}