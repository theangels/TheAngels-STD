template<typename VerTexType>
class AdjMatrix
{
public:
	AdjMatrix(int num = 0) :MAX_POINT(num)
	{
		len = 0;
		memset(point, 0, sizeof(point));
		memset(matrix, 0, sizeof(matrix));
	}
public:
	void InsertVex(VerTexType add)
	{
		if (len == MAX_POINT) return;
		point[len] = add;
		len++;
	}
public:
	void DeleteVex(VerTexType del)
	{
		int remove = find(del);
		if (remove == -1) return;
		for (int i = 0; i < MAX_POINT; i++)
			matrix[remove][i] = matrix[i][remove] = 0;
	}
public:
	void InsertArc(VerTexType a, VerTexType b)
	{
		int adda = find(a);
		int addb = find(b);
		if (adda == -1 || addb == -1) return;
		matrix[adda][addb] = 1;
	}
public:
	void DeleteArc(VerTexType a, VerTexType b)
	{
		int dela = find(a);
		int delb = find(b);
		if (dela == -1 || delb == -1) return;
		matrix[dela][delb] = 0;
	}
public:
	void PrintGraph()
	{
		for (int i = 0; i < MAX_POINT; i++)
			for (int j = 0; j < MAX_POINT; j++)
			{
				cout << matrix[i][j];
				if (j == MAX_POINT - 1)
					cout << endl;
				else
					cout << " ";
			}
	}
private:
	int find(VerTexType f)
	{
		for (int i = 0; i < MAX_POINT; i++)
			if (point[i] == f) return i;
		return -1;
	}
private:
	int MAX_POINT;
	int matrix[MAX_SIZE][MAX_SIZE];
	VerTexType point[MAX_SIZE];
	int len;
};