#include<stdio.h>
#include<malloc.h>
#include<math.h>					//����fabs();����ֵ�������õ�
#include<string.h>
#define max 100
typedef struct node
{
	char firstaddress[5];				//�׵�ַ
	int data;
	char endaddress[5];					//β��ַ
	struct node *next;
}*Linklist,Node;
typedef struct node1				//����ṹ������������������
{
	char a[5];							//�׵�ַ
	int data1;
	char b[5];							//β��ַ
	int flag;						//��������Ƿ�ѡ��
}array[max];
void enter(array v,int n)					//��������
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
								// ����������Ӧ���������ʱ���д�á���
    a->next = NULL;
    b->next = NULL;
    Linklist p = L->next;// ����L���ƶ�ָ��
    Linklist aTail = a, bTail = b;// ָ��a,b��β
    while (p != NULL) {
        Linklist q = a->next;// ����a���ƶ�ָ��
        int flag = 0;
        while (q != NULL) {
            if (fabs(p->data) == fabs(q->data)) {
                flag = 1;
                break;
            }
            q = q->next;
        }
        // �����µĽ��
        Linklist newNode = (Linklist)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->data = p->data;
        strcpy(newNode->firstaddress, p->firstaddress);
        strcpy(newNode->endaddress, p->endaddress);
 
        if (flag) {// a���Ѿ��У����ظ��ģ���ӵ�bĩβ
            bTail->next = newNode;
            bTail = bTail->next;
        } else {// ���ظ�����ӵ�aĩβ
            aTail->next = newNode;
            aTail = aTail->next;
        }
        p = p->next;// ����
    }
}
void print(Linklist L)    //�������
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
	scanf("%s %d",firstaddress,&n);					//�����׵�ַ��Ҫ������������
	enter(v,n);
    creat(L,firstaddress,n,v);
	deleteRepeated(L,a,b);
	print(a);
	print(b);
	return 0;
}