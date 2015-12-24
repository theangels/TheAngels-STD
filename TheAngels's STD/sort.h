#include<stdio.h>
#include<iostream>
using namespace std;

struct ScoreNode {
	char name[50];
	int score;
};

void InsertSort(ScoreNode array[], int len) {
	for (int i = 2; i <= len; i++) {
		if (array[i].score > array[i - 1].score) {
			array[0] = array[i];
			int j;
			for (j = i; array[j - 1].score < array[0].score; j--) {
				array[j] = array[j - 1];
			}
			array[j] = array[0];
		}
	}
}

void ExchangeSort(ScoreNode array[],int op, int ed) {
	if (op >= ed) {
		return;
	}
	int _op = op;
	int _ed = ed;
	int kid = op;
	while (_op != kid || _ed != kid) {
		while (_ed != kid && array[_ed].score <= array[kid].score) {
			_ed--;
		}
		ScoreNode tmp1 = array[kid];
		array[kid] = array[_ed];
		array[_ed] = tmp1;
		kid = _ed;
		while (_op != kid && array[_op].score >= array[kid].score) {
			_op++;
		}
		ScoreNode tmp2 = array[kid];
		array[kid] = array[_op];
		array[_op] = tmp2;
		kid = _op;
	}
	ExchangeSort(array, op, kid - 1);
	ExchangeSort(array, kid + 1, ed);
}