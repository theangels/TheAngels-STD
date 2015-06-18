template <typename	VerTexType>
class AdjLink
{
public:
	AdjLink(int _size = 0) :size(_size)
	{
		point = 0;
		for (int i = 0; i < size; i++)
		{
			link[i] = new Node;
			link[i]->id = i;
			tail[i] = link[i];
		}
	}
public:
	~AdjLink()
	{
		for (int i = 0; i < size; i++)
		{
			Node *p = link[i];
			while(p)
			{
				Node *tmp = p->next;
				delete(p);
				p = tmp;
			}
		}
	}
public:
	void Addpoint(VerTexType x)
	{
		if (point >= size)return;
		tab[point] = x;
		point++;
	}
public:
	void InsertArc(VerTexType x, VerTexType y, int val)
	{
		int ax = find(x);
		int ay = find(y);
		if (ax == -1 || ay == -1 || ax >= size || ay >= size) return;
		insert(ax, ay, val);
		insert(ay, ax, val);
	}
public:
	void DeleteArc(VerTexType x, VerTexType y)
	{
		int ax = find(x);
		int ay = find(y);
		if (ax == -1 || ay == -1 || ax >= size || ay >= size) return;
		remove(ax, ay);
		remove(ay, ax);
	}
public:
	int VexDegree(VerTexType x)
	{
		int ax = find(x);
		if (ax == -1) return 0;
		int time = 0;
		for (Node *p = link[ax]->next; p; p = p->next)
			time++;
		return time;
	}
public:
	void PrintGraph()
	{
		for (int i = 0; i < size; i++)
			for (Node *p = link[i]; p; p = p->next)
			{
				cout << tab[p->id] << " " << p->val;
				if (p->next)
					cout << " -> ";
				else
					cout << endl;
			}
	}
private:
	void insert(int la, int lb, int val)
	{
		Node *add = new Node;
		add->next = tail[la]->next;
		add->id = lb;
		add->val = val;
		tail[la]->next = add;
		tail[la] = add;
	}
private:
	void remove(int la, int lb)
	{
		for (Node *p = link[la]; p->next; p=p->next)
		{
			if (p->next->id == lb)
			{
				Node *del = p->next;
				p->next = del->next;
				delete(del);
				break;
			}
		}
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
		int id;
		int val;
		Node *next;
		Node() :id(),val(), next(){}
	};
	VerTexType tab[MAX_SIZE];
	Node *link[MAX_SIZE];
	Node *tail[MAX_SIZE];
	int point;
	int size;
};