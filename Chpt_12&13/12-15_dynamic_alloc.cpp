/** 
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Using new and delete to dynamically allocate memory on the heap
 * 
*/
#include <iostream>
#include <new>
#include <cstring>
using namespace std;

class balance{
    double cur_bal;
    char name[80];

public:
    balance(double n, char* s){
        cur_bal = n;
        strcpy(name, s);
    }

    balance(){} // parameterless constructor

    ~balance(){
        cout << "Destructing ";
        cout << name << "\n";
    }

    void set_bal(double n, char* s){
        cur_bal = n;
        strcpy(name, s);
    }

    void get_bal(double &n, char *s){
        n = cur_bal;
        strcpy(s, name);
    }
};

int main()
{
    /********** Allocating an array. *********/
    // One caveat to allocating arrays on the heap is that you cannot given it an initial value;
    int *t, i;

    try {
        t = new int [10]; // allocating a 10 integer array
    }
    catch(bad_alloc xa)
    {
        cout << "Array allocation failed.\n";
        return 1;
    }

    for (i = 0; i < 10 ; i++)
    {
        t[i] = i;
    }
    for (i = 0; i < 10; i++)
        cout << t[i] << " ";
        cout << "\n";
    
    delete [] t; // the [] informs the delete function that array is being released.


    /********** Allocating an object of a class ***********/
    balance *p, *m;
    char s[80];
    double n;

    try
    {
        p = new balance(12387.87, (char*)"Ralph Wilson"); // Using a parameterized constructor
    }
    catch(bad_alloc xa)
    {
        cout << "Allocation failure\n";
        return 1;
    }

    p->get_bal(n,s);

    cout << s << "'s balance is: " << n;
    cout << "\n";

    delete p;

    // Allocating an array of objects
    // The catch to allocating object arrays is that since no array allocated by new can have an initializer,
    // then the class must have a parameterless constructor, if not the C++ compilier will not find a matching constructor
    // to allocate the array of objects to and the program will not compile successfully.
    try{
        m = new balance[3]; // this needs a parameterless constructor.
    }
    catch(bad_alloc xa)
    {
        cout << "Allocation failed";
        return 1;
    }

    m[0].set_bal(12387.67, (char*)"Ralph Wilson");
    m[1].set_bal(144.00, (char*)"A.C Conners");
    m[2].set_bal(-11.23, (char*)"I.M. overdrawn");

    for (i = 0; i < 3; i++)
    {
        m[i].get_bal(n,s);

        cout << s <<"'s balance is: " << n;
        cout << "\n";
    }
    delete [] m;

    return 0;
}
