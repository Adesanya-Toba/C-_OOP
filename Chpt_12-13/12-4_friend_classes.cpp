/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Friend class
 * 
 * The friend class and all of its member functions
 * have access to the private members defined within the other class
*/
#include <iostream>
using namespace std;

class TwoValues
{
    int a , b;

public:
    TwoValues (int i, int j){
        a = i;
        b = j;
    }

    int add()
    {
        return a + b;
    }
    friend class Min;
};

/**
 * @brief   Friend classes do not inherit members of the other class,
 *          they only have access to it.
*/
class Min
{
public:
    int min(TwoValues x);
    int add_frm_Min();
};

int Min::min (TwoValues x)
{
    return x.a < x.b ? x.a : x.b;
}

int Min::add_frm_Min()
{
    TwoValues x(2, 4);
    return x.add();
}

int main()
{
    TwoValues ob (10, 20);
    Min m;

    cout << m.min(ob);

    return 0;
}
