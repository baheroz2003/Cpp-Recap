#include <iostream>
using namespace std;
void sayHello() {   // function definition
    cout << "Hello, Baheroz!" << endl;
}
int main() {
    sayHello();     // function call
    return 0;
}
----------------------------
Function Overloading
Same function name, but different parameter list.
Compiler decide karta hai kis function ko call karna hai.
int sum(int a, int b) { return a+b; }
double sum(double a, double b) { return a+b; }
---------------------
Function Template
Generic function → ek hi function multiple datatypes ke liye.
#include <iostream>
using namespace std;
template <class T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}
int main() {
    cout << maximum(10, 20) << endl;      // int
    cout << maximum(3.5, 2.5) << endl;    // double
}
--------------------------------------------------------
#include <iostream>
using namespace std;
void greet(string name = "Friend") {
    cout << "Hello " << name << endl;
}
int main() {
    greet();            // default "Friend"
    greet("Baheroz");   // custom
}
----------------------------------------------------------
Parameter Passing
Pass by Value → Copy banti hai (original change nahi hota).
Pass by Address → Pointer use karke actual variable change ho sakta hai.
Pass by Reference → & use karke bina copy ke direct original variable modify.
#include <iostream>
using namespace std;
void change(int x) {
    x = 50;
}
int main() {
    int a = 10;
    change(a);
    cout << a << endl;   // still 10 (copy gaya tha)
}
------------------------------------------------------------
#include <iostream>
using namespace std;
void change(int* x) {
    *x = 50;
}
int main() {
    int a = 10;
    change(&a);
    cout << a << endl;   // ab 50 ho gaya
}
---------------------------------------------------------

#include <iostream>
using namespace std;
void change(int &x) {
    x = 100;
}
int main() {
    int a = 10;
    change(a);
    cout << a << endl;  // ab 100 ho gaya
}
---------------------------------------------------------------------
Return by Address / Return by Reference
Agar local variable ka address return kiya → dangling pointer ban jaata hai ❌
Heap ka address return karna safe hai ✅
Reference return karte time ensure karo ki variable destroy na ho.
----------------------------------------------------------------
#include <iostream>
using namespace std;
int* create() {
    int *p = new int(42);
    return p;   // heap ka address return safe hai
}

int main() {
    int* ptr = create();
    cout << *ptr << endl; 
    delete ptr;
}
-------------------------------------------------------------------------
#include <iostream>
using namespace std;
int& getStaticVar() {
    static int x = 10;   // static scope (lifetime program tak)
    return x;
}
int main() {
    int &ref = getStaticVar();
    ref = 50;
    cout << getStaticVar() << endl;   // 50
}
-------------------------------------------------------------------------------
Local vs Global Variables
Local → sirf function ke andar.
Global → pura program use kar sakta hai.
#include <iostream>
using namespace std;
int g = 100;  // global
int main() {
    int g = 50;  // local
    cout << g << endl;   // prints 50 (local dominates)
    cout << ::g << endl; // prints 100 (global)
}
-----------------------------------------------------------------------------------
Function ke andar bhi lifetime program ke equal hota hai.
Ek hi baar initialize hota hai.
#include <iostream>
using namespace std;
void counter() {
    static int x = 0;  // retains value between calls
    x++;
    cout << x << endl;
}
int main() {
    counter(); // 1
    counter(); // 2
    counter(); // 3
}
--------------------------------------------------------------------------------------------
Recursion
Function calling itself.
#include <iostream>
using namespace std;
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
int main() {
    cout << factorial(5) << endl; // 120
}
---------------------------------------------------------------------------------------------------
Function Pointers
Function ko variable ki tarah treat karna.
Callback functions ke liye use hota hai.
#include <iostream>
using namespace std;
void hello() {
    cout << "Hello Baheroz!" << endl;
}
int main() {
    void (*funcPtr)() = hello; // function pointer
    funcPtr();  // call via pointer
}
--------------------------------------------------------------------------------------------------------------------------------------------
Ek function pointer ek pointer hota hai jo kisi function ka address store karta hai. 
Matlab jaise hum variables ka address pointer me store karte hain, waise hi hum function ka address bhi store kar sakte hain.
#include <iostream>
using namespace std;
void hello() {
    cout << "Hello, world!" << endl;
}
int main() {
    void (*fp)();  // function pointer jo koi function returnType void, args none leta hai
    fp = &hello;   // address of hello function
    (*fp)();       // calling function using pointer
    // fp();       // ye bhi same kaam karega

    return 0;
}
#include <iostream>
using namespace std;
int add(int a, int b) {
    return a + b;
}
int main() {
    int (*fp)(int, int);   // function pointer for int function with 2 int args
    fp = &add;

    cout << "Sum = " << fp(5, 7) << endl; // call using pointer
    return 0;
}
#include <iostream>
using namespace std;
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
// Higher-order function: takes function pointer as parameter
void compute(int x, int y, int (*operation)(int, int)) {
    cout << "Result: " << operation(x, y) << endl;
}
int main() {
    compute(5, 3, add);      // add function bheja
    compute(5, 3, multiply); // multiply function bheja
    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------
pointer to pointer
👉 Simple pointer ek variable ka address store karta hai.
👉 Lekin pointer to pointer ek aise pointer ka address store karta hai jo khud ek pointer hai.
#include <iostream>
using namespace std;
int main() {
    int x = 10;
    int *p = &x;   // p stores address of x
    int **pp = &p; // pp stores address of p
    cout << "x = " << x << endl;
    cout << "*p = " << *p << endl;      // dereference pointer
    cout << "**pp = " << **pp << endl;  // dereference pointer to pointer
    return 0;
}
// x = 10
// *p = 10
// **pp = 10
#include <iostream>
using namespace std;
int main() {
    int x = 42;
    int *p = &x;
    int **pp = &p;
    **pp = 100;  // changing value of x using pointer to pointer
    cout << "x = " << x << endl;
    return 0;
}
// x = 100

















