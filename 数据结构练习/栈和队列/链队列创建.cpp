#include<stdio.h>
#include<malloc.h>
typedef struct node  
{
    int data;
    struct node *next;
}*Qnode;
typedef struct     
{
    Qnode front;
    Qnode rear;
}*linkqueue;
void creat_queue(linkqueue l)
{
    int i, n,x;
	Qnode p;
    printf("请输入队列长度\n");
    scanf("%d", &n);
	printf("请输入队列元素\n");
    for (i = 0; i < n; i++)
    {   
        scanf("%d", &x);
        p = (node*)malloc(sizeof(struct node)); 
        p->data = x;
        p->next = NULL;
        l->rear->next = p;
        l->rear = p;
    }
	
}
void out_queue(linkqueue l)
{
    node* p;
    p = l->front->next;
    printf("输出\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void main()
{
    linkqueue l ;
    l->front =(Qnode)malloc(sizeof(node));
	l->rear=l->front;
    l->front->next = NULL;
    creat_queue(l);
    out_queue(l);
}