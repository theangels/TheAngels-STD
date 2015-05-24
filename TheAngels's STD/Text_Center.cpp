#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		val=0;
		cout<<"A():"<<val<<endl;
	}
	A(int v)
	{
		val=v;
		cout<<"A()"<<val<<endl;
	}
private:
	int val;
};
class B:public A
{
public:
	B(int v1,int v2):A(v1),objA(v2)
	{
		cout<<"B()"<<endl;
	}
	B(B &objB)
	{
		cout<<"Copy B()"<<endl;
	}
private:
	A objA;
};
int main(void)
{
	B objB1(2,3);
	B objB2(objB1);
	return 0;
}
