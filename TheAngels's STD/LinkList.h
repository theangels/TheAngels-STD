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
void Link_Traver(const Link &p)
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
	return;
}