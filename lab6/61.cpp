/*
            Car
          /
Transport
          \
            Express - Train

The speed, capacity, model, type, and number_of_seats_in_the_carriage attributes are declared as class members
and are protected from direct access from outside the class. They are declared with the private or protected
access modifier.

The move() methods in each class provide an interface for interacting with class objects. They use the class
attribute data to print information, but the attributes themselves remain hidden.

The TransportVehicle class serves as a base class, and its attributes and methods are restricted to access
through inheritance.

In the main() function, class objects are created and used through pointers to the TransportVehicle base
class, demonstrating polymorphism and encapsulation.

Thus, the code demonstrates the principle of encapsulation, since it restricts access to class data and
methods while providing an interface for interacting with the objects.

for (int i = 0; i < 3; i++) { ... }: We loop through the vehicles array. At each iteration, we call the move()
method on the object pointed to by vehicles[i]. This demonstrates the principle of polymorphism, since the
move() method will be called according to the type of the object (class) in the array.

*/

#include <iostream>
#include <string>
using namespace std;

class TransportVehicle {
   public:
    TransportVehicle(int speed, int capacity) : speed(speed), capacity(capacity) {}

    virtual void move() { cout << "The vehicle is moving." << endl; }

   protected:
    int speed;
    int capacity;
};

class Car : public TransportVehicle {
   public:
    Car(int speed, int capacity, string model) : TransportVehicle(speed, capacity), model(model) {}

    void move() override { cout << "Car " << model << " moves at speed" << speed << " km/h" << endl; }

   private:
    string model;
};

class Train : public TransportVehicle {
   public:
    Train(int speed, int capacity, string type) : TransportVehicle(speed, capacity), type(type) {}

    void move() override { cout << "Train type" << type << "  moves at speed" << speed << " km/h" << endl; }

   protected:
    string type;
};

class Express : public Train {
   public:
    Express(int speed, int capacity, string trainType, int number_of_seats_in_the_carriage)
        : Train(speed, capacity, trainType),
          number_of_seats_in_the_carriage(number_of_seats_in_the_carriage) {}

    void move() override {
        cout << "Express type " << type << " with " << number_of_seats_in_the_carriage
             << " ... moves at speed " << speed << " km/h" << endl;
    }

   private:
    int number_of_seats_in_the_carriage;
};

int main() {
    cout << "Сreating objects of the classes car, train, express" << endl;
    cout << "\nCreating a car class object: " << endl;
    cout << "Enter car make: ";
    string model;
    cin >> model;
    cout << "Enter car speed: ";
    int speed;
    cin >> speed;
    cout << "Enter car capacity: ";
    int capacity;
    cin >> capacity;
    Car car(speed, capacity, model);

    cout << "\nCreating a train class object: " << endl;
    cout << "Enter train type: ";
    string type;
    cin >> type;
    cout << "Enter train speed: ";
    cin >> speed;
    cout << "Enter train capacity: ";
    cin >> capacity;
    Train train(speed, capacity, type);

    cout << "\nCreating a exspress class object: " << endl;
    cout << "Enter exsprees type: ";
    type;
    cin >> type;
    cout << "Enter number of seats in the carriage: ";
    int number_of_seats_in_the_carriage;
    cin >> number_of_seats_in_the_carriage;
    cout << "Enter train speed: ";
    cin >> speed;
    cout << "Enter train capacity: ";
    cin >> capacity;
    Express express(speed, capacity, type, number_of_seats_in_the_carriage);

    TransportVehicle* vehicles[] = {&car, &train, &express};

    for (int i = 0; i < 3; i++) {
        vehicles[i]->move();
    }
}
