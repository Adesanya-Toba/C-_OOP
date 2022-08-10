/**
 * @file    18-2_Explicit_specialization.cpp
 * @author  Toba Adesanya
 * @brief   Here, a generic/template function is overloaded to work with a specific 
 *          argument data type. This overload will override the generic function
 *          the compiler would have otherwise created for this data type.
 *          
 *          If the data type of the explicitly specialized version is found, the compiler
 *          simply invokes the specialized version.
 * 
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

template <class X> void swapargs(X &a, X &b)
{
    X temp;
    
    temp = a;
    a = b;
    b = temp;
    cout << "Inside template swapargs. \n";
}

// This overrides the generic version of swapargs() for ints.
template<> void swapargs<int>(int &a, int &b)
{
    int temp;
    
    temp = a;
    a = b;
    b = temp;
    cout << "Inside swapargs int specialization. \n";
}

int main()
{
    int i = 10, j= 30;
    double x = 10.3, y = 23.7;
    char a = 'x', b = 'z';

    cout << "Original i, j: " << i << " " << j << "\n";
    cout << "Original x, y: " << x << " " << y << "\n";
    cout << "Original a, b: " << a << " " << b << "\n";

    swapargs(i, j); // calls explicitly overloaded swapargs()
    swapargs(x, y); // calls generic swapargs()
    swapargs(a, b); // calls generic swapargs()

    cout << "Swapped i, j: " << i << " " << j << "\n";
    cout << "Swapped x, y: " << x << " " << y << "\n";
    cout << "Swapped a, b: " << a << " " << b << "\n";

    return 0;
}