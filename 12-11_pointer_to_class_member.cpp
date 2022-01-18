/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Pointers to Class Members
 * 
 * Pointer to members aren't regular C++ pointers, instead a pointer to a member 
 * provides only an offset into an object of the member's class at which that 
 * member (data or function) can be found.
 * 
 * It is an offset to a location in which a member function or data can be found. It doesn't 
 * point to a specific object but the location where a class member is supposed to be 
 * in an object.
*/
#include <iostream>
using namespace std;

class c1{
public:
    c1(int i) {val = i; }
    int val;
    int double_val() { return val+val; }
};

int main()
{
    // Notice we create them as int pointers because the addresses/offset it stores are int-type.
    int c1::*data; // data member pointer
    int (c1::*func)(); // function member pointer
    
    c1 ob1(1), ob2(22); // creating objects of the class

    data = &c1::val; // get the offset for where 'val' will be in a generic object of the c1 class
    func = &c1::double_val; // get offset for generic function 'double_val'

    cout << "Here are the values: " ;
    cout << ob1.*data << " " << ob2.*data << "\n";

    cout << "Here they are doubled: ";
    cout << (ob1.*func)() << " ";
    cout << (ob2.*func)() << "\n\n";

    // We can also access using pointer to objects
    c1 *p;
    p = &ob2;

    cout << "Here is the value from a pointer: ";
    cout << (p->*data) << "\n";
    cout << "Here is the value doubled: ";
    cout << (p->*func)() << "\n";

    return 0;
}
