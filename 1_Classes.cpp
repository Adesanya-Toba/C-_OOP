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
};

int main()
{
   Employee employee1; // uses the default constructor.
   employee1.Name = "Toba";
   employee1.Company = "AllBase";
   employee1.Age = 25;
    
   employee1.IntroduceYourself();
   
   /* Employee* test;
   test->Age = 60;
   test->IntroduceYourself();*/
}
