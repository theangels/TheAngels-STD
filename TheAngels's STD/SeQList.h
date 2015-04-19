class SeqList
{
public:
	SeqList(ElemType* __Elem, int __MaxSize, int __len = 0, int __time = 1) : Elem(__Elem), MaxSize(__MaxSize), len(__len), time(__time)
	{
		Elem = (ElemType*)malloc(sizeof(ElemType)*time);
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
		for (int i = len - 1; i >= ind - 1; i--)
			Elem[i + 1] = Elem[i];
		Elem[ind - 1] = e;
		len++;
		return;
	}
public:
	void erase(int ind)
	{
		for (int i = ind - 1; i < len - 1; i++)
			Elem[i] = Elem[i + 1];
		len--;
		return;
	}
public:
	ElemType at(int ind)
	{
		return Elem[ind - 1];
	}
public:
	~SeqList()
	{
		free(Elem);
	}
private:
	ElemType *Elem;
	int len;
	int MaxSize;
	int time;
};
