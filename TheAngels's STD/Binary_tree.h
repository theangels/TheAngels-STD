template <typename ElemType>
struct TreeNode
{
	ElemType data;
	TreeNode *lc, *rc;
	TreeNode() : data(), lc(), rc(){}
};
template <typename ElemType>
class Binary_tree
{
public:
	Binary_tree(ElemType *add)
	{
		strcpy(arr, add);
		root = new TreeNode<ElemType>;
		root->data = arr[0];
		id = 1;
		build(root);
	}
	Binary_tree()
	{
		root = new TreeNode<ElemType>;
	}
public:
	void PreOrderTraverse2()
	{
		stack<TreeNode<ElemType>*> tst;
		TreeNode<ElemType>* now;
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
	void ChangeBiTree()
	{	
		ch(root);
	}
public:
	int CountLeafBiTree()
	{
		return count(root);
	}
public:
	void CopyBiTree(Binary_tree<ElemType> &T)
	{
		cp(root, T.getroot());
	}
public:
	bool SimilarBiTrees(Binary_tree<ElemType> &T)
	{
		if (check(root, T.getroot()) == 0)
			return true;
		return false;
	}
public:
	void RemoveLeaves()
	{
		rl(root);
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
		LinkQueue<TreeNode<ElemType> *> que;
		que.push(root);
		while (!que.empty())
		{
			TreeNode<ElemType> *now = que.top();
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
	TreeNode<ElemType> *Parent(ElemType x)
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
	void rl(TreeNode<ElemType> *now)
	{
		if (now)
		{
			if (now->lc && !(now->lc->lc) && !(now->lc->rc))
			{
				TreeNode<ElemType> *del = now->lc;
				now->lc = NULL;
				delete del;
			}
			else
				rl(now->lc);
			if (now->rc && !(now->rc->lc) && !(now->rc->rc))
			{
				TreeNode<ElemType> *del = now->rc;
				now->rc = NULL;
				delete del;
			}
			else
				rl(now->rc);
		}
	}
private:
	int check(TreeNode<ElemType> *a, TreeNode<ElemType> *b)
	{
		if (!a&&!b)
			return 0;
		if (!a || !b)
			return 1;
		return check(a->lc, b->lc)+check(a->rc, b->rc);
	}
private:
	void cp(TreeNode<ElemType> *pre, TreeNode<ElemType> *cpy)
	{
		cpy->data = pre->data;
		if (pre->lc)
		{
			TreeNode<ElemType> *add = new TreeNode < ElemType >;
			cpy->lc = add;
			cp(pre->lc, cpy->lc);
		}
		if (pre->rc)
		{
			TreeNode<ElemType> *add = new TreeNode < ElemType >;
			cpy->rc = add;
			cp(pre->rc, cpy->rc);
		}
	}
private:
	TreeNode<ElemType> *&getroot()
	{
		return root;
	}
private:
	int count(TreeNode<ElemType> *now)
	{
		if (!now)
			return 0;
		if (now->lc == NULL&&now->rc == NULL)
			return 1;
		return count(now->lc) + count(now->rc);
	}
private:
	void ch(TreeNode<ElemType> *now)
	{
		if (now)
		{
			TreeNode<ElemType> *tmp = now->lc;
			now->lc = now->rc;
			now->rc = tmp;
			ch(now->lc);
			ch(now->rc);
		}
	}
private:
	void find(TreeNode<ElemType> *now, ElemType x)
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
	void prt(TreeNode<ElemType> *now)
	{
		if (!now) return;
		cout << now->data;
		prt(now->lc);
		prt(now->rc);
	}
private:
	void it(TreeNode<ElemType> *now)
	{
		if (!now) return;
		it(now->lc);
		cout << now->data;
		it(now->rc);
	}
private:
	void pot(TreeNode<ElemType> *now)
	{
		if (!now) return;
		pot(now->lc);
		pot(now->rc);
		cout << now->data;
	}
private:
	void Del(TreeNode<ElemType> *now)
	{
		if (!now) return;
		Del(now->lc);
		Del(now->rc);
		delete(now);
	}
private:
	void finddeep(TreeNode<ElemType> *now, int num)
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
	void build(TreeNode<ElemType> *now)
	{
		if (arr[id] == '\0') return;
		if (arr[id] != '#')
		{
			TreeNode<ElemType> *lson = new TreeNode < ElemType >;
			lson->data = arr[id];
			now->lc = lson;
			id++;
			build(now->lc);
		}
		else
			id++;
		if (arr[id] != '#')
		{
			TreeNode<ElemType>* rson = new TreeNode < ElemType >;
			rson->data = arr[id];
			now->rc = rson;
			id++;
			build(now->rc);
		}
		else
			id++;
	}
private:
	TreeNode<ElemType>* root;
	TreeNode<ElemType> *ret;
	ElemType arr[MAX_SIZE];
	int id;
	int deep;
};