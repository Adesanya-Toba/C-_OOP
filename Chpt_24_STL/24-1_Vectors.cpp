/**
 * @file   24-1_Vectors.cpp
 * @author Toba Adesanya 
 * @brief 
 * @version 0.1
 * @date 2022-08-20
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
    vector<char> v(10); // Creates a char vector of lenght 10
    int i;

    // Display the original size of v
    cout << "Size = " << v.size() << endl;

    // Assign elements in the vector some values
    for(i = 0; i < 10; i++) v[i] = i + 'a';

    // Print contents of v
    cout << "Current contents: \n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n\n";

    // Expanding the contents of the vector
    cout << "Expanding vector\n";
    for (i = 0; i <10; i++) v.push_back(i + 10 + 'a');
    
    // Display the current size of v
    cout << "Size now = " << v.size() << endl;

    // Print contents of v
    cout << "Current contents: \n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n\n";
    
    // Change contents of v
    for (i = 0; i < v.size(); i++) v[i] = toupper(v[i]);
    cout << "Modified contents: \n";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    v.push_back('c');

    for(const auto& my_v : v) cout << my_v << " "; // Using range-based for loops
    
    return 0;
}