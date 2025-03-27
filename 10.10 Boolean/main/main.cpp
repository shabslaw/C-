#include <iostream>


// BOOLEANS true/false
int main(){

    bool red_light {true};
    bool green_light {false};

    if(red_light == true){
        std::cout << "Stop!" << std::endl;
    } else {
        std::cout << "Go!" << std::endl;
    }
    

    if(green_light){
        std::cout << "The Light is Green." << std::endl;
    } else {
        std::cout << "The Light is not Green." << std::endl;
    }


    // printing out a bool
    // 1 -->> true
    // 2 -->> false
    std::cout << std::endl;
    std::cout << "Red Light :" << red_light << std::endl;
    std::cout << "Green Light :" << green_light << std::endl;

    // print out true and false
    std::cout << std::endl;
    std::cout << std::boolalpha; // Forces the output format to true/false
    std::cout << "Red Light :" << red_light << std::endl;
    std::cout << "Green Light :" << green_light << std::endl;


    // Boolean occupy 8 Bits in memory
    // It take up 1 byte in memory
    return 0;
}

