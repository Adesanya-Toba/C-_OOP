/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Friend functions
 * 
 * Friend functions allow functions access to 
 * all private and protected members of a class to 
 * which it is friend to.
*/
#include <iostream>
#include <cstring>

using namespace std;

class myclass
{
    int a, b;

public:
    friend int sum(myclass x);
    void set_ab(int i, int j);
};

void myclass::set_ab(int i, int j)
{
    a = i;
    b = j;
}

// sum is not member function of any class but can access members of 
// myclass because it is a friend function.
int sum(myclass x)
{
    return x.a + x.b;
}

int main()
{
    myclass n;
    n.set_ab(4, 5);

    cout << sum(n);
    return 0;
}
