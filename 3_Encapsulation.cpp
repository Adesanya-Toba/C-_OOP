#include <iostream>

using namespace std;

class Employee {
private: // The private keyword may not be neccessary as all items in a class are private by default, unless specified as otherwise

   /* These properties are now hidden */
   string Name;
   string Company;
   int Age;

public:
   void setName(string name) // setter method
   {
       Name = name;
   }
   string getName() //getter method
   {
       return Name;
   }

   void setCompany(string company)
   {
       Company = company;
   }
   string getCompany()
   {
       return Company;
   }

   void setAge(int age)
   {
       if (age >= 21) // Adding a validation check
       {
           Age = age;
       }
       else cout << "Age should be at least 21. Using previous age." << endl;
   }
   int getAge()
   {
       return Age;
   }

   void IntroduceYourself()
   {
       cout << "Name: " << Name << endl;
       cout << "Company: " << Company << endl;
       cout << "Age: " << Age << endl;
   }

   /* Creating a constructor 
   *  3 rules for creating constructors:
   *  1. Must be public
   *  2. No return type
   *  3. Must have the same name as the class
   */
   Employee(string name, string company, int age)
   {
       Name = name;
       Company = company;
       Age = age;
   }
};

int main()
{
   Employee employee1 = Employee("Toba", "AllBase", 24);
   employee1.IntroduceYourself();

   Employee employee2 = Employee("John", "Amazon", 35);
   employee2.IntroduceYourself();

   employee1.setAge(10);
   cout << employee1.getName() << " is " << employee1.getAge() << " years old." << endl;
}
