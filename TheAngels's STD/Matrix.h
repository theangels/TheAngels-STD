#define MAX_Mat 100
class Matrix
{
public:
	Matrix() :h(), l(){}
	Matrix(int __h, int __l)
		:h(__h), l(__l){}
public:
	int &at(int x, int y)
	{
		return tab[x][y];
	}
public:
	Matrix &operator += (const Matrix &other)
	{
		for (int i = 0; i < h; i++)
			for (int j = 0; j < l; j++)
				tab[i][j] += other.tab[i][j];
		return *this;
	}
	Matrix &operator -= (const Matrix &other)
	{
		for (int i = 0; i < h; i++)
			for (int j = 0; j < l; j++)
				tab[i][j] -= other.tab[i][j];
		return *this;
	}
	Matrix &operator *= (const Matrix &other)
	{
		Matrix input;
		input.h = h;
		input.l = other.l;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < other.l; j++)
			{
				int save = 0;
				for (int k = 0; k < l; k++)
					save += (tab[i][k] * other.tab[k][j]);
				input.tab[i][j] = save;
			}
		*this = input;
		return *this;
	}
	Matrix &operator = (const Matrix &other)
	{
		h = other.h;
		l = other.l;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < l; j++)
				tab[i][j] = other.tab[i][j];
		return *this;
	}
	Matrix &operator ^= (int num)
	{
		Matrix input(h,h);
		Matrix base = *this;
		for (int i = 0; i < h; i++)
			input.tab[i][i] = 1;
		while (num)
		{
			if (num & 1)
			{
				input *= base;
			}
			base *= base;
			num >>= 1;
		}
		*this = input;
		return *this;
	}
	Matrix operator * (const Matrix &other) const
	{
		return Matrix(*this) *= other;
	}
	Matrix operator + (const Matrix &other) const
	{
		return Matrix(*this) += other;
	}
	Matrix operator - (const Matrix &other) const
	{
		return Matrix(*this) -= other;
	}
	Matrix operator ^ (int num) const
	{
		return Matrix(*this) ^= num;
	}
private:
	int tab[MAX_Mat][MAX_Mat];
	int h, l;
};
