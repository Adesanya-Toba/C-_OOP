/**
 * @file 24-3_Insert_del_vectors.cpp
 * @author Toba Adesanya (toba@shyftpower.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <char> v(10);
    vector <char> v2;
    char str[] = "<Vector>";
    int i;

    for(i = 0; i < v.size(); i++){
        v[i] = i + 'a';
    }
    for(auto& i : v) cout << i << " ";

    // Copy characters in str into v2
    for (i = 0; str[i]; i++) v2.push_back(str[i]);

    // Display original contents of v
    for(auto& i : v) cout << i << " ";
    cout << "\n\n";

    vector <char>::iterator p = v.begin();
    p += 2; // point to third element

    // Insert 10 X's into v
    v.insert(p, 10, 'X');

    cout << "Size after inserting X's = " << v.size() << endl;
    cout << "Contents after the insert: \n";

    for(auto& i : v) cout << i << " ";
    cout << "\n\n";

    // Remove the added elements
    p = v.begin();
    p += 2; // Point to third element
    v.erase(p, p+10); // erase from p to p+10

    cout << "Size after erasing = " << v.size() << endl;
    cout << "Contents after the erase: \n";

    for(auto& i : v) cout << i << " ";
    cout << "\n\n";

    // Insert v2 into v
    v.insert (p,v2.begin(), v2.end());
    cout << "Size after v2's insertion = " << v.size() << endl;
    cout << "Contents after the insertion: \n";

    for(auto& i : v) cout << i << " ";
    cout << "\n\n";

    return 0;
}