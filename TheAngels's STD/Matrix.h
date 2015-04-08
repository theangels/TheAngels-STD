#define MAX_Mat 100
struct Matrix
{
	int tab[MAX_Mat][MAX_Mat];
	int h, l;
	Matrix() :h(), l(){}
	Matrix(int __h, int __l)
		:h(__h), l(__l){}
};
void Matrix_Add(Matrix &add, const Matrix &other)
{
	for (int i = 0; i < add.h; i++)
		for (int j = 0; j < add.l; j++)
			add.tab[i][j] += other.tab[i][j];
	return;
}
void Matrix_Mius(Matrix &mius, const Matrix &other)
{
	for (int i = 0; i < mius.h; i++)
		for (int j = 0; j < mius.l; j++)
			mius.tab[i][j] -= other.tab[i][j];
	return;
}
void Matrix_Mult(const Matrix &left, const Matrix &right, Matrix &input)
{
	for (int i = 0; i < left.h; i++)
		for (int j = 0; j < right.l; j++)
		{
			int save = 0;
			for (int k = 0; k < left.l; k++)
				save += (left.tab[i][k] * right.tab[k][j]);
			input.tab[i][j] = save;
		}
	return;
}
void Matrix_Give(Matrix &input, const Matrix &other)
{
	input.h = other.h;
	input.l = other.l;
	for (int i = 0; i < other.h; i++)
		for (int j = 0; j < other.l; j++)
			input.tab[i][j] = other.tab[i][j];
	return;
}
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