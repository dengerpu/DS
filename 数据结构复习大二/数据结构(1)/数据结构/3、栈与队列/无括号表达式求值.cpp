//无括号表达式运算
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int data;//无论对于运算符还是运算数，都用int型变量来保存 
    node *next;
}LinkStackNode,*LinkStack;
void InitStack(LinkStack *S)
{//初始化链栈 
    *S = (LinkStack)malloc(sizeof(LinkStackNode));
    (*S)->next = NULL;
}
int Push(LinkStack top, int x)
{// 进栈操作 
    LinkStackNode *temp;
    temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
    if(temp == NULL) return 0;
    temp->data = x;
    temp->next = top->next;
    top->next = temp;
    return 1;
}
int Pop(LinkStack top, int *x)
{//出栈操作 
    LinkStackNode *temp;
    temp = top->next;
    if(temp == NULL) return 0;
    *x = temp->data;
    top->next = temp->next;
    free(temp);
    return 1;
}
int GetNum(char ch)
{//返回字符对应的数字 
    return ch - '0';
}
bool IsEmpty(LinkStack top)
{//栈为空返回假 
    if(top->next == NULL) return false;
    return true;
}
int GetTop(LinkStack top)
{//返回栈顶元素 
    if(top->next == NULL) return 1;
    return top->next->data;
}
char Compare(char ch1, char ch2)
{//实现运算符优先级比较 
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
{//计算 a op b 的值 
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
{//实现 
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
		{//如果数字不是一位数字，便把字符转化为数字
            num = num * 10 + GetNum(ch);
            ch = getchar();
        }
        if(num != 0)
		{//如果num不为0便进OVS栈 
            Push(ovs, num);
            num = 0;//把num置零 
        }
        else{
            switch(Compare(ch, (char)GetTop(optr)))
			{//对运算符优先级进行比较，实现对应三种关系的操作 
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
    t = GetTop(ovs);//取栈顶元素，返回值 
    return t; 
}
int main()
{
    int ans = ExpEvaluation();
    printf("%d\n", ans);
    return 0;
}