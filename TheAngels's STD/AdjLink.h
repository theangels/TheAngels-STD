template <typename	VerTexType>
class AdjLink
{
public:
	AdjLink(int _size = 0) :size(_size){}
public:
	~AdjLink()
	{

	}
public:
	void InsertArc(VerTexType x, VerTexType y)
	{
		int ax = find(x);
		int ay = find(y);
		if (ax == -1 || ay == -1) return;

	}
private:
	void insert()
	{

	}
private:
	int find(VerTexType x)
	{
		for (int i = 0; i < size; i++)
			if (x == tab[i]) return i;
		return -1;
	}
private:
	struct Node
	{
		int num;
		Node *next;
		Node() :num(), next(){}
	};
	VerTexType tab[MAX_SIZE];
	int size;
};