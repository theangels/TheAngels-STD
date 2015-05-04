class SeqList
{
public:
	SeqList(int __MaxSize = 1) :MaxSize(__MaxSize)
	{
		time = 1;
		len = 0;
		Elem = (ElemType*)malloc(sizeof(ElemType)*time*MaxSize);
	}
public:
	int length()
	{
		return len;
	}
public:
	void travel()
	{
		for (int i = 0; i < len; i++)
		{
			cout << Elem[i];
			if (i == len - 1)
				cout << endl;
			else
				cout << " ";
		}
		return;
	}
public:
	void insert(ElemType e, int ind)
	{
		if (len == MaxSize*time)
		{
			Elem = (ElemType*)realloc(Elem, time*MaxSize*sizeof(ElemType));
			time++;
		}
		for (int i = len - 1; i >= ind; i--)
			Elem[i + 1] = Elem[i];
		Elem[ind] = e;
		len++;
		return;
	}
public:
	void erase(int ind)
	{
		for (int i = ind; i < len - 1; i++)
			Elem[i] = Elem[i + 1];
		len--;
		return;
	}
public:
	ElemType at(int ind)
	{
		return Elem[ind];
	}
public:
	~SeqList()
	{
		free(Elem);
		len = 0;
		time = 1;
		MaxSize = 1;
	}
private:
	ElemType *Elem;
	int len;
	int MaxSize;
	int time;
};