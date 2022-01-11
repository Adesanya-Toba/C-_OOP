/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Pointer to objects
 * Using pointers to access members of a class given a pointer to 
 * an object.
*/
#include <iostream>
using namespace std;

class c1
{
    int i;
public:
    c1() {i=0;}
    c1(int j) {i = j;}
    int get_i() {return i;}
};

int main()
{
    c1 ob(89), *p;
    c1 ob2[3] = {1, 2, 3}; // using array initialization to initialize a parameterized constructor
    
    c1 *p2;
    p = &ob; // get the address of ob

    p2 = ob2; // get the start of the array

    cout << p->get_i() << "\n"; // using a pointer to call get_i, which has been set by ob

    for(int i = 0; i < 3; i++)
    {
        cout << p2->get_i() << "\n";
        p2++; // this increments to the next object
    }

    return 0;
}
