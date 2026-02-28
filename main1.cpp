#include <iostream>
using namespace std;
struct Student
{
	string name;
	int age;
};
Student s = {"John", 20};

Student &getRefStruct()
{
	return s;
}

int main()
{
	s.name ="Jane";
	s.age = 19;
	Student &sref = getRefStruct();
	// Student &sref = s; 
	cout << sref.name << endl;
	cout << sref.age << endl;

	getRefStruct().age = 21; 
	cout << "After getRefStruct().age ;" << s.age << endl;
}
