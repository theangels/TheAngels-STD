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
	Binary_tree(ElemType *add)
	{
		strcpy(arr, add);
		root = new Node<ElemType>;
		root->data = arr[0];
		id = 1;
		build(root);
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
	int id;
	int deep;
};