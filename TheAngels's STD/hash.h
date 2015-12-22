#include<stdio.h>
#include<iostream>
using namespace std;

#define KeyType int

typedef struct{
	KeyType key;
	int count;
}ElemType,HashTable[13];

class hash{
public:
	hash(KeyType x[], int n){
		len = n;
		for(int i = 0; i < 13; i++){
			ha[i].count = 0;
			ha[i].key = -1;
		}
		for(int i = 0; i < n; i++){
			InsertHT(x[i]);
		}
	}
public:
	bool InsertHT(KeyType k){
		ElemType in;
		in.count = 1;
		in.key = k;
		int f = k % 13;
		if(ha[f].key!=-1){
			for(int i = 1; i <= 13/2; i++){
				int flag = 1;
				for(int j = 0; j < 2; j++){
					in.count++;
					int tmp = (f + i*i * flag + 13*13) % 13;
					if(ha[tmp].key == -1){
						ha[tmp] = in;
						return true;
					}
					flag = -flag;
				}
			}
			return false;
		}
		else{
			ha[f] = in;
			return true;
		}
	}
public:
	int SearchHT(KeyType k){
		int f = k % 13;
		if(ha[f].key==k){
			return f;
		}
		else if(ha[f].key == -1){
			return -1;
		}
		else{
			for(int i = 1; i <= 13/2; i++){
				int flag = 1;
				for(int j = 0; j < 2; j++){
					int tmp = (f + i*i * flag + 13*13) % 13;
					if(ha[tmp].key == k){
						return tmp;
					}
					else if(ha[tmp].key == -1){
						return -1;
					}
					flag = -flag;
				}
			}
			return -1;
		}
	}
public:
	void DispHT(){
		int sum = 0;
		for(int i = 0; i < 13; i++){
			cout << "id: " << i << " " << "value: " << ha[i].key << " " << "count: " << ha[i].count << endl;
			sum += i * ha[i].count;
		}
		double cal = sum * 1.0 / len;
		cout << "avg: " << cal << endl;
	}
private:
	HashTable ha;
	int len;
};