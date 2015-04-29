struct LinkNode
{
	ElemType val;
	LinkNode *next;
	LinkNode() :val(), next(){}
	LinkNode(ElemType __val, LinkNode* __next = NULL)
		:val(__val),  next(__next){}
};
class LinkList
{
public:
	LinkList() : head(), tail(), len()
	{
		LinkNode *tmp = new LinkNode;
		len = 0;
		tmp->val = -1;
		head = tail = tmp;
		tmp->next = NULL;
	}
public:
	void push_back(ElemType add)
	{
		LinkNode *tmp = new LinkNode(add);
		tail->next = tmp;
		tail = tmp;
		len++;
		return;
	}
public:
	void travel()
	{
		for (LinkNode *p = head->next; p; p = p->next)
		{
			cout << p->val;
			if (p->next)
				cout << " ";
			else
				cout << endl;
		}
		return;
	}
public:
	void erase(int ind)
	{
		LinkNode *p = head;
		int i=1;
		while (p&&i < ind)
		{
			p = p->next;
			i++;
		}
		LinkNode *del;
		del = p->next;
		p->next = del->next;
		delete(del);
		len--;
		return;
	}
public:
	ElemType at(int ind)
	{
		LinkNode *p = head->next;
		int i = 1;
		while (p&&i < ind)
		{
			p = p->next;
			i++;
		}
		return p->val;
	}
public:
	int size()
	{
		return len;
	}
public:
	~LinkList()
	{
		LinkNode *p;
		LinkNode *del;
		del = head;
		p = head->next;
		while (p)
		{
			delete(del);
			del = p;
			p = p->next;
		}
		delete(p);
	}
private:
	LinkNode *head;
	LinkNode *tail;
	int len;
};
