#include <iostream>

// Polymorphism means "many forms." In C++, it allows one function or 
// operator to behave differently based on the context.

// A single device (phone) has different behaviors based on how it is used. That’s polymorphism!
// In C++, polymorphism allows a function to act differently for different objects.

// polymorphism have two types

// 1. Static Polymorphism (Compile Time) | 2. Dynamic Polymorphism (Run time)

// Static Polymorphism also has two types
// 1. operator Overloading 2. function overloading

// O P E R A T O R  O V E R L O A D I N G

class Complex {
public:
    int real, imag;

    // Constructor to initialize values
    Complex(int r, int i) : real(r), imag(i) {}

    // Overloading the + operator
    // c1.operator+(c2)
    Complex operator+(const Complex& obj) {
        // obj is the second operand (c2)
        // operato + function 
        return Complex(real + obj.real, imag + obj.imag);
    }
};

// When you call the function on an object (e.g., c1 + c2), 
// the function implicitly has access to the object's data 
// and methods through the this pointer.

int main() {
    Complex c1(2, 3);  // c1.real = 2, c1.imag = 3
    Complex c2(1, 4);  // c2.real = 1, c2.imag = 4

    Complex c3 = c1 + c2; // Calls operator+()
    // it can be also be written as > c1.operator+(c2);

    std::cout << "Sum: " << c3.real << " + " << c3.imag << "i" << '\n';
    return 0;
}

// SUMMARY

// + The operator + function has access to c1's members (real and imag) because it is called on c1.
// + The parameter obj gives access to c2's members (obj.real and obj.imag).
// + The function combines the values from c1 and c2 to produce a new Complex object (res), 
//   which is returned as the result
