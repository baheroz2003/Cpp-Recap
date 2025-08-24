➡️ OOPs ek programming paradigm hai jo real-world entities (Student, Car, BankAccount)
ko classes and objects ke through model karta hai.
4 pillars of OOPs: Encapsulation, Abstraction, Inheritance, Polymorphism.
#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int age;
    void introduce() {
        cout << "Hi, I am " << name << " and I am " << age << " years old.\n";
    }
};

int main() {
    Student s1;
    s1.name = "Baheroz";
    s1.age = 22;
    s1.introduce();
}
---------------------------------------------------------------------------------------------------------------------
2. Principles of OOPS
Encapsulation → Data + Functions ko ek unit (class) me pack karna.
Abstraction → Implementation detail hide karke sirf functionality dikhana.
Inheritance → Ek class ki properties dusre class me reuse karna.
Polymorphism → Same function ka alag-alag behavior (compile-time ya run-time).
#include <iostream>
using namespace std;
class Animal {
public:
    void eat() { cout << "I can eat\n"; }
};
class Dog : public Animal {
public:
    void bark() { cout << "I can bark\n"; }
};
int main() {
    Dog d;
    d.eat();  // Inherited function
    d.bark();
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------
Class vs Object
Class: Blueprint/template (Student class).
Object: Instance of class (student1, student2).
#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int age;
};
int main() {
    Student s1; // Object
    s1.name = "Baheroz";
    s1.age = 22;
    cout << s1.name << " " << s1.age << endl;
    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------
Pointer to an Object in Heap
👉 Object ko heap me new se allocate karte hain aur pointer hold karta hai.
#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int age;
};

int main() {
    Student *s = new Student;  // heap allocation
    s->name = "Baheroz";
    s->age = 22;
    cout << s->name << " " << s->age << endl;
    delete s; // memory free
}
------------------------------------------------------------------------------------------------------------------------------------
Private data ko direct access ni karna chahiye, getter-setter use karte hain.
#include <iostream>
using namespace std;
class Student {
private:
    int age;
public:
    void setAge(int a) { age = a; }      // Mutator
    int getAge() { return age; }         // Accessor
};

int main() {
    Student s;
    s.setAge(22);
    cout << s.getAge();
}
-------------------------------------------------------------------------------------------------------------------------------------------
👉 Special function jo object banne ke time automatically call hota hai.
Default constructor
Parameterized constructor
Copy constructor
#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int age;
    // Default constructor
    Student() {
        cout << "Default constructor\n";
    }
    // Parameterized constructor
    Student(string n, int a) {
        name = n; age = a;
    }
    // Copy constructor
    Student(const Student &s) {
        name = s.name;
        age = s.age;
    }
};
int main() {
    Student s1;               // default
    Student s2("Baheroz",22); // parameterized
    Student s3(s2);           // copy
    cout << s2.name << " " << s2.age << endl;
}
-----------------------------------------------------------------------------------------------------------------------------
Deep Copy Constructor
👉 Jab object ke andar dynamically allocated memory ho toh shallow copy se dikkat hoti hai, isliye deep copy likhte hain.
Call by Value = Normal copy (ek alag copy banti hai, original safe rehta hai).
Call by Reference = Deep copy jaisa nahi hai, balki same memory share hoti hai (changes reflect ho jaate hain).
#include <iostream>
#include <cstring>
using namespace std;
class Student {
public:
    char *name;

    Student(const char *n) {
        name = new char[strlen(n)+1];
        strcpy(name, n);
    }
    // Deep Copy Constructor
    Student(const Student &s) {
        name = new char[strlen(s.name)+1];
        strcpy(name, s.name);
    }

    ~Student() { delete[] name; }
};
int main() {
    Student s1("Baheroz");
    Student s2 = s1; // Deep copy
    cout << s2.name;
}
-------------------------------------------------------------------------------------------------------------------------
Scope Resolution Operator (::)
👉 Class ke function ko class ke bahar define karne ke liye.
#include <iostream>
using namespace std;
class Student {
public:
    void display();
};
void Student::display() {
    cout << "Hello from Student class\n";
}
int main() {
    Student s;
    s.display();
}
----------------------------------------------------------------------------------------------------------------------------------------------


  



