struct LinkNode
{
	ElemType val;
	LinkNode *pre, *next;
	LinkNode() :val(), pre(), next(){}
	LinkNode(ElemType __val, LinkNode *__pre = NULL, LinkNode *__next = NULL)
		:val(__val), pre(__pre), next(__next){}
};
struct Link
{
	LinkNode *head;
	LinkNode *tail;
	int len;	
};
void Link_Ini(Link &p)
{
	LinkNode *start = new LinkNode();
	p.head = p.tail = start;
	p.len = 0;
	return;
}
void Link_Add(Link &p, const ElemType &add)
{
	LinkNode *tmp = new LinkNode(add);
	tmp->next = NULL;
	tmp->pre = p.tail;
	p.tail->next = tmp;
	p.tail = tmp;
	p.len++;
	return;
}
void Link_Insert(Link &p, const ElemType &insert, const int ind)
{
	LinkNode *now = p.head;
	for (int i = 0; i < ind; i++)
		now = now->next;
	LinkNode *tmp = new LinkNode(insert);
	tmp->next = now->next;
	now->next->pre = tmp;
	now->next = tmp;
	tmp->pre = now;
	p.len++;
	return;
}
void Link_Delete(Link &p, const int ind)
{
	LinkNode *now = p.head;
	for (int i = 0; i < ind; i++)
		now = now->next;
	LinkNode *del = now;
	del->pre->next = now->next;
	del->next->pre = del->pre;
	delete(del);
	p.len--;
	return;
}
void Link_Traverse(const Link &p)
{
	LinkNode *now = p.head;
	for (int i = 0; i < p.len; i++)
	{
		now = now->next;
		cout << now->val;
		if (i == p.len - 1)
			cout << endl;
		else
			cout << " ";
	}
	return;
}
void Link_Destory(Link &p)
{
	LinkNode *now = p.head;
	LinkNode *des;
	for (int i = 0; i < p.len; i++)
	{
		des = now;
		now = now->next;
		delete(des);
	}
	p.head = NULL;
	p.tail = NULL;
	p.len = 0;
	return;
}
void Link_GetElem(const Link &p, int ind, ElemType &e)
{
	LinkNode *now = p.head;
	for (int i = 0; i < ind; i++)
		now = now->next;
	e = now->val;
}
void Link_PriorElem(const Link &p, const ElemType &cur_e, ElemType &pre_e)
{
	LinkNode *now = p.head;
	while (now->val!=cur_e)
		now = now->next;
	pre_e = now->pre->val;
	return;
}
void Link_NextElem(const Link &p, const ElemType &cur_e, ElemType &next_e)
{
	LinkNode *now = p.head;
	while (now->val != cur_e)
		now = now->next;
	next_e = now->next->val;
	return;
}
void Link_DeleteElem(Link &p, const ElemType &Min, const ElemType &Max)
{
	LinkNode *now = p.head;
	int ind;
	for (now = p.head->next,ind=1; now != NULL; now,ind)
	{
		if (now->val >= Min&&now->val <= Max)
		{
			now = now->pre;
			Link_Delete(p, ind);
			ind--;
		}
		else
		{
			ind++;
			now = now->next;
		}
	}
	return;
}