struct ElemType {
	ElemType() {
		count = 1;
	}
	InfoType count;
	KeyType key;
};
typedef struct BSTNode{
	BSTNode() {
		lchild = rchild = NULL;
	}
	ElemType data;
	BSTNode *lchild, *rchild;
}*BSTree, BSTNode;

class bstree {

public:
	bstree() {
		ElemType e;
		root = NULL;
		cin >> e.key;
		while (e.key != -1) {
			InsertBST(e);
			cin >> e.key;
		}
	}

public :
	void PrintBST() {
		PrintBST_Inner(root);
		cout << endl;
	}

private:
	void PrintBST_Inner(BSTree T) {
		if (T) {
			cout << T->data.key << "-" << T->data.count;
			if (T->lchild || T->rchild) {
				cout << "(";
				PrintBST_Inner(T->lchild);
				if (T->rchild) {
					cout << ",";
					PrintBST_Inner(T->rchild);
				}
				cout << ")";
			}
		}
	}

public:
	void InsertBST(ElemType  e){
		//在指针T所指的二叉排序树中插入关键字为e的元素
		BSTree bt, parent, p;
		bt = root;
		parent = NULL;
		while (bt != NULL) {
			parent = bt;
			if (e.key < bt->data.key) {
				bt = bt->lchild;
			}
			else if (e.key > bt->data.key) {
				bt = bt->rchild;
			}
			else {
				bt->data.count++;
				return;
			}
		}
		p = new BSTNode;
		p->data = e;
		if (parent == NULL) {
			root = p;
		}
		else if (e.key < parent->data.key) {
			parent->lchild = p;
		}
		else {
			parent->rchild = p;
		}
	}

public:
	void DeleteBST(KeyType key) {
		BSTree bt, parent, p;
		bt = root;
		parent = NULL;
		bool isFind = false;
		while (bt != NULL) {
			parent = bt;
			if (key < bt->data.key) {
				bt = bt->lchild;
			}
			else if (key > bt->data.key) {
				bt = bt->rchild;
			}
			else {
				if (bt->data.count != 1) {
					bt->data.count--;
					return;
				}
				isFind = true;
				break;
			}
		}
		if (isFind) {
			if (bt->rchild == NULL) {//左单
				if (parent->lchild == bt) {
					parent->lchild = bt->lchild;
				}
				else {
					parent->rchild = bt->lchild;
				}
			}
			else if (bt->lchild == NULL) {//右单
				if (parent->lchild == bt) {
					parent->lchild = bt->rchild;
				}
				else {
					parent->rchild = bt->rchild;
				}
			}
			else {//双分支

			}
		}	
	}

public:
	BSTree SearchBST(KeyType key) {
		BSTree bt, parent;
		bt = root;
		parent = NULL;
		while (bt != NULL) {
			parent = bt;
			if (key < bt->data.key)
				bt = bt->lchild;
			else if (key > bt->data.key)
				bt = bt->rchild;
			else {
				return bt;
			}
		}
		return NULL;
	}

public:
	ElemType MaxBST() {
		BSTree bt, parent;
		bt = root;
		parent = NULL;
		while (bt != NULL) {
			parent = bt;
			bt = bt->rchild;
		}
		return parent->data;
	}

private:
	BSTree root;
};