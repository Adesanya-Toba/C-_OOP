/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Parameterized Constructors
 * 
 * Adding parameters to constructor declarations
*/
#include <iostream>
using namespace std;

class myclass
{
    int a, b;
public:
    // Inline functions
    myclass(int i, int j){a = i; b = j;}
    void show() {cout << a << " " << b << endl;}
};

class myotherclass
{
    int a, b;
public:
    myotherclass(int i){a = i;}
    void show(){cout << a ;}
};

int main()
{
    // Two ways to create ojects of the class
    myclass ob1(3, 5); // Most popular

    myclass ob2 = myclass(8, 9); // Less popular

    // For classes with just one parameter
    myotherclass ob3 = 10; // This works

    ob1.show();
    ob3.show();

    return 0;
}
