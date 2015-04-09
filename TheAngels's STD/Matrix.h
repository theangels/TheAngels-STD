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
			for (int j = 0; j <l; j++)
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
		{
			for (int j = 0; j < l; j++)
			{
				tab[i][j] = other.tab[i][j];
			}
		}
		return *this;
	}
	Matrix &operator * (const Matrix &other) const
	{
		return (Matrix)*this *= other;
	}
	Matrix operator + (const Matrix &other) const
	{
		return (Matrix)*this += other;
	}
	Matrix operator - (const Matrix &other) const
	{
		return (Matrix)*this -= other;
	}
private:
	int tab[MAX_Mat][MAX_Mat];
	int h, l;
};
/*
void Matrix_Fast_Pow(Matrix base,int num, Matrix &input, Matrix &tmp)
{
	for (int i = 0; i < base.h; i++)
		for (int j = 0; j < base.l; j++)
			input.tab[i][j] = (i == j);
	while (num)
	{
		if (num & 1)
		{
			Matrix_Mult(input, base, tmp);
			Matrix_Give(input, tmp);
		}
		Matrix_Mult(base, base, tmp);
		Matrix_Give(base, tmp);
		num >>= 1;
	}
	return;
}
*/