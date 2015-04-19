struct Node
{
	ElemType val;
	Node *next;
	Node() :val(), next(){}
	Node(ElemType __val,Node* __next = NULL)
		:val(__val),  next(__next){}
};
class LinkList
{
public:
	LinkList() : head(), tail(), len()
	{
		Node *tmp = new Node;
		len = 0;
		tmp->val = -1;
		head = tail = tmp;
		tmp->next = NULL;
	}
public:
	void push_back(ElemType add)
	{
		Node *tmp = new Node(add);
		tail->next = tmp;
		tail = tmp;
		len++;
		return;
	}
public:
	void travel()
	{
		for (Node *p = head->next; p; p = p->next)
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
		Node *p=head;
		int i=1;
		while (p&&i < ind)
		{
			p = p->next;
			i++;
		}
		Node *del;
		del = p->next;
		p->next = del->next;
		delete(del);
		len--;
		return;
	}
public:
	ElemType at(int ind)
	{
		Node *p = head->next;
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
		Node *p;
		Node *del;
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
	Node *head;
	Node *tail;
	int len;
};
