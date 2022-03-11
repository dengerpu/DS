#include<stdio.h>
#include<malloc.h>
#include<math.h>					//调用fabs();绝对值函数会用到
#include<string.h>
#define max 100
typedef struct node
{
	char firstaddress[5];				//首地址
	int data;
	char endaddress[5];					//尾地址
	struct node *next;
}*Linklist,Node;
typedef struct node1				//这个结构体用来存放输入的数据
{
	char a[5];							//首地址
	int data1;
	char b[5];							//尾地址
	int flag;						//用来标记是否被选过
}array[max];
void enter(array v,int n)					//输入数据
{
	for(int i=0;i<n;i++)
	{
		scanf("%s%d%s",&v[i].a,&v[i].data1,&v[i].b);
		v[i].flag=0;
	}
}
void creat(Linklist L,char address[],int n,array v)
{
	Linklist p,s;
	p=L;
	int x=n,i;
	while(x!=0)
	{
		for(i=0;i<n;i++)
			if(v[i].flag==0)
			{
				if(strcmp(v[i].a,address)==0)
				{
					s=(Linklist)malloc(sizeof(Node));
					s->data=v[i].data1;
					strcpy(s->firstaddress,v[i].a);
					strcpy(s->endaddress,v[i].b);
					p->next=s;
					p=s;
					p->next=NULL;
					strcpy(address,v[i].b);
					v[i].flag=1;
				}
			}
			x--;
	}
	
}
   void deleteRepeated(Linklist L, Linklist a, Linklist b) {
								// 下面这两步应该在申请的时候就写好。。
    a->next = NULL;
    b->next = NULL;
    Linklist p = L->next;// 遍历L的移动指针
    Linklist aTail = a, bTail = b;// 指向a,b的尾
    while (p != NULL) {
        Linklist q = a->next;// 遍历a的移动指针
        int flag = 0;
        while (q != NULL) {
            if (fabs(p->data) == fabs(q->data)) {
                flag = 1;
                break;
            }
            q = q->next;
        }
        // 申请新的结点
        Linklist newNode = (Linklist)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->data = p->data;
        strcpy(newNode->firstaddress, p->firstaddress);
        strcpy(newNode->endaddress, p->endaddress);
 
        if (flag) {// a中已经有，即重复的，添加到b末尾
            bTail->next = newNode;
            bTail = bTail->next;
        } else {// 不重复，添加到a末尾
            aTail->next = newNode;
            aTail = aTail->next;
        }
        p = p->next;// 后移
    }
}
void print(Linklist L)    //输出链表
{
	Linklist p;
	p=L->next;
	while(p!=NULL)
	{
		printf("%s %d %s\n",p->firstaddress,p->data,p->endaddress);
		p=p->next;
	}
}
int main()
{
	int n;
	char firstaddress[5];
	Linklist L,a,b;
	array v;
	L=(Linklist)malloc(sizeof(Node));
	a=(Linklist)malloc(sizeof(Node));
	b=(Linklist)malloc(sizeof(Node));
	scanf("%s %d",firstaddress,&n);					//输入首地址和要输入数的数量
	enter(v,n);
    creat(L,firstaddress,n,v);
	deleteRepeated(L,a,b);
	print(a);
	print(b);
	return 0;
}