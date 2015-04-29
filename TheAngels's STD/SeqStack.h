#define MAX_Sta 100000
class SeqStack
{
public:
	SeqStack() :__st()
	{
		__st = new ElemType[MAX_Sta];
		__top = __st;
	}
public:
	~SeqStack()
	{
		delete []__st;
		__st = NULL;
		__top = NULL;
	}
public:
	bool empty()
	{
		if (__top == __st)
			return true;
		return false;
	}
public:
	int length()
	{
		return __top - __st;
	}
public:
	void push(ElemType in)
	{
		*__top = in;
		__top++;
		return;
	}
public:
	void pop()
	{
		__top--;
		return;
	}
public:
	ElemType top()
	{
		return *(__top - 1);
	}
private:
	ElemType *__st;
	ElemType *__top;
};
