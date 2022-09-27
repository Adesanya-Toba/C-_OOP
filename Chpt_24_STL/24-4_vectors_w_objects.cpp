/**
 * @file 24-4_vectors_w_objects.cpp
 * @author Toba Adesanya (toba@shyftpower.com)
 * @brief Storing class Objects in Vectors
 *        We have to define some custom/overloaded operators so that
 *        the vector class can correctly handle our user defined class.
 * 
 * @version 0.1
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class DailyTemp{
    int temp;
public:
    DailyTemp() { temp = 0;}
    DailyTemp(int x) {temp = x;}

    DailyTemp &operator=(int x){
        temp = x;
        return *this;
    }

    double get_temp(){ return temp;}

    // Overloading the output stream operator
    friend ostream& operator<<(ostream &out, const DailyTemp &c);

};

// Overloading operators outside of a class structure
bool operator<(DailyTemp a, DailyTemp b)
{
    return a.get_temp() < b.get_temp();
}

bool operator==(DailyTemp a , DailyTemp b)
{
    return a.get_temp() == b.get_temp();
}

/**
 * @brief Overloading the <> stream/insertion operator
 *        - cout is an object of the ostream class
 *        - It has to be overloaded as a global function and made a friend
 *          because it need access to private members of our class.
 *          It has to be made global because if an operator is overloaded as a 
 *          member, then it must be called with the class object on the left hand side
 *          e.g. ob++
 *          For the stream operators, we need them to be on the right side,
 *          e.g. cout << ob.
 *          Therefore, the way to do this is to make the operator overload global with 
 *          two parameters: cout and the object of our class.
 * 
 * @param out 
 * @param c 
 * @return ostream& 
 */
ostream& operator<<(ostream &out, const DailyTemp &c)
{
    out << c.temp << " ";
    return out;
}

int main()
{
    vector<DailyTemp> v;
    int i;

    for(i = 0; i < 7; i++)
    {
        v.push_back(DailyTemp(60 + rand()%30));
    }

    cout << "Farenheit temperatures: \n";
    for (i = 0; i < v.size(); i++)
        cout << v[i].get_temp() << " ";

    cout << endl;

    // Convert to Centigrade (same as Celcius)
    for (auto &i : v)
    {
        i = (i.get_temp() - 32) * 5/9;
    }

    cout << "\nCentigrade temperatures: \n";
    for (auto &i : v) cout << i;
    cout << "\n";

}
