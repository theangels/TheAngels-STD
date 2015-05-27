template <typename ElemType>
class Binary_tree
{
private:
	struct BiTNode
	{
		ElemType data;
		BiTNode *lc, *rc;
	};
	BiTNode* p;
	ElemType arr[MAX_SIZE];
};