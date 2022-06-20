/**
 * @file    7_Smart_pointers.cpp
 * @author  Toba Adesanya
 * @brief   Learning about smart pointers. They are basically pointers that automatically 
 *          deallocate when they go out of scope.
 *      
 *          **** Haven't learnt how to allocate smart pointer arrays yet, will come back to this. ****
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> ptr(new int());

    unique_ptr<uint8_t> uniq0 (new uint8_t());
    *uniq0 = 30;
    cout << *uniq0 << endl;

    unique_ptr<int> unqu1 = make_unique<int>(25); // Creates a unique pointer of type int and assigns it the value 25.
    cout << *unqu1 << endl;
    *unqu1 = 50;
    cout << *unqu1 << endl;

    // You can't copy this pointer unless you move it. The assignment operator is overloaded to delete the pointer.
    // unique_ptr<int> unqu2 = unqu1; // Gives an error!
    
    unique_ptr<int> unqu2 = move(unqu1);
    // After moving, the original pointer is set to null and cannot be accessed anymore(i.e. deleted)
    cout << *unqu2 << endl;
    cout << &unqu2 << endl;

    // Making an unique pointer array
    std::unique_ptr<int[]> p(new int[10]);
    // *p = 'h';

    // unique_ptr<int[]> uniq_array[2] = make_unique<int[]>{1, 2,3};
    // cout << sizeof(uniq_array)<< endl;

    // unique_ptr<int[]> unqu3 = make_unique<int>[20];

    //With array of std::string 
    auto strArray = std::unique_ptr<std::string[]>(new std::string[10]);
    // *strArray = "h";
    return 1;
}