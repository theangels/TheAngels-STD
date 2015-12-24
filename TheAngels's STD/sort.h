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