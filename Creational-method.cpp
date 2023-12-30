/* --> This particular example is of Singular pattern -  It lets ensure that class have only one instance created.
 Singleton ensures concurrent access to resource.

 The below code is an example of Printer where in single printer is responsible for printing all the resources
 that are coming one after another.
*/

//  --> Basic shared printer code without design pattern applied. The problem arising here is for every object created, there would be different instances created.

#include <iostream>

using namespace std;

class Singleton
{
private:
    static int counter;

public:
    Singleton() // Constructor made to keep track of number of objects created. Counter will increment when new object is created
    {
        counter++;
        cout << "counter value for object initialization : " << counter << endl;
    };

public:
    void Print(string msg)
    {
        cout << "Printing message : " << msg << endl;
    }
};

int Singleton::counter = 0;

int main()
{
    Singleton *Employeeprint = new Singleton; // In this case, there will be two objcts created. one for Emplyee and another for admin but according to simgular pattern only one instance should be created and not more.
    Singleton *Adminprint = new Singleton;

    Employeeprint->Print("Scheduling print for Employee");
    Adminprint->Print("Scheduling print for Admin");
}

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

//  --> Using Singleton Design Pattern

#include <iostream>

using namespace std;

class Singleton
{
private:
    static int counter;
    static Singleton *instance;

public:
    Singleton()
    {
        counter++;
        cout << "Counter value for object initialization : " << counter << endl;
    };

public:
    static Singleton *GetInstance() // This method will take care whether to initiate new object or not based on the value of instance.
    {
        if (instance == nullptr) // Initially, the instance pointe is set to null, so object will be created for the first time (in this case
        {                        // during EmplyeePrint, line 83), and instance will be pointing to the Singleton class, but for the next time, during adminprint the instance is not null, so same instance will be returned and no additional object will be created.
            instance = new Singleton();
        }
        return instance;
    }
    void Print(string msg)
    {
        cout << "Printing message : " << msg << endl;
    }
};

int Singleton::counter = 0;
Singleton *Singleton::instance = nullptr; // To solve the problem, instance variable is created which is pointer type to Singleton class.

int main()
{
    Singleton *Employeeprint = Singleton::GetInstance();
    Singleton *Adminprint = Singleton::GetInstance();

    Employeeprint->Print("Scheduling print for Employee");
    Adminprint->Print("Scheduling print for Admin");
}
