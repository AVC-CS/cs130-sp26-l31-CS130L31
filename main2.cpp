#include <iostream>
using namespace std;

int &getRefNum(int &num)
{
	return num;
}

int main()
{
	int num = 10;

	getRefNum(num) = 100;
	cout << "getRefNum(num) = " << getRefNum(num) << endl;
	cout << "num = " << num << endl;

	int &refNum = getRefNum(num);
	cout << refNum << endl;
}
