Chhote functions ko inline banate hain taaki function call overhead kam ho.
C++ me inline function ek aisa function hota hai jiska code directly function call ke jagah replace ho jaata hai.
Matlab jab tum function ko call karte ho, to control transfer hone ki jagah compiler us function ka code wahi chipka deta hai.
Isse function call ka overhead (stack banan, return address save karna, etc.) kam ho jaata hai → program fast chal sakta hai.
#include <iostream>
using namespace std;
// Inline function
inline int square(int x) {
    return x * x;
}
int main() {
    int a = 5, b = 7;
    cout << "Square of " << a << " is " << square(a) << endl;
    cout << "Square of " << b << " is " << square(b) << endl;
    return 0;
}
✅ Chhote aur frequently used functions ke liye (jaise getters, setters, mathematical formulas).
✅ Code readability ke liye.
Compiler ne replace kar diya:
➡️ Ab koi stack push/pop, control transfer, return address save nahi hua.
➡️ Direct multiplication perform hua → faster execution.
👉 Yaha inline kaam nahi karega, kyunki recursion me compiler har jagah code replace nahi kar sakta (infinite ho jaayega).
Isliye recursive functions me inline avoid karte hain.
This Pointer
👉 Current object ka address hold karta hai.
C++ me har non-static member function ke andar ek hidden pointer hota hai jiska naam this hai.
this pointer current object ka address store karta hai jiske liye function call hua hai.
Matlab agar ek class ke 10 objects hain, aur tum ek object se function call karte ho, to this pointer us object ko point karega.
#include <iostream>
using namespace std;
class Student {
    int age;
public:
    void setAge(int age) {
        // left side 'age' = member variable
        // right side 'age' = parameter
        this->age = age;  // 'this' current object ko point karta hai
    }
    void show() {
        cout << "Age = " << age << endl;
    }
};
int main() {
    Student s1, s2;
    s1.setAge(20);
    s2.setAge(25);
    s1.show(); // Age = 20
    s2.show(); // Age = 25
    return 0;
}
-----------------------------------------
class Number {
    int n;
public:
    Number(int x): n(x) {}
    Number operator+(Number &obj) {
        return Number(this->n + obj.n);
    }
    void show() { cout << n << endl; }
};
int main() {
    Number n1(10), n2(20), n3(0);
    n3 = n1 + n2;   // operator overloading
    n3.show();
}
Expression n1 + n2 ko compiler internally likhta hai:
n1.operator+(n2);
Left side object = n1 → ye this pointer ban gaya.
Right side object = n2 → ye function ka parameter hai.
So function ke andar:
this->n = n1.n (left side object ka data).
obj.n = n2.n (right side object ka data).
Result = 10 + 20 = 30. 
struct me default access modifier public hota hai.
class me default access modifier private hota hai.
#include <iostream>
using namespace std;
struct S {
    int x;   // public by default
};
class C {
    int y;   // private by default
};
int main() {
    S s1;
    s1.x = 10;   // allowed
    // C c1; c1.y = 20; ❌ error
}



