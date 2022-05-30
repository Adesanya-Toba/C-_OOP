/**
 * @file    18-1_Templates.cpp
 * @author  Toba Adesanya
 * @brief   A generic funtion defines a general set of operations that will
 *          be applied to various types of data. The type of data that the function will 
 *          operate upon is passed to it as a parameter.
 * 
 *          It has the following format:
 *          template <class Ttype> ret_type func_name(parameter list)
 *          {
 *              // Body of the function
 *          }
 *          
 *          We can use the keyword 'class' or we could the keyword 'typename'.
 * 
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

// template <class X, class Y> void swapargs(X &a, Y &b);

// This is a function template
template <class X> void swapargs(X &a, X &b) // X just specifies a (flexible) variable type
{
    X temp;
    
    temp = a;
    a = b;
    b = temp;
}

// A template function with two generic types
template <class X, class Y>
void myPrint(X var1, Y var2)
{
    cout << var1 << ' ' << var2 << '\n';
}

int main()
{
    int i = 10, j= 30;
    double x = 10.3, y = 23.7;
    char a = 'x', b = 'z';

    cout << "Original i, j: " << i << " " << j << "\n";
    cout << "Original x, y: " << x << " " << y << "\n";
    cout << "Original a, b: " << a << " " << b << "\n";

    swapargs(i, j); // swap integers
    swapargs(x, y); // swap doubles
    swapargs(a, b); // swap chars

    cout << "Swapped i, j: " << i << " " << j << "\n";
    cout << "Swapped x, y: " << x << " " << y << "\n";
    cout << "Swapped a, b: " << a << " " << b << "\n";

    int var = 90, *p;
    p = &var;

    myPrint("Hello World", 345);
    myPrint(*p, "I just printed a pointer!");

    return 0;
}