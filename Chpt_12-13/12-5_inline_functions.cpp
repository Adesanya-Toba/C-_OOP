/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Inline functions
 * 
 * These are short functions that are not actually called
 * but expanded in line at the point of their invocation.
*/
#include <iostream>
using namespace std;

class myclass
{
    int a, b;
public:

    // Automatic inlining (if possible, i.e if short enough)
    void init(int i, int j){ a = i; b = j; }
    void show();
};

// Creating an inline function
inline void myclass::show()
{
    // Inlining this is kinda reduntant. Since the I/O operation takes far more time and overhead than a function call.
    cout << a << " " << b << endl;
}

int main()
{
    myclass x;

    x.init(10, 20);
    x.show();

    return 0;
}