class LinkQueue
{
public:
	LinkQueue() :_head(), _tail()
	{
		_head = new ElemType;
		_tail=_head;
	}
public:
	void push(int _num, int _time)
	{
		ElemType* tmp = new ElemType(_num, _time);
		_tail->next = tmp;
		_tail = tmp;
	}
public:
	void pop()
	{
		_head = _head->next;
	}
public:
	bool empty()
	{
		return _head == _tail;
	}
public:
	ElemType& top()
	{
		return *(_head->next);
	}
public:
	/**/
	~LinkQueue()
	{
		ElemType *p;
		p = _head;
		while (p)
		{
			ElemType *del;
			del = p;
			p = p->next;
			delete del;
		}
	}
private:
	ElemType* _head;
	ElemType* _tail;
};