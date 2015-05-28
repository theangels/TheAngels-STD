template <typename ElemType>
struct Node
{
	ElemType data;
	Node *lc, *rc;
	Node() : data(), lc(), rc(){}
};
template <typename ElemType>
class Binary_tree
{
public:
	void PreOrderTraverseUn()
	{
		stack<Node<ElemType>*> tst;
		Node<ElemType>* now;
		now = root;
		while (now||!tst.empty())
		{
			while (now)
			{
				tst.push(now);
				cout << now->data;
				now = now->lc;
			}
			now = tst.top();
			tst.pop();
			now = now->rc;
		}
		cout << endl;
	}
public:
	Binary_tree(ElemType *add)
	{
		strcpy(arr, add);
		root = new Node<ElemType>;
		root->data = arr[0];
		id = 1;
		build(root);
	}
public:
	void PreOrderTraverse()
	{
		prt(root);
		cout << endl;
	}
public:
	void InOrderTraverse()
	{
		it(root);
		cout << endl;
	}
public:
	void PostOrderTraverse()
	{
		pot(root);
		cout << endl;
	}
public:
	void LevelOrderTraverse()
	{
		LinkQueue<Node<ElemType> *> que;
		que.push(root);
		while (!que.empty())
		{
			Node<ElemType> *now = que.top();
			que.pop();
			cout << now->data;
			if (now->lc)
				que.push(now->lc);
			if (now->rc)
				que.push(now->rc);
		}
		cout << endl;
	}
public:
	Node<ElemType> *Parent(ElemType x)
	{
		ret = NULL;
		find(root, x);
		return ret;
	}
public:
	bool BiTreeEmpty()
	{
		if (root)
			return true;
		return false;
	}
public:
	int BiTreeDepth()
	{
		deep = 0;
		finddeep(root, 1);
		return deep;
	}
public:
	~Binary_tree()
	{
		Del(root);
		root = NULL;
	}
private:
	void find(Node<ElemType> *now,ElemType x)
	{
		if (!now) return;
		if (now->lc && now->lc->data == x || now->rc && now->rc->data == x)
		{
			ret = now;
			return;
		}
		find(now->lc,x);
		find(now->rc,x);
	}
private:
	void prt(Node<ElemType> *now)
	{
		if (!now) return;
		cout << now->data;
		prt(now->lc);
		prt(now->rc);
	}
private:
	void it(Node<ElemType> *now)
	{
		if (!now) return;
		it(now->lc);
		cout << now->data;
		it(now->rc);
	}
private:
	void pot(Node<ElemType> *now)
	{
		if (!now) return;
		pot(now->lc);
		pot(now->rc);
		cout << now->data;
	}
private:
	void Del(Node<ElemType> *now)
	{
		if (!now) return;
		Del(now->lc);
		Del(now->rc);
		delete(now);
	}
private:
	void finddeep(Node<ElemType> *now,int num)
	{
		if (!now)
		{
			deep = max(deep, num-1);
			return;
		}
		finddeep(now->lc, num + 1);
		finddeep(now->rc, num + 1);
	}
private:
	void build(Node<ElemType> *now)
	{
		if (arr[id] == '\0') return;
		if (arr[id] != '#')
		{
			Node<ElemType> *lson = new Node < ElemType > ;
			lson->data = arr[id];
			now->lc = lson;
			id++;
			build(now->lc);
		}
		else
			id++;
		if (arr[id] != '#')
		{
			Node<ElemType>* rson = new Node < ElemType > ;
			rson->data = arr[id];
			now->rc = rson;
			id++;
			build(now->rc);
		}
		else
			id++;
	}
private:
	Node<ElemType>* root;
	ElemType arr[MAX_SIZE];
	Node<ElemType> *ret;
	int id;
	int deep;
};