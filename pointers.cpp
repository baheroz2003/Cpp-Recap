Pointer ek variable hota hai jo dusre variable ka memory address store karta hai.
#include <iostream>
using namespace std;
int main() {
    int x = 10;
    int* ptr = &x; // pointer storing address of x

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Pointer ptr me address: " << ptr << endl;
    cout << "Pointer se value (*ptr): " << *ptr << endl;
}
* → dereference (value nikalna), & → address lena
------------------------------------------------------------------------------------------------------------------
int y = 20;
int* p = &y;
cout << "Address of y: " << p << endl;
cout << "Value of y: " << *p << endl;
--------------------------------------------------------------------------------------------------------------------
Efficient memory access (direct address ke through)
Dynamic memory allocation (heap)
Pass by reference (functions me data copy nahi hota)
Data structures (Linked list, Trees, Graphs)
-----------------------------------------------------------------------------------------------------------------------
int* p = new int(50); // heap me ek int allocate kiya
cout << "Heap value: " << *p << endl;
delete p; // memory free karna mat bhoolna
----------------------------------------------------------------------------------------------------------------------
int n;
cin >> n;
int* arr = new int[n]; // heap me array banaya
for(int i=0; i<n; i++) cin >> arr[i];
for(int i=0; i<n; i++) cout << arr[i] << " ";
delete[] arr; // array free
-------------------------------------------------------------------------------------------------------------------------
Pointer math kar skte ho:
p++ → next element ka address
p-- → previous element
p + i → ith element
int arr[3] = {10,20,30};
int* p = arr;
cout << *p << endl;     // 10
cout << *(p+1) << endl; // 20
cout << *(p+2) << endl; // 30
-------------------------------------------------------------------------------------------------------------------------
⚠️ Pointers tricky hote hain:
Dangling pointer (free ke baad use karna)
Memory leak (delete bhool gaye)
Wild pointer (initialize nahi kiya)
----------------------------------------------------------------------------------------------------------------------------
int a = 5;
int &ref = a; // reference
cout << a << " " << ref << endl; // 5 5
ref = 10;
cout << a << " " << ref << endl; // 10 10
--------------------------------------------------------------------------------------------------------------------------------
void update(int &x) {
    x += 10;
}
int main() {
    int num = 20;
    update(num);
    cout << num; // 30
}
----------------------------------------------------------------------------------------------------------------------------------
Dangling pointer matlab aisa pointer jo aise memory location ko point karta hai jo ab valid nahi hai. 
Matlab memory free/delete ho chuki hai lekin pointer us address ko hold kar raha hai.
Isse program me undefined behavior aata hai (kabhi crash, kabhi garbage value).
Example 1: Deleted Memory
#include <iostream>
using namespace std;
int main() {
    int *ptr = new int(10);  // heap me memory allocate
    cout << "Value: " << *ptr << endl;
    delete ptr;  // memory free kar di
    // Ab ptr dangling pointer hai kyunki memory free ho gayi
    cout << "Dangling Pointer: " << *ptr << endl;  // Undefined behavior

    return 0;
}
Example 2: Out of Scope
#include <iostream>
using namespace std;
int* createPointer() {
    int a = 5;
    return &a;  // Local variable ka address return kar rahe ho
}
int main() {
    int* p = createPointer(); 
    cout << *p << endl;  // Dangling pointer (local variable destroy ho gaya)
    return 0;
}
Example 3: Double Free
#include <iostream>
using namespace std;
int main() {
    int *ptr = new int(20);
    delete ptr;   // pehli baar free
    delete ptr;   // dobara free -> undefined behavior
    return 0;
}
Fix Dangling Pointer
Delete ke baad pointer ko NULL karo
delete ptr;
ptr = NULL;
Local variable ka address return na karo
Instead, heap memory return karo ya reference.
👉 Stack me bana hua local variable sirf function ke andar hi zinda rehta hai.
Function ke baahar aate hi memory free ho jaati hai → aur agar tu uska address bahar bhejega toh wo dangling pointer ban jaata hai.
👉 Heap me jo memory allocate karte hain (new / malloc se), wo tab tak rehti hai jab tak tu manually delete / free nahi karta.
👉 Wild pointer ka matlab hai aisa pointer jo declare toh kar diya gaya hai, lekin initialize nahi kiya.
Matlab wo kisi unknown (garbage) memory location ko point kar raha hota hai.
#include <iostream>
using namespace std;
int main() {
    int* p;       // Pointer declare kiya, but initialize nahi
    cout << *p;   // ❌ Undefined behavior (wild pointer)
    return 0;
}
int* p = nullptr;   // C++11 ke baad best practice
// ya
int* p = 0;         // Older C++ me
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
👉 Memory leak tab hota hai jab tum heap memory allocate karte ho new se,
lekin usse free/delete karna bhool jaate ho.
Matlab tumne memory le liya system se, use kar bhi liya,
par wapas system ko return nahi kiya → system ki memory waste ho gayi.
#include <iostream>
using namespace std;
int main() {
    while(true) {
        int* p = new int(10); // Heap me memory allocate
        // delete p;  ❌ Agar delete bhool gaye → leak
    }
    return 0;
}
👉 Upar wale code me infinite loop hai, har baar new int(10) karega → nayi memory allocate hogi
par delete p; nahi likha → purani memory release nahi hogi → system RAM bhar jayegi.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
int main() {
    int* p = new int(10); // Heap allocation
    cout << *p << endl;
    delete p;  // ✅ Memory free kar di
    p = nullptr; // Best practice: dangling pointer se bach gaye
    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Socho tum hotel me room book karte ho (new),
Kaam ho gaya par checkout (delete) karna bhool gaye →
Room kisi aur ke kaam nahi aayega → hotel ke resources waste → yehi hai memory leak.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Wild pointer → pointer garbage address pe point kar raha (kabhi initialize nahi hua).
Dangling pointer → pointer valid tha, lekin jis memory ko point kar raha tha wo free/destroy ho gayi.
Memory leak → tumne memory allocate ki par free karna bhool gaye, memory waste ho gayi.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
needed function pointer and pointer to pointer




