/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Pointers to Derived/Child types
 * 
 * If D is class that is derived from / or a child of the base class B, 
 * a pointer of type B* may be used to point to an object of class D.
 * However, the reverse is not the case, except explicitly casted.
*/
#include <iostream>
using namespace std;

class base{
    int i;
public:
    void set_i(int num) { i = num; }
    int get_i() { return i; }
};

class derived: public base{ // inherting attributes from class base
    int j;
public:
    void set_j(int num) { j = num; }
    int get_j() { return j; }
};

int main()
{
    base *bp;
    derived d;

    bp = &d; // base pointer points to derived object

    // accessing functions derived object using base pointer
    bp->set_i(10);
    cout << bp->get_i() << " ";

    // However, using the base pointer, we can only access inherited functions of the base class and not the member functions of the derived class
    // bp->set_j(20);
    // bp->get_j();

    // To do this, we can cast the pointer to be of type of the derived class
    ((derived*)bp)->set_j(90);
    cout << ((derived *)bp)->get_j() << "\n";


    // Also note that if the base pointer points to an array of objects of the base class, incrementing the pointer will 
    // not iterate to the next derived object in the array, because the pointer is of the base type and incrementing will 
    // cause it to iterate to the address of what it thinks the next object of the base class is.
    derived dy[2];
    bp = dy;

    dy[0].set_i(23);
    dy[1].set_i(49);

    cout << bp->get_i() << " ";
    // bp++; // this does not point to the next derived object

    bp = (derived*)bp + 1; // this does!
    cout << bp->get_i() << "\n"; 

    return 0;
}