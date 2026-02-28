#include <iostream>
#include "answers.hpp"
using namespace std;

int main() {
    int a = 5, b = 10;

    cout << "Before swapByRef: a=" << a << " b=" << b << endl;
    swapByRef(a, b);
    cout << "After  swapByRef: a=" << a << " b=" << b << endl;

    int x = 20, y = 30;

    cout << "Before swapByPtr: x=" << x << " y=" << y << endl;
    swapByPtr(&x, &y);
    cout << "After  swapByPtr: x=" << x << " y=" << y << endl;

    return 0;
}
