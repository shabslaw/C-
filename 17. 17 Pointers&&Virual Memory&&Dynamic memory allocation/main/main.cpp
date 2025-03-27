#include <iostream>

// POINTER
int main(){

    int num {22};

    // Declearation
    int *p_num {&num};
    int *p_functional_num {nullptr};

    // int decimalNum = p_num;

    std::cout << "My result" << num << std::endl;
    std::cout << "Pointer " << p_num << std::endl;



    int num1 {22};

    // Declearation with  numbers
    int *p_num1 {&num1};

    num1 = 25;
    p_num1 = &num1;

    // int decimalNum = p_num;

    std::cout << "Decleared Value : " << num1 << std::endl;
    std::cout << "Pointer " << p_num1 << std::endl;

    std::cout << std::endl;




    
    // Pointer with Char
    char *p_chars {nullptr};

    char chars = 'A';

    p_chars = &chars;

    // int decimalNum = p_num;

    std::cout << "Decleared Value : " << chars << std::endl;
    std::cout << "Pointer " << *p_chars << std::endl;
    

    std::cout << std::endl;
    
    const char * p_chars1 { "Hello World!" };
    // char p_chars1[] { "Hello World!" };
    

    std::cout << "Decleared : " << p_chars1 << std::endl;
    std::cout << "Pointer " << *p_chars1 << std::endl;



    // Virtual memory
    // Each program is abstracted into a process, and each process has access to the memory range 0 ~ 2^n -1 where N is 32 on 32bit systems and 64 on 64bit systems.

    // Memory Map is divided into 5 sections  ( Memory Management systems )

    // 1. system
    // 2. stack : Local Variables, function calls.
    // 3. heap  : Additional memory that can be queried for at run time.
    // 4. data
    // 5. text




    // DYNAMIC MEMORY ALLOCATION
    
    
    // STACK

    // - Memory is finite
    // - The developer isn't in full control of the memory lifetime
    // - Lifetime is controlled by the scope mechanism

    std::cout << std::endl;
    // HEAP

    // - Memory is finite
    // - The developer is in full control of when memory is allocated and when its released
    // - Lifetime is controlled explicitly through new and delete operators


    // Using dynamic memory and storing on the HEAP not on the STACK.
    int * new_num {nullptr};
    new_num = new int;
    
    *new_num = 44;

    std::cout << *new_num << std::endl;

    // Releasing and Resetting
    delete new_num;
    new_num = nullptr;


    int *p_number5{ new int}; // Memory location contains Junk value
    int *p_number6{ new int (22)}; // use direct initialization
    int *p_number7{ new int { 23 } }; // use uniform initialization

    std::cout << std::endl;
    std::cout << "P_number5 : " << *p_number5 << std::endl;
    std::cout << "P_number6 : " << *p_number6 << std::endl;
    std::cout << "P_number7 : " << *p_number7 << std::endl;

    
    std::cout << std::endl;
    
    // Releasing and Resetting
    delete p_number5;
    p_number5 = nullptr;
    
    delete p_number6;
    p_number6 = nullptr;
    
    delete p_number6;
    p_number6 = nullptr;


    // Handling the Exception mechine.
    /*
    for (size_t i{}; i < 10000000; i++){
        
        try{
            int* lots_of_ints3 { new int[10000000] };
        }catch(std::exception& ex){
            std::cout << "Cought exception ourselves : " << ex.what() << std::endl;
        }
    }

    for (size_t i{}; i < 10000000000; i++){

        int* lots_of_ints4 { new(std::nothrow) int[10000000] };

        if(lots_of_ints4 == nullptr){
            std::cout << "Memory allocation failed" << std::endl;
        }else{
            std::cout << "Memory allocation succeeded" << std::endl;
        }
    }
    */

    return 0;
}
 