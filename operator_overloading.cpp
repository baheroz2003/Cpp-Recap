Normal C++ operators (+, -, *, /, ==, <, etc.) numbers aur primitive types pe kaam karte hain.
Lekin agar tumhari apni class hai (jaise Complex, Vector, Matrix),
toh tum chahte ho ki + ya == us class ke objects pe bhi kaam kare.
#include <iostream>
using namespace std;
class Complex {
int real, imag;
public:
Complex(int r=0, int i=0) {
real = r; imag = i;
    }
//yhi hai operator overloading
Complex operator+(Complex const &obj) {
        Complex result;
        result.real = this->real + obj.real;
        result.imag = this->imag + obj.imag;
        return result;
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;  // compiler internally: c1.operator+(c2)
    c3.display();  // Output: 4 + 6i
}
-----------------------------------------------------------------------------------------------------------------------------------------------
class Number {
    int n;
public:
    Number(int x): n(x) {}
    bool operator==(Number const &obj) {
        return this->n == obj.n;
    }
};
int main() {
    Number n1(10), n2(20), n3(10);
    cout << (n1 == n2) << endl; // 0 (false)
    cout << (n1 == n3) << endl; // 1 (true)
}
Syntax:
return_type operator<symbol>(parameters) { ... }
Tum most operators overload kar sakte ho, jaise + - * / % == != << >> [] ().
Kuch operators overload nahi hote (.:, ::, ?:, sizeof).
Operator overloading se tum user-defined types ke liye operators ko natural bana sakte ho.
----------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
class Point {
    int x, y;
public:
    Point(int a, int b): x(a), y(b) {}
    // Friend function for operator overloading
    friend ostream& operator<<(ostream &out, Point const &p);
};
ostream& operator<<(ostream &out, Point const &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
int main() {
    Point p1(10, 20);
    cout << p1 << endl;  // Output: (10, 20)
}
Jab tumhari class ke objects ko readable/printable banana ho
Example:
Agar class Point hai → (10, 20) format me print karna.
Agar class Complex hai → 3 + 4i format me print karna.
Jab input/output operator (cin/cout) ka natural use chahiye ho
Complex c1;
cin >> c1;   // instead of c1.read();
cout << c1;  // instead of c1.display();
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r=0, int i=0): real(r), imag(i) {}

    // Insertion operator
    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    // Extraction operator
    friend istream& operator>>(istream &in, Complex &c) {
        cout << "Enter real and imaginary parts: ";
        in >> c.real >> c.imag;
        return in;
    }
};

int main() {
    Complex c1;
    cin >> c1;       // Input object
    cout << c1;      // Output object
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Kyunki tumhe apne custom objects (Point, Complex, Student, etc.) ko easily print karna hai.
Agar overloading na karo to tumhe manually function likhna padta:
Friend operator overloading
Kuch cases me hume private data members ko access karna hota hai, aur hume operator ko member function ke bahar likhna hota hai.
Tab hum friend function ka use karte hain.
#include <iostream>
using namespace std;
class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    // Friend function declaration
    friend Complex operator+(Complex const &c1, Complex const &c2);
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};
// Friend function definition (class ke bahar)
Complex operator+(Complex const &c1, Complex const &c2) {
    Complex result;
    result.real = c1.real + c2.real;  // direct access to private data
    result.imag = c1.imag + c2.imag;
    return result;
}
int main() {
    Complex a(3, 4), b(5, 6);
    Complex c = a + b;   // operator+ friend function call hoga
    c.display();   // Output: 8 + 10i
    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Private data access
Friend function ko class ke private aur protected members ka access hota hai.
Matlab tumhe unnecessarily getter functions banane ki zarurat nahi.
result.real = c1.real + c2.real;
Symmetry in operations
Member operator overloading me left operand hamesha class ka object hona chahiye.
Agar left operand non-class (jaise int + Complex) ho, toh friend function hi use hota hai.
Complex c1(5, 6);
Complex c2 = 5 + c1;
Better readability:
Jab dono operands ko equal treatment dena ho 
(a + b me a aur b dono object ho ya mixed ho), toh friend function clean hota hai.
Encapsulation break hota hai:Kyunki friend function class ke private data ko directly access kar sakta hai, toh data hiding ka principle thoda kamzor ho jaata hai.
Maintenance tough ho sakti hai:Agar tum har operator ke liye alag-alag friend functions likhoge, toh code lamba aur manage karna mushkil ho sakta hai.
Polymorphism ka fayda nahi milta:
Member functions virtual ho sakte hain, lekin friend functions virtual nahi ban sakte.
Matlab dynamic binding nahi hoti.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




