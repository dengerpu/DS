//�����ű��ʽ����
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int data;//���۶������������������������int�ͱ��������� 
    node *next;
}LinkStackNode,*LinkStack;
void InitStack(LinkStack *S)
{//��ʼ����ջ 
    *S = (LinkStack)malloc(sizeof(LinkStackNode));
    (*S)->next = NULL;
}
int Push(LinkStack top, int x)
{// ��ջ���� 
    LinkStackNode *temp;
    temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
    if(temp == NULL) return 0;
    temp->data = x;
    temp->next = top->next;
    top->next = temp;
    return 1;
}
int Pop(LinkStack top, int *x)
{//��ջ���� 
    LinkStackNode *temp;
    temp = top->next;
    if(temp == NULL) return 0;
    *x = temp->data;
    top->next = temp->next;
    free(temp);
    return 1;
}
int GetNum(char ch)
{//�����ַ���Ӧ������ 
    return ch - '0';
}
bool IsEmpty(LinkStack top)
{//ջΪ�շ��ؼ� 
    if(top->next == NULL) return false;
    return true;
}
int GetTop(LinkStack top)
{//����ջ��Ԫ�� 
    if(top->next == NULL) return 1;
    return top->next->data;
}
char Compare(char ch1, char ch2)
{//ʵ����������ȼ��Ƚ� 
    switch(ch1)
	{
        case '#':
			switch(ch2)
			{
				case '#': return '=';
				case '+':
				case '-':
				case '*':
				case '/':
				case '^': return '<';
			}
        case '+':
            switch(ch2)
			{
                case '#': return '>';
                case '+':
                case '-': return '=';
                case '*':
                case '/':
                case '^': return '<';
            }
        case '-':
            switch(ch2)
			{
                case '#': return '>';
                case '+':
                case '-': return '=';
                case '*':
                case '/':
                case '^': return '<';
            }
        case '*':
            switch(ch2)
			{
                case '#':
                case '+':
                case '-': return '>';
                case '*':
                case '/': return '=';
                case '^': return '<';
            }
        case '/':
            switch(ch2)
			{
                case '#':
                case '+':
                case '-': return '>';
                case '*':
                case '/': return '=';
                case '^': return '<';
            }
        case '^':
            switch(ch2)
			{
                case '#':
                case '+':
                case '-':
                case '*':
                case '/': return '>';
                case '^': return '=';
            }
    }
}
int Calculate(int a, char op, int b)
{//���� a op b ��ֵ 
    int c;
    switch(op)
	{
        case '-': c = a - b; break;
        case '+': c = a + b; break;
        case '*': c = a * b; break;
        case '/': c = a / b; break;
        case '^': c = pow(a, b); break;
        default : c = 0;
    }
    return c;
}
int ExpEvaluation()
{//ʵ�� 
    LinkStack ovs, optr;
    InitStack(&ovs);
    InitStack(&optr);
    Push(optr, (int)'#');
    printf("\n\nPlease input an expression(Ending with '#'):\n");
    char ch = getchar();
    int num = 0, a, b, t, op;
    while(ch != '#' || (char)GetTop(optr) != '#')
	{
        while(ch >= '0' && ch <= '9')
		{//������ֲ���һλ���֣�����ַ�ת��Ϊ����
            num = num * 10 + GetNum(ch);
            ch = getchar();
        }
        if(num != 0)
		{//���num��Ϊ0���OVSջ 
            Push(ovs, num);
            num = 0;//��num���� 
        }
        else{
            switch(Compare(ch, (char)GetTop(optr)))
			{//����������ȼ����бȽϣ�ʵ�ֶ�Ӧ���ֹ�ϵ�Ĳ��� 
                case '>': Push(optr, (int)ch); ch = getchar(); break;
                case '=':
                case '<': Pop(optr, &op); 
                        Pop(ovs, &a);
                        Pop(ovs, &b);
                        t = Calculate(b, (char)op, a);
                        Push(ovs, t);
                        break;
            }
        }
    }
    t = GetTop(ovs);//ȡջ��Ԫ�أ�����ֵ 
    return t; 
}
int main()
{
    int ans = ExpEvaluation();
    printf("%d\n", ans);
    return 0;
}