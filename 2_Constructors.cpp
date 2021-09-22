#include <iostream>

using namespace std;

class Employee {
public:
   string Name;
   string Company;
   int Age;

   void IntroduceYourself()
   {
       cout << "Name: " << Name << endl;
       cout << "Company: " << Company << endl;
       cout << "Age: " << Age << endl;
   }

   /* Creating a constructor */
   Employee(string name, string company, int age)
   {
       Name = name;
       Company = company;
       Age = age;
   }
};

int main()
{
   Employee employee1 = Employee("Toba", "AllBase", 25);
   employee1.IntroduceYourself();

   Employee employee2 = Employee("John", "Amazon", 35);
   employee2.IntroduceYourself();

}
