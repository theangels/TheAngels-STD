#include<stdio.h>
#define ElemType int
#define MaxRows 100
typedef struct Node{
	int row;
	int col;
	ElemType val;
	Node *next;
} TripleNode;
typedef struct {
	int m, n, t;
	TripleNode *vector[MaxRows + 1];
} LMatrix;
void Init(LMatrix &T,int m) {
	T.m = 0;
	T.n = 0;
	T.t = 0;
	for (int i = 1; i <= m; i++) {
		T.vector[i] = new TripleNode();
		T.vector[i]->col = 0;
		T.vector[i]->row = 0;
		T.vector[i]->val = 0;
		T.vector[i]->next = NULL;
	}
}
void Input(LMatrix &T, int m, int n) {
	int k = 0;
	int row, col;
	ElemType val;
	scanf("%d%d%d", &row, &col, &val);
	while (row || col || val) {
		TripleNode *tmp = T.vector[row];
		while (tmp->next) {
			tmp = tmp->next;
		}
		TripleNode *add = new TripleNode();
		add->row = row;
		add->col = col;
		add->val = val;
		add->next = NULL;
		tmp->next = add;
		k++;
		scanf("%d%d%d", &row, &col, &val);
	}
	T.m = m;
	T.n = n;
	T.t = k;
}
void Output(LMatrix T) {
	printf("row\tcol\tval\n");
	for (int i = 1; i <= T.m; i++) {
		TripleNode *tmp = T.vector[i] ->next;
		while (tmp) {
			printf("%d\t%d\t%d\n", tmp->row, tmp->col, tmp->val);
			tmp = tmp->next;
		}
	}
}
void Transpostion(LMatrix &T, LMatrix B) {
	for (int i = 1; i <= B.m; i++) {//按行遍历
		TripleNode *tmp = B.vector[i]->next;
		while (tmp) {//遍历B某行的列
			TripleNode *f = T.vector[tmp->col];
			while (f->next) {//遍历T某行的列
				f = f->next;
			}
			TripleNode *add = new TripleNode();
			add->row = tmp->col;
			add->col = tmp->row;
			add->val = tmp->val;
			add->next = NULL;
			f->next = add;
			tmp = tmp->next;
		}
	}
	T.m = B.n;
	T.n = B.m;
	T.t = B.t;
}