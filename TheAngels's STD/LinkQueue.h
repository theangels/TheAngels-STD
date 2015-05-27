template <typename ElemType>
class LinkQueue
{
public:
	LinkQueue() :_head(), _tail()
	{
		_head = new Node;
		_tail=_head;
	}
public:
	void push(ElemType &add)
	{
		Node* tmp = new Node(add);
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
		return (_head->next)->data;
	}
public:
	~LinkQueue()
	{
		Node *p;
		p = _head;
		while (p)
		{
			Node *del;
			del = p;
			p = p->next;
			delete del;
		}
	}
private:
	struct Node
	{
		ElemType data;
		Node *next;
		Node() :data(), next(){}
		Node(ElemType __data, Node *__next = NULL) :data(__data), next(__next){}
	};
	Node* _head;
	Node* _tail;
};