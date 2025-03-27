#include <iostream>


// CONDITIONAL OPERATION
int main(){

    // IF STATEMENT
    bool tayo {true};

    if (tayo){
        std::cout << "Go and collect your money." << std::endl;
    } else {
        std::cout << "No money for you today!" << std::endl;
    }
    



    // SWITCH
    // Testing for several different conditions
    int tool{55};

    switch (tool){
        case 23:{
            std::cout << "Yes it PEN" << std::endl;
        }
        break;
        case 22:{
            std::cout << "Yes it SWEEP" << std::endl;
        }
        break;
        case 55:{
            std::cout << "Yes it is a BIG PEN" << std::endl;
        }
        break;
        default:{
            std::cout << "No it's NOTHING" << std::endl;
        }
        break;
    }




    // TERNARY OPERATION

    int max{};

    int a {3};
    int b {4};

    
    std::cout << std::endl;

    if(a > b){
        max = a;
    } else {
        max = b;
    }

    
    std::cout << "Max : " << max << std::endl;

    max = (a > b) ? a : b;

    std::cout << "Max2 : " << max << std::endl;


    // LOOPs
    // For loops

    
    std::cout << std::endl;

    for(unsigned int i{}; i < 10; i++){
        std::cout << "I LOVE C++" << std::endl;
    }

    for(size_t i{}; i < 10; i++){
        std::cout << "I LOVE size_t in C++" << std::endl;
    }


    // While loops
    std::cout << std::endl;

    const unsigned int count{10};
    unsigned int j{0};

    while (j < count){
        std::cout << "While Loop" << j*2 << std::endl; ++j;
    }
    
    

    // Do While loops
    std::cout << std::endl;

    const int count_num{10};
    int k{0};
    
    do{
        std::cout << "DO While Loop : " << k << std::endl; 
        ++k;

    }while (k < count_num);
    

    return 0;
}
 