class SeqQueue
{
public:
	SeqQueue(int __len) :len(__len)
	{
		que = new ElemType[len];
		top = 0;
		tail = 0;
	}
public:
	void push(ElemType add)
	{
		if ((tail + 1) % len == top) return;
		que[tail] = add;
		tail = (tail + 1) % len;
		return;
	}
public:
	void pop()
	{
		if (top==tail) return;
		top = (top + 1) % len;
	}
public:
	void travel()
	{
		int p = top;
		while (p != tail)
		{
			cout << que[p];
			if ((p + 1) % len == tail)
				cout << endl;
			else
				cout << " ";
			p = (p + 1) % len;
		}
	}
public:
	ElemType front()
	{
		return que[top];
	}
public:
	~SeqQueue()
	{
		delete[]que;
	}
private:
	int len;
	ElemType *que;
	int top;
	int tail;
};