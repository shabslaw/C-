#include <iostream>


// Integer Modifiers
int main(){

    // Positive & Negative Integer
    int positive{200};
    int negetive{-200};

    unsigned int positive_num{300};  // requesting for a positive decimal
    signed int negetive_num{-300};   // requesting for a negetive decimal

    std::cout << positive << " , " << negetive << " , " << positive_num << " , " << negetive_num << std::endl;

    // Flaging your Integer
    short short_var {-345};          //  2 bytes
    short int short_int {455};
    signed short signed_short {122};
    signed short int signed_short_int {-45};
    unsigned short int unsigned_short_int {45};
    
    int int_var {55};          //  4 bytes
    signed signed_var {66};
    signed int signed_int {77};
    unsigned int unsigned_int {88};

    long long_var {88};          //  4 or 8 bytes
    long int long_int {33};
    signed long signed_long {44};
    signed long int signed_long_int {44};
    unsigned long int unsigned_long_int {44};

    long long long_long_var {888};          //  8 bytes
    long long int long_long_int {999};
    signed long long signed_long_long {444};
    signed long long int signed_long_long_int {1234};
    unsigned long long int unsigned_long_long_int {1234};

    return 0;
}
 