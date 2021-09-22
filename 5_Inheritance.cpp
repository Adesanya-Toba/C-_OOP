//#include <iostream>
//
//using namespace std;
//
///* This is an abstract class
//*   It is a contract which implies that whichever class decides to sign it
//*   must provide the defination of this function 'AskForPromotion'
//*/
//class AbstractEmployee {
//    virtual void AskForPromotion() = 0; // pure virtual(abstract) functions(=0) make it obligatory to provide the implementation of this function.
//};
//
//
//class Employee:AbstractEmployee {
//private: // The private keyword may not be neccessary as all items in a class are private by default, unless specified as otherwise
//
//    /* These properties are now hidden */
//    string Company;
//    int Age;
//
//protected:
//    /* Makes the variable here accesible to the child class */
//    string Name;
//
//public:
//    void setName(string name) // setter method
//    {
//        Name = name;
//    }
//    string getName() //getter method
//    {
//        return Name;
//    }
//
//    void setCompany(string company)
//    {
//        Company = company;
//    }
//    string getCompany()
//    {
//        return Company;
//    }
//
//    void setAge(int age)
//    {
//        if (age >= 21) // Adding a validation check
//        {
//            Age = age;
//        }
//        else cout << "Age should be at least 21. Using previous age." << endl;
//    }
//    int getAge()
//    {
//        return Age;
//    }
//
//    void IntroduceYourself()
//    {
//        cout << "Name: " << Name << endl;
//        cout << "Company: " << Company << endl;
//        cout << "Age: " << Age << endl;
//    }
//
//    /* Creating a constructor */
//    Employee(string name, string company, int age)
//    {
//        Name = name;
//        Company = company;
//        Age = age;
//    }
//
//    void AskForPromotion() {
//        if (Age > 30)
//            cout << Name << " got promoted!" << endl;
//        else
//            cout << Name << ", sorry you are not eligible for a promotion!" << endl;
//    }
//};
//
///* Inheritance
//*  Here class Developer inherits from the parent or super class
//*  'Employee' and therefore has all the attributes of the parent class
//* 
//*  Inheritance's are also private by default, unless made public.
//*  So objects don't have access to parent attributes until it is made public.
//*/
//class Developer: public Employee {
//public:
//    string favProgrammingLang;
//
//    Developer(string name, string company, int age, string favProgrammingLanguage)
//        :Employee(name, company, age) // The employee constructor helps with these parameters
//    {
//        favProgrammingLang = favProgrammingLanguage;
//    }
//
//    void fixBug() {
//        cout << Name << " fixed bug using " << favProgrammingLang << std::endl;
//    }
//};
//
//
//int main()
//{
//    Employee employee1 = Employee("Toba", "AllBase", 24);
//    Employee employee2 = Employee("John", "Amazon", 35);
//    
//    Developer B = Developer("Bruce", "Tesla", 26, "C++");
//    B.fixBug();
//
//    B.AskForPromotion();
//
//}
