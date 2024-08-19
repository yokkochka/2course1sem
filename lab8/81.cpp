/*
            Automobile - Passenger car
          /
Transport
          \
            Truck

const = 0 in a pure virtual function declaration indicates that the function is abstract (fully virtual)
and has no implementation in the base class. This means that any class that inherits this interface (or
abstract class) must provide its own implementation of this function.
*/

#include <iostream>
#include <string>
using namespace std;

class Transport {
   protected:
    int speed;
    int capacity;

   public:
    Transport(int speed, int capacity) : speed(speed), capacity(capacity) {}
    virtual void move() const = 0;

    virtual int getSpeed() const { return speed; }

    virtual int getCapacity() const { return capacity; }
};

class Car : public Transport {
   protected:
    string model;

   public:
    Car(int speed, int capacity, string model) : Transport(speed, capacity), model(model) {}

    void move() const override { cout << "Car " << model << " moves at speed " << speed << " km/h" << endl; }
};

class PassengerCar : public Car {
   private:
    string purpose;

   public:
    PassengerCar(int speed, int capacity, string model, string purpose)
        : Car(speed, capacity, model), purpose(purpose) {}

    void move() const override {
        cout << "Passenger car " << model << " moves at speed " << speed << " km/h" << endl;
    }
};

class Truck : public Transport {
   private:
    string cargoType;

   public:
    Truck(int speed, int capacity, string cargoType) : Transport(speed, capacity), cargoType(cargoType) {}
    void move() const override {
        cout << "Truck carrying " << cargoType << " moves at speed " << speed << " km/h" << endl;
    }
};

int main() {
    cout << "Сreating objects of the classes Car, Truck, Passenger car" << endl;
    cout << "\nCreating a Car class object: " << endl;
    cout << "Enter model: ";
    string model;
    cin >> model;
    cout << "Enter speed: ";
    int speed;
    cin >> speed;
    cout << "Enter capacity: ";
    int capacity;
    cin >> capacity;
    Car* car1 = new Car(speed, capacity, model);

    cout << "\nCreating a Truck class object: " << endl;
    cout << "Enter type: ";
    cin >> model;
    cout << "Enter speed: ";
    cin >> speed;
    cout << "Enter capacity: ";
    cin >> capacity;
    Truck* truck1 = new Truck(speed, capacity, model);

    cout << "\nCreating a Passenger car class object: " << endl;
    cout << "Enter type: ";
    cin >> model;
    cout << "Enter speed: ";
    cin >> speed;
    cout << "Enter capacity: ";
    cin >> capacity;
    cout << "Enter purpose: ";
    string purpose;
    cin >> purpose;
    PassengerCar* passCar = new PassengerCar(speed, capacity, model, purpose);
    cout << "\n\n";
    car1->move();
    truck1->move();
    passCar->move();
}
