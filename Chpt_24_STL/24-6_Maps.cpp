/**
 * @file 24-6_Maps.cpp
 * @author Toba Adesanya (adesanyatoba@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> m;
    int i;

    // Put pairs into map
    for (i = 0; i < 26; i++)
    {
        // m.insert(pair<char, int>('A' + i, 65 + i));

        // Another way to insert without explicitly stating the key and value type
        // make_pair automatically deduces the argument type, however in this case, to prevent the automatic conversion to int
        // due to the addition of i, I had to cast the key back to char.
        m.insert(make_pair(char('A' + i), 65 + i));
    }
    char ch;
    cout << "Enter key: ";
    cin >> ch;

    map<char, int>:: iterator p;

    // Find if the given key exists in the map
    p = m.find(ch);
    if (p != m.end()) cout << "Its ASCII value is: " << p->second << "\n";
    else cout << "Key not in map!\n";

    return 0;
}
