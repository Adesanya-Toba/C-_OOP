/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Static member variables
 * 
 * There is only a single copy of this variable regardless of the 
 * number of objects created from the class. This allows all objects of a 
 * class to share a single variable by declaring as static.
*/
#include <iostream>
using namespace std;

class shared
{
    int b;
public:
    static int a;

    void set(int i, int j) {a = i; b = j;}
    void show();
};

// For static member variables, we have to define them outside the class to allocate storage for it
// because in the class, it is only declared. Here it is defined actual storage is allocated to it.
// Also because it essentially exists outside the creation of any object.
int shared::a;

void shared::show()
{
    cout << "This is static a: " << a;
    cout << "\nThis is non-static b: " << b;
    cout << "\n";
}

int main()
{
    shared x, y;

    x.set(1,1); // set a to 1
    x.show();

    y.set(2,2);
    y.show();

    x.show(); // a should have been changed at this point because it is shared

    // Let's change 'a' again
    cout << "\nChanging 'a' again...\n";
    shared::a = 90;
    x.show();
    y.show();

    return 0;
}
