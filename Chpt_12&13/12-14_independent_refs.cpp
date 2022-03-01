/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Independent References
 * 
 * This is essentially creating another name for an object variable.
 * Independent references are not really useful because it can confusing having two
 * names for the same variable in your program.
*/
#include <iostream>
using namespace std;

int main()
{
    int a;
    int &ref = a; // Independent reference

    a = 10;
    cout << a << " " << ref << "\n";

    ref = 100;
    cout << a << " " << ref << "\n";

    int b = 19;
    ref = b; // this puts b's value into a
    cout << a << " " << ref << "\n";

    ref--; // this decrements the new value of a which is now b's value
    cout << a << " " << ref << "\n";

    return 0;
}