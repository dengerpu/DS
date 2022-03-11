int like(BiTree t1,BiTree t2)
{
	int like1,like2;
	if(t1==NULL && t2==NULL)
		return 1;
	else if(t1==NULL || t2==NULL)
		return 0;
	else
	{
		like1=like(t1->LChild);
		like2=like(t2->RChild);
		return (like1 && like2);
	}
}
void path(BiTree root,BiTree r)
{
	BiTree p,q;
	int i,top=0;
	BiTree s[Stack_Size];	
	p=root;
	q=NULL;
	while(p!=NULL || top!=0)
	{
		while(p!=NULL)
		{
			top++;
			if(top>Stack_Size)
				OverFlow();	//ջ�������
			s[top]=p;
			p=p->LChild;
		}
		if(top>0)
		{
			p=s[top];
			if(p->RChild==NULL || p->RChild==q)
			{
				if(p==r)
				{
					for(i=1;i<=top;i++)
						printf("%d",s[top]->data);
					return ;
				}
				else
				{
					q=p;
					top--;
					p=NULL;
				}
			}
			else
				p=p->RChild;
		}
	}
}
int LayerOrder(BiTree bt)
{
	SeqQueue Q;
	BiTree p;
	InitQueue(&Q);
	if(bt==NULL)
		return ERROR;
	EnterQueue(&Q,bt);
	while(!IsEmpty(Q))	//�����зǿգ������δ��������������
	{
		DeleteQueue(&Q,&p);	//��ͷԪ�س���
		printf("%d",p->data);
		if(p->LChild) EnterQueue(&Q,p->LChild);
		if(p->RChild) EnterQueue(&Q,p->RChild);
	}
	return OK;
}
int LayerOrder(BiTree bt)
{
	SeqQueue Q;
	BiTree p;
	InitQueue(&Q);
	if(bt==NULL)
		return ERROR;
	EnterQueue(&Q,bt);
	while(!IsEmpty(Q))	//�����зǿգ������δ��������������
	{
		DeleteQueue(&Q,&p);
		printf("%d",p->data);
		if(p->LChild) EnterQueue(&Q,p->LChild);
		if(p->RChild) EnterQueue(&Q,p->RChild);
	}
}