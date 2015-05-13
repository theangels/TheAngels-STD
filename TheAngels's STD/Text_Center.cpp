#include <fstream>
#include "TheAngels's STD.h"
using namespace std;
class student
{
public:
	void output()
	{
		ofstream outfile("stud.txt", ios::binary);
		if (!outfile)
		{
			cout << "open error!" << endl;
			return;
		}
		outfile.write((char *)&name, strlen(name));//写数据到文件中
		outfile.close();//关闭流
	}
public:
	char* get()
	{
		return name;
	}
private:
	char name[1000-7];
};

int main()
{
	student tst;
	cin >> tst.get();
	tst.output();
	return 0;
}