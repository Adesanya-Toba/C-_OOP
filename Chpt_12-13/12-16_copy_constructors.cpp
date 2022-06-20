/**
 * @file 12-16_copy_constructors.cpp
 * @author  Toba Adesanya
 * @brief   Using copy constructors in C++ help prevent problems that might occur
 *          when one object is used to initialize another.
 *          
 *          Copy constructors only apply to initializations.
 * @version 0.1
 * @date 2022-06-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

class array 
{
    int *p;
    int size;
public:
    array(int sz)
    {
        try{
            p = new int [sz];
        }catch (bad_alloc xa){
            cout << "Allocation failure\n";
            exit(EXIT_FAILURE);
        }
        size = sz;
    }
    ~array(){ delete []p;}

    // Copy constructor
    array(const array &a); // The first argument must be a reference to the object doing the initializing.

    void put(int i, int j)
    {
        if (i > 0 && i < size) {
            p[i] = j;
        }
    }

    int get(int i)
    {
        return p[i];
    }
};

array::array(const array &a)
{
    int i;

    try{
        p = new int [a.size];
    }catch (bad_alloc xa)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    for (i = 0; i <a.size; i++)
    {
        p[i] = a.p[i];
    }
}

int main()
{
    array num(10); // Uses normal constructor
    int i;

    for(i = 0; i <10; i++) num.put(i, i);
    for(i = 0; i<10; i++) cout << num.get(i);
    cout << "\n";

    // Create another object using num to initialize it
    array x(num); // Invokes the copy constructor
    for(int i = 0; i < 10; i++)
    {
        cout << x.get(i);
    }
    cout << "\n";
    
    return 0;
}
