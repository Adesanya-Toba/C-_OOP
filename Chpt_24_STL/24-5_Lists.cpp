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
#include <cstdlib>

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
    std::cout << "Reversed contents: ";
    while (p != lst.begin()){
        // NOTE: that lst.end() returns an iterator to the address after the last element in the list
        // therefore, it is neccessary to decrement p first to get the last element
        p--;
        std::cout << *p << " ";
    }
    std::cout << "\n\n";

    // Sorting a list
    std::list<int> lst2;

    for (i = 0; i < 10; i++) lst2.push_back(rand() % 111);

    std::cout << "Original list contents: ";
    for(const auto& l : lst2)
        std::cout << l << " ";
    std::cout << "\n\n";

    std::cout << "Sorted list: ";
    lst2.sort();
    for(const auto& l : lst2) std::cout << l << " ";
    std::cout << "\n\n";

    // Merging lists
    // This will create a combined sorted list and leave the merged list (on the RHS) empty
    std::list<int> l3;
    std::list<int> l4;

    for(i=0; i < 10; i+= 2) l3.push_back(i);
    for(i =1; i < 10; i+=2) l4.push_back(i);

    std::cout << "Original contents:\n";
    for(const auto& l : l3) std::cout << l << " ";
    std::cout << "\n";
    for(const auto& l : l4) std::cout << l << " ";
    std::cout << "\n";

    // Merge the list
    l3.merge(l4);
    if (l4.empty())
        std::cout << "l4 is now empty!\n\n";
    
    std::cout << "Contents after merge: ";
    for(const auto& l : l3) std::cout << l << " ";
    std::cout << "\n\n";

    return 0;
}
