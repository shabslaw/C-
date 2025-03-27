#include <iostream>

// CHARACTER & TEXT
int main(){

    char character1 {'s'};
    char character2 {'h'};
    char character3 {'a'};
    char character4 {'b'};
    char character5 {'s'};

    std::cout << character1 << std::endl;
    std::cout << character2 << std::endl;
    std::cout << character3 << std::endl;
    std::cout << character4 << std::endl;
    std::cout << character5 << std::endl;

    // Char occupy 1 byte in memory : 2^8 = 256 different values (0 ~ 255)
    std::cout << std::endl;

    char value = 65;  // ASCII character code for 'A'
    std::cout << "value : " << value << std::endl;
    std::cout << "value(int) : " << static_cast<int>(value) << std::endl;



    // AUTO key WORDS in C++
    auto var1 {12};   // decimal
    auto var2 {13.0};  // double
    auto var3 {14.0f};  // float
    auto var4 {15.0l};  // long double
    auto var5 {'e'};    // char

    //int modifier suffixes
    auto var6 {123u};  // unsigned
    auto var7 {123ul};  // unsigned long 
    auto var8 {123ll};  // long long

    std::cout << sizeof(var1) << " Bytes , " << sizeof(var2) << " Bytes , " << sizeof(var3) << " Bytes , " << sizeof(var4) << " Bytes , " << sizeof(var5) << " Bytes , " << sizeof(var6) << " Bytes , " << sizeof(var7) << " Bytes , " << sizeof(var8) << " Bytes " << std::endl;

    return 0;
}
 