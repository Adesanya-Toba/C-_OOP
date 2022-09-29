/**
 * @file 24-5_Lists.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief List basics
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <list>

int main()
{
    std::list<int> lst; // Creates an empty list
    int i;

    for (i=0; i < 10; i++) lst.push_back(i);

    std::cout << "List size: " << lst.size() << std::endl;
    std::cout << "Contents: ";
    std::list<int>::iterator p = lst.begin(); // Creator iterator of type list
    while(p != lst.end()){
        std::cout << *p << " ";
        p++;
    }
    std::cout << "\n\n";

    // Change the contents of the list
    p = lst.begin();
    while (p != lst.end())
    {
        *p = *p + 100;
        p++;
    }
    std::cout << "Modified contents: ";
    p = lst.begin();
    while (p != lst.end()){
        std::cout << *p << " ";
        p++;
    }
    std::cout << "\n\n";

    // Printing list contents in reverse
    p = lst.end();
    while (p != lst.begin()){
        // NOTE: that lst.end() returns an iterator to the address after the last element in the list
        // therefore, it is neccessary to decrement p first to get the last element
        p--;
        std::cout << *p << " ";
    }

    return 0;
}
