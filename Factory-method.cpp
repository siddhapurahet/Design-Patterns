/* This particular example is of Factory pattern - it encapsulates the logic of
creating various classes and let the subclass decide which class to instantiate.

The below code is an exmple of different automobile company having common interface Car and based on the user query,
it will getch the data from respective class through interface.

--> The problem is here, for new car company to be added, there would be change in client code i.e in the int main.
But that need not to be done and only there should be change in respective classses to add or delete.
*/

#include <bits/stdc++.h>

using namespace std;

class Car
{
public:
    virtual string GetCarModel() = 0; // Interface
    virtual int GetCarPrice() = 0;
    virtual string GetCarColor() = 0;
};

class Honda : public Car
{
public:
    string GetCarColor()
    {
        return "Black";
    }
    int GetCarPrice()
    {
        return 2500000;
    }
    string GetCarModel()
    {
        return "AZ234";
    }
};

class BMW : public Car
{
public:
    string GetCarColor()
    {
        return "Grey";
    }
    int GetCarPrice()
    {
        return 10000000;
    }
    string GetCarModel()
    {
        return "WQ3234";
    }
};

class RollsRoyce : public Car
{
public:
    string GetCarColor()
    {
        return "Brown";
    }
    int GetCarPrice()
    {
        return 50000000;
    }
    string GetCarModel()
    {
        return "Phantom";
    }
};

string convertToLower(string str)
{
    for (int index = 0; index < str.size(); index++)
    {
        str[index] = tolower(str[index]);
    }
    return str;
}

int main()
{
    Car *ptr; // As per C++, for accessing interface, a pointer to that class needs to be initialsed and then the object address needs to be given to the pointer (line no. 92) so it points to that class and fetched the vlaues.
    cout << "Enter Car company name :" << endl;
    string car_name;
    cin >> car_name;
    if (convertToLower(car_name) == "honda") // Here, every time different objects would be created for new entry.
    {
        Honda CarDetails;
        ptr = &CarDetails;
    }
    else if (convertToLower(car_name) == "bmw")
    {
        BMW CarDetails;
        ptr = &CarDetails;
    }
    else if (convertToLower(car_name) == "rollsroyce")
    {
        RollsRoyce CarDetails;
        ptr = &CarDetails;
    }
    else
    {
        cout << "Sorry...No cars for this compnay.";
        return 0;
    }
    cout << "Model is : " << ptr->GetCarModel() << endl;
    cout << "color is : " << ptr->GetCarColor() << endl;
    cout << "Price is : " << ptr->GetCarPrice() << endl;
}

//=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

// --> Using Factory Design Pattern

#include <bits/stdc++.h>

using namespace std;

class Car
{
public:
    virtual string GetCarModel() = 0;
    virtual int GetCarPrice() = 0;
    virtual string GetCarColor() = 0;
};

class Honda : public Car
{
public:
    string GetCarColor()
    {
        return "Black";
    }
    int GetCarPrice()
    {
        return 2500000;
    }
    string GetCarModel()
    {
        return "AZ234";
    }
};

class BMW : public Car
{
public:
    string GetCarColor()
    {
        return "Grey";
    }
    int GetCarPrice()
    {
        return 10000000;
    }
    string GetCarModel()
    {
        return "WQ3234";
    }
};

class RollsRoyce : public Car
{
public:
    string GetCarColor()
    {
        return "Brown";
    }
    int GetCarPrice()
    {
        return 50000000;
    }
    string GetCarModel()
    {
        return "Phantom";
    }
};

class CarFactory
{
public:
    virtual Car *CreateCar() = 0; // Interface created for accessing Car properties of that particular compnay mentioned in the return.
};

class HondaFactory : public CarFactory
{
public:
    Car *CreateCar() override
    {
        return new Honda();
    }
};

class BMWFactory : public CarFactory
{
public:
    Car *CreateCar() override
    {
        return new BMW();
    }
};

class RollsRoyceFactory : public CarFactory
{
public:
    Car *CreateCar() override
    {
        return new RollsRoyce();
    }
};

CarFactory *ChooseCarFactory(const string &carName) // In case of new compnay added, just adding that particular car name with corresponding name of CarFactory.
{
    if (carName == "honda")
    {
        return new HondaFactory();
    }
    else if (carName == "bmw")
    {
        return new BMWFactory();
    }
    else if (carName == "rollsroyce")
    {
        return new RollsRoyceFactory();
    }
    else
    {
        cout << "Sorry... No cars for this company." << endl;
        return nullptr;
    }
}

string convertToLower(string str)
{
    for (int index = 0; index < str.size(); index++)
    {
        str[index] = tolower(str[index]);
    }
    return str;
}

void PrintValues(Car *carvalues)
{
    cout << "Model is: " << carvalues->GetCarModel() << endl;
    cout << "Color is: " << carvalues->GetCarColor() << endl;
    cout << "Price is: " << carvalues->GetCarPrice() << endl;
}

int main()
{ // Now, if any new compnyis added, there is no change in client side code.
    cout << "Enter Car company name :" << endl;
    string car_name;
    cin >> car_name;

    string car_name_lower_case = convertToLower(car_name);

    CarFactory *carFactory = ChooseCarFactory(car_name_lower_case);

    if (carFactory != nullptr)
    {
        Car *car = carFactory->CreateCar();
        PrintValues(car);

        delete carFactory;
        delete car;
    }
    else
    {
        cout << "sorry...not available";
        return 0;
    }
}

//= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *
//= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *= *

// --> Factory Abstract Design pattern -  It lets produce families of related objects without specifying
// their concrete(classes that have all methods implemented and methods bodies are complete) classes.

// In the below code, there is an example of falilies of classes i.e Bike and Car and different companies use
// that property of Car and bike through interface.
// The code has been written in C# language.

using System;

namespace AbstractFactory
{

public
    interface Bike
    {
    }
public
    interface Car
    {
    }

public
    class Tatabike : Bike
    {
    public
        void Manufacturer
        {
            Console.WriteLine("Tata Bike");
        }
    }

    public class Tatacar : Car
    {
    public
        void Manufacturer
        {
            Console.WriteLine("Tata Car");
        }
    }

    public class Teslacar : Car
    {
    public
        void Manufacturer
        {
            Console.WriteLine("Tesla Car");
        }
    }

    public class Teslabike : Bike
    {
    public
        void Manufacturer
        {
            Console.WriteLine("Tesla Bike");
        }
    }

    public abstract class VehicleCompany
    {
    public
        abstract Car GetCar() public abstract Bike GetBike()
    }

    public class TeslaCompany : VehicleCompany
    {
    public
        override Bike GetBike()
        {
            return new Teslabike();
        }
    public
        override Car GetCar()
        {
            return new Teslacar();
        }
    }

    public class TataCompany : VehicleCompany
    {
    public
        override Bike GetBike()
        {
            return new Tatabikebike();
        }
    public
        override Car GetCar()
        {
            return new Tatacarcar();
        }
    }

    public class Program
    {
    public
        static void Main(string[] args)
        {

            VehicleCompany Tesla = new TeslaCompany();
            Bike b = Tesla.GetBike();
            Car c = Tesla.GetCar();

            VehicleCompany Tata = new TataC();
            Bike b = Tesla.GetBike();
            Car c = Tesla.GetCar();

            Console.ReadKey();
        }
    }

}
