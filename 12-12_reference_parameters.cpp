/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Reference Parameters
 * 
 * A reference is essentially an implicit pointer and when it is passed as an 
 * argument to a function, it is called 'call-by-reference parameter passing'.
 * 
 * What this does is, when you create a function that requires a reference parameter
 * like func(int &h), what you have just done is create an implicit pointer to h and 
 * therefore, any modifications to h affect the real h, as a copy of the variable is not
 * made.
*/
#include <iostream>
using namespace std;

void neg_with_pointer(int *i); // Using call by reference
void neg(int &i); // Using reference pointer

void swap(int &i, int &j);

// We can also pass references to objects
class c1{
    int id;
public:
    int i;
    c1 (int i);
    ~c1();
    void neg(c1 &ob) { ob.i = -ob.i; } // this does not create a copy of the class object when it is called.
    void neg_w_copy(c1 ob) { ob.i = -ob.i; } // this creates a copy
};

int main()
{
    int x;
    x = 10;

    cout << x << " negated is: ";
    neg(x);
    cout << x << "\n";

    int a = 90, b = -12;
    cout << "a and b: " << a << " " << b << "\n";
    swap(a,b);
    cout << "swapped\n";
    cout << "a and b: " << a << " " << b << "\n\n";

    c1 o(1);
    c1 o2(2);

    o.i = 99;
    o2.i = 34;

    o.neg(o);
    o2.neg_w_copy(o2); // Doesn't actually negate the variable

    cout << o.i << "\n";
    cout << o2.i << "\n";

    return 0;
}


void neg(int &i) // this will implicitly get the address of i.
{
    // It automatically refers to (implicity points to) the argument used to call the function.
    i = -i; // this is a lot sweeter!!!
}

void neg_with_pointer(int *i) // this will require the address of i.
{
    *i = -(*i);
}

void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

c1::c1(int num)
{
    cout << "Constructing " << num << "\n";
    id = num;
}

c1::~c1()
{
    cout << "Destructing " << id << "\n";
}
