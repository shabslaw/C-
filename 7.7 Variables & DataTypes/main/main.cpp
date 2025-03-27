#include <iostream>


// NUMBER SYSTEMS in the bit world.
int main(){

    int number1 = 0x6b;    // Hexadecimal
    int number2 = 81;     // Decimal
    int number3 = 0117;    // Octal
    int number4 = 0b00001111;    // Binary

    std::cout << number1 << std::endl;
    std::cout << number2 << std::endl;
    std::cout << number3 << std::endl;
    std::cout << number4 << std::endl;


    // VARIABLES & INTEGERS

    // Variables braced initialization
    int elephant_count;  //random garbage value.
    int lion_count {};
    int dog_count {10};
    int cat_count {15};

    // you can express an initializer
    int domesticated_animals {dog_count + cat_count};

    // 2.9 is for type double, with a wider range than int.ERROR or WARNING
    double bad_initialization {2.9};

    std::cout << elephant_count << " , " << lion_count << " , " << dog_count << " , " << cat_count << " , " << domesticated_animals << " , " << bad_initialization << std::endl;

    // Size of a type in memory
    std::cout << sizeof(bad_initialization) << std::endl;
    std::cout << sizeof(int) << std::endl;

    // Typename
    typename boy_in {20};
    std::cout << boy_in << std::endl;


    return 0;
}
 