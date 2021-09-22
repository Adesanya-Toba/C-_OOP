/**
 * The only difference between a class and a struct is that by default all members 
 * are Public in a struct and Private in a class. 
 * In all other respects, structs and classes are equivalent.
*/
#include <iostream>
#include <cstring>

using namespace std;

struct my_struct{
    my_struct(char*); // constructor
    ~my_struct(); // destructor
    void buildstr(char* s); // public elements of the struct
    void showstr();
private:
    char name[10];
    char str[255];
};

int main()
{
    my_struct s = my_struct("My struct");

    s.buildstr("");
    s.buildstr("Hello ");
    s.buildstr("there.");

    s.showstr();
}

my_struct::my_struct(char *name1)
{
    strcpy(name, name1);
    cout << name1 << " just got created!\n";
}

my_struct::~my_struct()
{
    cout << name <<" just got destroyed!";
}

void my_struct::buildstr(char *s){
    if (!*s) *str = '\0';
    else strcat(str, s);
}

void my_struct::showstr()
{
    cout << str << "\n";
}