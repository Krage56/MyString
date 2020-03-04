
#include "MyClass.h"
using namespace std;

int main()
{
    MyString l1, l2(" l2 "), l3 = " l3 ", l4 = l3;
    cout << l2 << l3 << l4 << endl;
    l1 = " l1 ";
    l1 += l2;
    l1 += " l3 ";
    cout << l1 << endl;
    l1 == " l1 l2 l3 "? cout << "equal\n" : cout << "not equal\n";
    l1 == l2?  cout << "equal\n" : cout << "not equal\n";
    MyString l5 = l1.reverse();
    cout << l5 << endl;
    MyString l6;
    l6.isEmpty()? cout << "empty\n" : cout << "not empty\n";
    l5.isEmpty()? cout << "empty\n" : cout << "not empty\n";
    return 0;
}
