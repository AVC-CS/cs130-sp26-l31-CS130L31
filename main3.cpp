#include <iostream>
using namespace std;

struct MyStruct{
	int value;
	string strvalue;
	int &getValue(){
		return value;
	}
	string &getStrValue(){
		return strvalue;
	}
};

int main()
{
	int num = 10;

	MyStruct ms;
	ms.value = 100;
	cout << "The field value is " <<  ms.value << endl;
	ms.getValue() = 200;
	cout << "The field value is " <<  ms.value << endl;

	ms.strvalue = "Hello";
	cout << "The field strvalue is " <<  ms.strvalue << endl;

	string str = ms.getStrValue();
	cout << "The field strvalue is " <<  str << endl;

	str = "World";
	cout << "The variable str is " <<  ms.strvalue << endl;

	string &strRef = ms.getStrValue();
	strRef = "World";
	cout << "The field strvalue is " <<  ms.strvalue << endl;
}
