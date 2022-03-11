//头结点-》首结点-》-》-》尾结点  （头结点作用，方便操作，并不存放有效数据。）
//头指针：指向头结点的指针变量
//尾指针：指向尾结点的指针变
#include<stdio.h>
typedef struct lnode
{
int data; //数据域
struct lnode *next; //指针域
}node ,*linklist;  //node等价于struct lnode ,linklist等价于struct lnode *;
//要插入一个q指针；
1.
r=p->next;    //写法一
p->next=q;
q->next=r;
2.
q->next=p->next;   //写法二
p->next=q;

