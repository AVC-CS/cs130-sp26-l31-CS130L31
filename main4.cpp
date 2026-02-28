#include <iostream>
using namespace std;

struct MyStruct {
    int value;
    string strvalue;
};

void changeStruct1(MyStruct ms);
void changeStruct2(MyStruct &ms);
void changeStruct3(MyStruct *ms);

int main()
{
    MyStruct ms = {100, "Hello"};

    changeStruct1(ms);
    cout << "**** After changeStruct(ms) ****  " << endl;
    cout << "The field value is " <<  ms.value << endl;
    cout << "The field strvalue is " <<  ms.strvalue << endl;

    changeStruct2(ms);
    cout << "**** After changeStruct2(ms) ****  " << endl;
    cout << "The field value is " <<  ms.value << endl;
    cout << "The field strvalue is " <<  ms.strvalue << endl;

    changeStruct3(&ms);
    cout << "**** After changeStruct3(&ms) ****  " << endl;
    cout << "The field value is " <<  ms.value << endl;
    cout << "The field strvalue is " <<  ms.strvalue << endl;
    
}

void changeStruct1(MyStruct ms){
    ms.value = 200;
    ms.strvalue = "World";
}

void changeStruct2(MyStruct &ms){
    ms.value = 300;
    ms.strvalue = "Hello";
}

void changeStruct3(MyStruct *ms){
    ms->value = 400;
    ms->strvalue = "World";
}
