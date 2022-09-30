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
#include <bits/stdc++.h>

using namespace std;

bool customCompare(vector<int> &a, vector<int> &b)
{
    vector<int>::iterator p1, p2;
    p1 = a.begin();
    p2 = b.begin();
    int diffA = a[0] - a[1];
    int diffB = b[0] - b[1];

    // p1++; p2++;
    // return diffA < diffB;
    return (*p1 - *(p1 + 1)) < *p2 - *(p2 +1);
}

bool customSort(vector<int> &a, vector<int> &b)
{
    // Sort the individual vectors first
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Sort according to the first element of each vector
    return *a.begin() < *b.begin();
}

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

    vector<int> a {9,0,4,5,2,5,7};
    sort(a.begin(), a.end(), greater<int>());

    for (const auto& v: a) cout << v << " ";
    cout << "\n" << endl;

    vector<vector<int>> b {{2,3}, {4,7}, {9,0}, {6,1}};
    sort(b.begin(), b.end(), customSort);

    vector<vector<int>>::iterator p2 = b.begin();

    for (const auto& v: b) {
        for(auto& v2 : v)
        cout << v2 << " ";
    }
    cout << endl;

    return 0;
}
