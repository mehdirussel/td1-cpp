#include "header.h"

#include "Complex2D.h"

#include <cmath>
#include <iostream>
#include <string>

class my_class {
private:
    std::string my_string;
public:
    // Default constructor
    my_class() : my_string("q4 hello world") {}

    // Constructor with argument
    my_class(const std::string &str) : my_string(str) {}

    // Public function to print the variable
    void print_my_element() const {
        std::cout << my_string << std::endl;
    }
};

void printString(const char * s) {
    std::cout << s << std::endl;
}

int main(){
    // q1
    std::cout << "q1 Hello World!" << std::endl;
    // q2
    printString("q2 Hello World!");
    // q3
    printStringFromHeader("q3 Hello World!");
    // q4
    my_class myObj("q4 Hello World!");
    myObj.print_my_element();


// exo2

Complex2D c1(3.0, 4.0);
    Complex2D c2(1.0, 2.0);

    c1.print("c1");
    c2.print("c2");

    // Test addition
    Complex2D c_add = c1 + c2;
    std::cout << "Addition: (" << c_add.getReal() << ", " << c_add.getImag() << "i)" << std::endl;



    // Test multiplication
    Complex2D c_mul = c1 * c2;
    std::cout << "Multiplication: (" << c_mul.getReal() << ", " << c_mul.getImag() << "i)" << std::endl;

    // Test division
    Complex2D c_div = c1 / c2;
    std::cout << "Division: (" << c_div.getReal() << ", " << c_div.getImag() << "i)" << std::endl;


    // Test rotation
    Complex2D c_rot = c1.rotation(3.14159 / 4); // Rotate by 45 degrees
    std::cout << "Rotation: (" << c_rot.getReal() << ", " << c_rot.getImag() << "i)" << std::endl;

    // Test comparison
    bool greater = c1 > c2;
    bool less = c1 < c2;
    std::cout << "c1 > c2: " << greater << std::endl;
    std::cout << "c1 < c2: " << less << std::endl;


    return 0;
}