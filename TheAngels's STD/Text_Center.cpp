#include<stdio.h>
#include<string.h>
#define MAXLEN 20
#define MAXROW 5
#define ElemType int
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SString;
typedef struct Node {
	int  row, col;
	ElemType val;
	struct Node *next;
} TripleNode;
typedef struct {
	int m, n, t;
	TripleNode *vector[MAXROW + 1];
} LMatrix;
int Concat(SString &T, SString S1, SString S2) {
	if (S1.length + S2.length > MAXLEN)
		return -1;
	int t = 1;
	T.length = S1.length + S2.length;
	for (int i = 1; i <= S1.length; i++)
		T.ch[t++] = S1.ch[i];
	for (int i = 1; i <= S2.length; i++)
		T.ch[t++] = S2.ch[i];
	T.ch[t] = '\0';
	return 0;
}
void OutputMartix(LMatrix M) {
	printf("row col val\n");
	for (int i = 1; i <= M.m; i++) {
		TripleNode *tmp = M.vector[i];
		while (tmp) {
			printf("%d %d %d\n", tmp->row, tmp->col, tmp->val);
			tmp = tmp->next;
		}
	}
}
int main(void) {
	SString tst, t1, t2;
	scanf("%s%s", t1.ch + 1, t2.ch + 1);
	t1.length = strlen(t1.ch + 1);
	t2.length = strlen(t2.ch + 1);
	if (Concat(tst, t1, t2) == 0) {
		printf("%s\n", tst.ch + 1);
		printf("%d\n", tst.length);
	}
	else
		printf("Overflow!");
}