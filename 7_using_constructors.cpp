/** 
 * C++: The Complete Reference
 * by Herbert Schidt
 * 
 * Using a constructor and a destructor 
 * 
*/
#include <iostream>
using namespace std;

#define SIZE 100

// Creating Class Stack
class stack{
    int stck[SIZE];
    int tos;
public:
    stack();
    ~stack();
    void push(int i);
    int pop();
};

// Writing the function implementations
// The constructor
stack::stack()
{
    tos = 0;
    cout << "Stack initailized\n";
}

// The destructor; although this doesn't do much for now
stack::~stack()
{
    cout << "Stack destroyed\n";
}

// Push method
void stack::push(int i)
{
    if (tos == SIZE){
        cout << "Stack is full.\n";
        return;
    }
    stck[tos] = i;
    tos++;
}

// Pop method
int stack::pop()
{
    if (tos == 0){
        cout << "Stack underflow.\n";
        return 0;
    }
    tos--;
    return stck[tos];
}

int main() // you can leave out the 'void' in main in c++
{
    stack a, b; // Creating two stack objects.
    stack c = stack(); // No need to do it like this because the constructor takes no arguments.

    a.push(1);
    b.push(2);

    a.push(3);
    b.push(4);

    cout << a.pop() << " ";
    cout << a.pop() << " ";
    
    cout << b.pop() << " ";
    cout << b.pop() << "\n";

    return 0;

}