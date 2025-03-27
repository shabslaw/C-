#include <iostream>
#include "costains.h"
#include "cylinder.h"



int main(){

    std::cout << "Classes in Multiple File." << std::endl;
    std::cout << std::endl;


    // STACK Objective
    Cylinder cylinder1(5, 20);
    
    std::cout << "Volume : " << cylinder1.volume() << std::endl;
    std::cout << "Height : " << cylinder1.get_height() << std::endl;


    // Manageing a Stack Object through Pointer.
    Cylinder *p_cylinder1 = &cylinder1;
    
    std::cout << std::endl;
    std::cout << "Volume : " << p_cylinder1->volume() << std::endl;      // Using Dash greater than Operator to access information inside it's managed object. ( The pointer call operator )
    std::cout << "Height : " << (*p_cylinder1).get_height() << std::endl;     // Using Dereferencing Pointer to access information inside it's managed Object.
    std::cout << "Height Address : " << p_cylinder1 << std::endl;       // Print Address
    
    
    
    // HEAP Objective
    Cylinder *p_cylinder2 = new Cylinder(4, 16);

    std::cout << std::endl;
    std::cout << "Heap Volume : " << (*p_cylinder2).volume() << std::endl;
    std::cout << "Heap Height : " << p_cylinder2->get_height() << std::endl;
    std::cout << "Heap address : " << p_cylinder2 << std::endl;
    

    delete p_cylinder2;
    p_cylinder2 = nullptr;



    // Destractors
    
    
    return 0;
}
 