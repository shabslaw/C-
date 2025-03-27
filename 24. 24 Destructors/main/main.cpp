#include <iostream>
#include "dog.h"


// Constructor and Destructors.
int main(){
    
    // STACK Object
    /*
    Dog second_dog1("Toni1", "Bull-Dog", 2);
    Dog second_dog2("Toni2", "Bull-Dog", 2);
    Dog second_dog3("Toni3", "Bull-Dog", 2);
    Dog second_dog4("Toni4", "Bull-Dog", 2);
    second_dog1.barck();
    second_dog2.barck();
    second_dog3.barck();
    second_dog4.barck();
    std::cout << "Done!" << std::endl;
    */
   
   
   
   
   // *** The This Pointer ***
   Dog first_dog("nana", "parlor dog", 3);


   /*     Conflicting names
   void show_function(std::string_view& dog_param){
        // dog_param = dog_param;  Error
        this->dog_param = dog_param;
   }


       //  Chained calls using pointers
        Dog * dog1 = new Dog("lolo", "li", 3);
        dog1->info();

        // **** Chained Calls Using Pointers
        dog1->set_name("lolo")->set_dog_breed("li")->set_dog_age(3);
        dog1->info();

        delete dog1;   // *** Release it from memory ***

        // **** Chained Calls Using Reference
        dog1->set_name("lolo").set_dog_breed("li").set_dog_age(3);
        dog1->info();

        delete dog1;   // *** Release it from memory ***
   */


    return 0;
}
 