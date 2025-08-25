Inheritance ka matlab hai – ek class dusri class ke properties & functions ko inherit (use) kar sakti hai.
#include <iostream>
using namespace std;
class Parent {
public:
    void greet() {
        cout << "Hello from Parent" << endl;
    }
};
class Child : public Parent {
    // Child automatically inherits greet()
};
int main() {
    Child obj;
    obj.greet(); // Child ne Parent ka function use kiya
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Real life example – Car inherit karti hai Vehicle se.
class Vehicle {
public:
    void start() { cout << "Vehicle starting..." << endl; }
};
class Car : public Vehicle {
public:
    void horn() { cout << "Car horn beep!" << endl; }
};
int main() {
    Car c;
    c.start(); // Inherited
    c.horn();  // Apna function
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
isA: "Car is a Vehicle" → Inheritance ka use.
hasA: "Car has an Engine" → Composition ka use.
#include <iostream>
using namespace std;
// Engine class
class Engine {
public:
    void start() {
        cout << "Engine start ho gaya!" << endl;
    }
};
// Vehicle base class (isA relationship ke liye)
class Vehicle {
public:
    void drive() {
        cout << "Vehicle chal rahi hai..." << endl;
    }
};
// Car class (Car isA Vehicle aur Car hasA Engine)
class Car : public Vehicle {   // Car isA Vehicle
public:
    Engine e;   // Car hasA Engine
    void startCar() {
        cout << "Car start ho rahi hai..." << endl;
        e.start(); // Engine start bhi call hoga
    }
};
int main() {
    Car c;       // Car object banaya
    c.drive();   // Vehicle wali function call (isA)
    c.startCar(); // Car apni engine ke sath start hoti hai (hasA)
    return 0;
}
Car isA Vehicle → Inheritance use karke Car ne Vehicle ka behaviour le liya.
Car hasA Engine → Composition use karke Car ke andar Engine object rakha hai.
Jab Car start hoti hai → wo apni Engine ko bhi start karwati hai.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
class Parent {
public:
    Parent() {
        cout << "Parent constructor" << endl;
    }
};
class Child : public Parent {
public:
    Child() {
        cout << "Child constructor" << endl;
    }
};
int main() {
    Child obj; 
    return 0;
}
Jab hum Child obj; likhte hain → Child ka object banta hai.
Lekin ek rule hai: Child object banane se pehle Parent ka constructor hamesha call hota hai.
Isliye pehle "Parent constructor" print hoga, uske baad "Child constructor" print hoga.
👉 Matlab:
Sabse pehle Parent class ka constructor run hoga.
Fir Child class ka constructor run hoga.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






