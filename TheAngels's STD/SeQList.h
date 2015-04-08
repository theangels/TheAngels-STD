#define MAX_SQ 50
typedef struct
{
	ElemType * Elem;
	int length;
	int MaxSize;	
}SqList;
int SeQ_Time=2;
void InitList(SqList &L)
{
	L.MaxSize = MAX_SQ;
	L.Elem=(ElemType *)malloc(L.MaxSize*sizeof(ElemType));
	L.length=0;
	return;
}
void DestoryList(SqList &L)
{
	free(L.Elem);
	return;
}
int ListLength(SqList L)
{
	return L.length;
}
void TraverselList(SqList L)
{
	for(int i = 0; i < L.length; i++)
	{
		cout << L.Elem[i];
		if(i==L.length-1)
			cout << endl;
		else
			cout << " ";
	}
	return;
}
void ListInsert(SqList &L, int ind, ElemType e)
{
	if(L.length==L.MaxSize)
	{
		L.Elem = (ElemType *)realloc(L.Elem, SeQ_Time*L.MaxSize*sizeof(ElemType));
		SeQ_Time++;
	}
	for(int i = L.length-1; i >= ind-1; i--)
		L.Elem[i+1]=L.Elem[i];
	L.Elem[ind-1]=e;
	L.length++;
	return;
}
void ListDelete(SqList &L, int ind)
{
	for(int i = ind-1; i < L.length-1; i++)
		L.Elem[i]=L.Elem[i+1];
	L.length--;
	
}
void GetElem(SqList L, int i , ElemType &e)
{
	e=L.Elem[i-1];
	return;
}
void DeleteElem(SqList &L, ElemType SQMin, ElemType SQMax)
{
	for(int i = 0; i < L.length; i)
	{
		if(L.Elem[i]>=SQMin&&L.Elem[i]<=SQMax)
		{
			ListDelete(L,i+1);
		}
		else
			i++;
	}
	return;
}
