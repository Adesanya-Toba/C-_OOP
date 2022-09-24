/**
 * @file 24-2_Vectors_w_iterators.cpp
 * @author Toba Adesanya (toba@shyftpower.com)
 * @brief  Accessing vectors with iterators
 * 
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    vector <char> v(10); // Creates a char vector of size 10

    /**
     * @brief An iterator is simply defined by the container class.
     *        To declare an iterator of a particular container class, you 
     *        simply need to qualify the iterator with the name of the container. 
     * 
     */
    vector <char>::iterator p; // Creates an iterator
    
    int i;

    // Assign elements in the vector a value
    p = v.begin();
    i = 0;
    while (p != v.end())
    {
        *p = i + 'a';
        p++;
        i++;
    }

    cout << "Original contents of vector: \n";
    p = v.begin();
    while (p != v.end()){
        cout << *p << " ";
        p++;
    }
    cout << "\n\n";

    // Change the contents of the vector
    p = v.begin();
    while (p != v.end()){
        *p = toupper(*p);
        p++;
    }

    cout << "Modified contents of vector: \n";
    p = v.begin();
    while (p != v.end()){
        cout << *p << " ";
        p++;
    }
    cout << endl;

    return 0;
}
