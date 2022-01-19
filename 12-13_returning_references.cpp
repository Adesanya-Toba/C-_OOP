/**
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Returning References from function calls
 * 
 * References are implicit pointers automatically created when a function takes a '&x' argument.
 * This allows the calling variable itself to be modified when the function is called, because no 
 * copy of the calling argument is made.
 * 
 * Funtions can also return references and allow for a crazy effect of having functions be on the 
 * left hand side of an assignment operator.
*/
#include <iostream>
using namespace std;

char &replace(int i); // this returns a reference

char s[80] = "Hello There";

int main()
{

    replace(5) = 'X'; // this is same as s[5] = 'X'

    cout << s;

    return 0;
}

// Replace() is declared as returning a reference to a character. As replace() is coded,
// it returns a reference to the element of s that is specified by its argument i. The reference returned
// by replace() is then used to in main() to assign to that element the character 'X'.
char &replace(int i)
{
    return s[i];
}
