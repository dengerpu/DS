#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
	int elem[MAXSIZE];
	int front;
	int rear;
}LinkQueue;
int main()
{
	LinkQueue Q;
	InitQueue();
	return 0;
}
