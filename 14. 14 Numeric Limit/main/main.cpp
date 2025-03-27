#include <iostream>
#include <limits>
#include <cmath>

// NUMERIC LIMIT #include <limit>
int main(){

    // std::numeric_limits<T>::min()
    // std::numeric_limits<T>::max()
    // std::numeric_limits<T>::lowest()

    
    std::cout << "My range for short is " << std::numeric_limits<short>::min() << " to " << std::numeric_limits<short>::max() << std::endl;



    // MATH FUNCTION

    // std::floor()     ===> to round down
    // std::ceil()      ===> to round up
    // std::abs()       ===> 
    // std::cos()
    // std::exp()
    // std::log()
    // std::sqrt()
    // std::pow()
    // std::sin()
    // std::tan()
    // std::round


    double expression1 = std::exp(10);
    int expression2 = std::pow(4,3);
    int expression3 = std::log10(10000);
    int expression4 = std::sqrt(81);
    // double expression2 = std::pow(2.30259,2.30259);

    std::cout << expression1 << " , " << expression2 << " , " << expression3 << " , " << expression4 << std::endl;





    // Weird Integral Type
    // Integral types less than 4 bytes in size don't support arithmetic operations

    

    return 0;
}
 