/**
 * @file 15-1_Operator_overload.cpp
 * @author Toba Adesanya
 * @brief Operator functions defines the operations that the overloaded 
 *        operator will perform relative to the class upon which it will work.
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

class loc
{
    int longitude, latitude;

public:
    loc(){};
    loc(int lg, int lt)
    {
        longitude = lg;
        latitude = lt;
    }

    void show()
    {
        cout << longitude << " ";
        cout << latitude << "\n";
    }

    /**
     * Member operator function takes this gneral form:
     * 
     * ret-type class-name::operator#(arg-list)
     * {
     * 
     * }
     */
    loc operator+(loc op2);
    loc operator-(loc op2);
    loc operator=(loc op2);
    loc operator++(); // prefix
    loc operator++(int a); // postfix
};

// Overload + for loc
loc loc::operator+(loc op2)
{
    loc temp;

    /**
     * The reason that the operator+() tkaes only one parameter si that the operand on the 
     * left side of the + is passed implicitly to the function through the this pointer.
     * 
     * When binary operators are overloaded, it is the object on the let that generates the call 
     * to the operator function.
     */
    temp.longitude = op2.longitude + longitude;
    temp.latitude = op2.latitude + latitude;

    return temp;
}

// Overload - for loc
loc loc::operator-(loc op2)
{   
    // Correct way to do this because - doesn't change its operands
    // loc temp;

    // // Notice the order operands
    // temp.longitude = longitude - op2.longitude;
    // temp.latitude = latitude - op2.latitude;

    // return temp;

    longitude = longitude - op2.longitude;
    latitude = latitude - op2.latitude;

    return *this;
}

// Overload assignment for loc
loc loc::operator=(loc op2)
{
    longitude = op2.longitude;
    latitude = op2.latitude;

    return *this; // returns the object that generated the call. This changes the value of the calling object
}

// Overload prefix ++ for loc
loc loc::operator++()
{
    longitude++;
    latitude++;

    return *this; // Derefenced this pointer. This changes the value of the calling object
}

// Overload postfix ++ for loc. Here a has the value 0 and no argument is passed
loc loc::operator++(int a)
{
    longitude++;
    latitude++;

    return *this;
}

int main()
{
    loc ob1(10, 20), ob2(5, 30), ob3(90, 90);

    ob1.show();
    ob2.show();

    ob1 = ob1 + ob2; // Using the overloaded + operator for loc class.
    ob1.show();

    (ob1 + ob2).show(); // This works because the operator function for + returns a temp object

    ++ob1; // Using prefix increment
    ob1.show();

    ob2 = ++ob1;
    ob1.show();
    ob2.show();

    (ob1 - ob2).show();
    ob1.show(); // ob1 has been changed because we used the this pointer. Shouldn't be this way though because the real - operator doesn't changes its operands
    ob2.show(); // ob2 stays the same

    ob1 = ob2 = ob3; // Multiple assignment
    ob1.show();
    ob2.show();

    ob2++; // Uisng postfix increment
    ob2.show();

    return 0;
}
