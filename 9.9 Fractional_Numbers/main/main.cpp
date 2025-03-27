#include <iostream>
#include <iomanip>


// Fractional Numbers
int main(){

    // Declear and Initialize the Variables
    float num1 {1.12345678901234567890f};
    double num2 {1.12345678901234567890};
    long double num3 {1.12345678901234567890l};

    std::cout << "Float size : " << sizeof(float) << std::endl;
    std::cout << "double size : " << sizeof(double) << std::endl;
    std::cout << "long double size : " << sizeof(long double) << std::endl;

    // Print out precision
    std::cout << std::setprecision(20);
    std::cout << "Num1 is : " << num1 << std::endl;
    std::cout << "Num2 is : " << num2 << std::endl;
    std::cout << "Num3 is : " << num3 << std::endl;

    // Floating problems : The precision is usually too limited
    // for a lot of application
    
    // float num4 {192400023.0f};          // Error : narrowing conversion
    double num4 {192400023.0};          // Error : narrowing conversion


    std::cout << num4 << std::endl;

    // Scientific notation
    // What we have seen so far in terms of floating point types
    // is fixed notation. there is another notation, scientific
    // that is handy if you have really huge numbers or small numbers
    // to represents

    double num5 {192400023};
    double num6 {1.92400023e8};         // multiply with 10 exp(8)       x 10 to the power of 8
    double num7 {1.924e8};              // can ommit the lower 00023
                                        // for simplicity if our application allows    
    double num8 {0.00000000003498};
    double num9 {3.498e-11};            // multiply with 10 exp(-11)

    std::cout << "NUM 5 : " << num5 << std::endl;
    std::cout << num6 << std::endl;
    std::cout << num7 << std::endl;
    std::cout << num8 << std::endl;
    std::cout << num9 << std::endl;


    double num10 {5.9};
    double num11 {};
    double num12 {};

    // Infinity
    double result {num10 / num11};

    // NaN
    double result1 {num11 / num12};

    std::cout << "NUM10 / NUM11 = " << result << std::endl;
    std::cout << "NUM11 / NUM12 = " << result1 << std::endl;
    
    return 0;
}
 