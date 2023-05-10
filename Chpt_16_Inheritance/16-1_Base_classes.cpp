/**
 * @file 16-1_Base_classes.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using std::cout;

class base
{
public:
    base() {cout << "Constructing base\n";}
    ~base(){cout << "Destructing base\n";}

};

class derived1 : public base
{
public:
    derived1(){cout << "Constructing derived1\n";}
    ~derived1(){cout << "Destructing derived1\n";}
};


int main()
{
    derived1 dev;

    int i = 100000000;
    cout << "Starting main\n";

    while(i)
    {
        i--;
    }

    cout << "Ending main\n";
    return 0;

}
