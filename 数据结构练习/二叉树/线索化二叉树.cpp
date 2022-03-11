void inthread(bitree root)
{
	if(root!=NULL)
	{
		inthread(root->lchild);
		if(root->lchild==NULL)
		{root->ltag=1;root->lchild=pre;}
		if(pre!=NULL&&pre->rchild==NULL)
		{pre->rchild=root;pre->rtag=1;}
		pre=root;
		inthread(root->rchild);
	}
}
bitnode *inpre(bitnode *p)
{
	if(p->ltag==1)pre=p->lchild;
	else
	{
		for(q=p->lchild;q->rtag==0;q=q->rchild)
			pre=q;
	}
	return (pre);
}
bitnode *innext(bitnode *p)
{
	if(p->rtag==1)next=p->rchild;
	else
	{
		for(q=p->rchild;q->ltag==0;q=q->lchild)
			next=q;
	}
	return (next)
}