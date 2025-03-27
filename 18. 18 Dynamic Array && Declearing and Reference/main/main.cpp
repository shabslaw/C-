#include <iostream>

int main(){

    // Declear a  Variable
    size_t new_arr{10};

    // Dynamic Arrays Allocation
    char ch_new[] {"Hello World1"}; 
    const char *ch_new1 {"It's me again!"};
    
    
    double *P_new_arr1 {new double[new_arr]}; // jonks allocated inside the array
    int *P_new_arr2 {new(std::nothrow) int[new_arr]{}};   // 0's allocated inside the array
    double *P_new_arr3 {new(std::nothrow) double[new_arr]{1,2,3,4,5}};  // 1,2,3,4,5 assigned insid the array, the unassigned is set to 0's


    std::cout << "Dynamic Arrays" << std::endl;
    std::cout << "*P_new_arr1 : " << P_new_arr1[7] << std::endl;
    std::cout << "*P_new_arr2 : " << P_new_arr2[2] << std::endl;
    std::cout << "*P_new_arr3 : " << P_new_arr3[4] << std::endl;
    
    std::cout << std::endl;
    std::cout << ch_new << std::endl;
    std::cout << ch_new1 << std::endl;


    for(size_t i{}; i < new_arr; i++){
        std::cout << i << "  Item = " << P_new_arr3[i] << std::endl;
    }

    // Resetting pointer
    delete[] P_new_arr1;
    P_new_arr1 = nullptr;

    delete[] P_new_arr2;
    P_new_arr2 = nullptr;
    delete[] P_new_arr3;
    P_new_arr3 = nullptr;







    // Declearing and using References
    int int_value {42};
    double double_value {31};

    int& reference_int_value {int_value};
    double& reference_double_value {double_value};


    std::cout << std::endl;
    std::cout << &int_value << std::endl;   // Print the address
    std::cout << reference_int_value << std::endl;
    std::cout << &reference_int_value << std::endl;
    std::cout << reference_double_value << std::endl;
    std::cout << &reference_double_value << std::endl;
    std::cout << std::endl;

    // Modify data through referrence.
    reference_int_value = 72;

    std::cout << reference_int_value << std::endl;
    std::cout << &reference_int_value << std::endl;
    std::cout << int_value << std::endl;


    // Pointer && References
    double double_value1 = 44.5;
    double& reference_double_value1 = double_value1;
    double *p_double_value1{&double_value1};

    std::cout << std::endl;
    std::cout << double_value1 << " : " << &reference_double_value1 << " : " << reference_double_value1 << " : " << p_double_value1 << " : " << *p_double_value1 << std::endl;

    // rewriting
    *p_double_value1 = 70;
    reference_double_value1 = 71;
    
    std::cout << std::endl;
    std::cout << double_value1 << " : " << &reference_double_value1 << " : " << reference_double_value1 << " : " << p_double_value1 << " : " << *p_double_value1 << std::endl;


    // References is like Const pointer which modify variables but not assign new address.
    double double_value2 = 34.5;
    double& reference_double_value2 = double_value2;
    double other_double_value1{100.3};

    reference_double_value2 = other_double_value1;

    std::cout << std::endl;
    std::cout << double_value2 << " : " << &reference_double_value2 << " : " << reference_double_value2 << " : " << other_double_value1 << " : " << &reference_double_value2 << std::endl;


    // Const on References
    int new_int_value = 40;
    int& Reference_new_int_value = new_int_value;
    const int* p_new_int_value {&new_int_value};

    std::cout << std::endl;
    std::cout << "New Int Value : " << new_int_value << std::endl;
    std::cout << "Referwnce New Int Value : " << Reference_new_int_value << std::endl;
    std::cout << "Pointer New Int Value : " << *p_new_int_value << std::endl;
    
    
    Reference_new_int_value++;
    // *p_new_int_value = 39;    // error
    std::cout << std::endl;
    std::cout << "Referwnce New Int Value : " << Reference_new_int_value << std::endl;
    std::cout << "Pointer New Int Value : " << *p_new_int_value << std::endl;

    


    return 0;
}
 