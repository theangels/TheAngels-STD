#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
typedef char IndexKeyType;//��������
typedef char InfoType;
typedef int KeyType;//ֵ
#define IMaxSize 105
#define MMaxSize 15

struct IndexItem {
	IndexKeyType index[13];    // ����ֵ
	int start;		//�ӱ��е�һ��Ԫ�����ڵĴ洢λ��
};     //����������
struct IndexList {
	IndexItem  in[IMaxSize];    //��in[1]��ʼ���
	int  length;
};            //����������
struct ElemType {
	KeyType   key;//ְ����
	InfoType depart[15];//��������
	bool aLive;
	int next;
};
struct SSTable {
	ElemType  m[MMaxSize];     //��m[1]��ʼ���
	int  length;
};    //��������

class IndexFind {
public:
	IndexFind() {
		cin >> A.length;
		B.length = 0;
		//CreateMainList
		for (int i = 1; i <= A.length; i++) {
			cin >> A.m[i].key >> A.m[i].depart;
		}
		//CreateIndexList
		for (int i = 1; i <= A.length; i++) {
			A.m[i].aLive = true;
			A.m[i].next = 0;
		}
		for (int i = 1; i <= B.length; i++) {
			tmp[i] = 0;
		}
		for (int i = 1; i <= A.length; i++) {
			int FindIndex = false;
			for (int j = 1; j <= B.length; j++) {
				if (strcmp(A.m[i].depart, B.in[j].index) == 0) {
					FindIndex = j;
					break;
				}
			}
			if (FindIndex) {
				A.m[tmp[FindIndex]].next = i;
				tmp[FindIndex] = i;
			}
			else {
				B.length++;
				strcpy(B.in[B.length].index, A.m[i].depart);
				B.in[B.length].start = i;
				tmp[B.length] = i;
			}
		}
	}
public:
	void OutputIndexList() {
		printf("MainList\n");
		for (int i = 1; i <= A.length; i++) {
			if (A.m[i].aLive) {
				printf("%d\t%s\n", A.m[i].key, A.m[i].depart);
			}
		}
		printf("IndexList\n");
		for (int i = 1; i <= B.length; i++) {
			int id = B.in[i].start;
			while (id) {
				if (A.m[i].aLive) {
					printf("%d\t%s\n", A.m[id].key, A.m[id].depart);
				}
				id = A.m[id].next;
			}
		}
	}
	int SearchIndexList(ElemType worker) {
		for (int i = 1; i <= A.length; i++) {
			if (strcmp(B.in[i].index,worker.depart) == 0) {
				for (int j = B.in[i].start; j != 0; j = A.m[j].next) {
					if (A.m[j].key == worker.key && A.m[j].aLive) {
						return j;
					}
				}
			}
		}
		return -1;
	}
	void InsertIndexList(ElemType worker) {
		A.length++;
		A.m[A.length].key = worker.key;
		strcpy(A.m[A.length].depart, worker.depart);
		A.m[A.length].next = 0;
		for (int i = 1; i <= B.length; i++) {
			if (strcmp(B.in[i].index, worker.depart) == 0) {
				A.m[tmp[i]].next = A.length;
				tmp[i] = A.length;
				return;
			}
		}
		B.length++;
		strcpy(B.in[B.length].index, worker.depart);
		B.in[B.length].start = A.length;
		tmp[B.length] = A.length;
	}
	void DeleteIndexList(ElemType worker) {
		int id = SearchIndexList(worker);
		A.m[id].aLive = false;
	}
private:
	SSTable A;
	IndexList B;
	int tmp[15];
};