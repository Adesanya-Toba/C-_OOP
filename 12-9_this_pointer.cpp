/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * The 'this' pointer
 * 
 * Whenever a member funciton is called from an object, it is automatically passed 
 * an implicit argument that is a pointer to (address of) the invoking object.
 * 
 * This let's the member function know which object of the class called it. 
 * This is very important when operators are overloaded in a class or whenever a
 * member function needs to use a pointer to the object that called it.
*/
#include <iostream>
using namespace std;

class pwr
{
    double b;
    int e;
    double val;
public:
    pwr(double base, int exp);
    double get_pwr() { return this->val; }
};

pwr::pwr(double base, int exp)
{
    this->b = base; // just saying that the 'b' to updated here is the copy of 'b' belonging to the invoking object
    this->e = exp;
    this->val = 1;
    
    if(exp == 0) return;
    for ( ;exp > 0; exp--) 
        this->val = this->val * this->b; // nobody really writes it this way though, but we'll see the full use of this pointer soon.
}

int main()
{
    pwr x(4.0, 2), y(2.5, 1), z(5.7, 0);

    cout << x.get_pwr() << " ";
    cout << y.get_pwr() << " ";
    cout << z.get_pwr() << "\n";

    return 0;
}
