#include "TheAngels's STD.h"
#include "SeQList.h"
#include "Matrix.h"
#include "LinkList.h"
int main(void)
{
	Matrix test(2,2);
	test.at(0, 0) = 1;
	test.at(0, 1) = 2;
	test.at(1, 0) = 3;
	test.at(1, 1) = 4;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << test.at(i,j);
			if (j == 1)
				cout << endl;
			else
				cout << " ";
		}
	Matrix tes(2, 2);
	tes.at(0, 0) = 5;
	tes.at(0, 1) = 6;
	tes.at(1, 0) = 7;
	tes.at(1, 1) = 8;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << tes.at(i,j);
			if (j == 1)
				cout << endl;
			else
				cout << " ";
		}
	test *= tes;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << test.at(i, j);
			if (j == 1)
				cout << endl;
			else
				cout << " ";
		}
	return 0;
}