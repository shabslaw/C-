#include <iostream>
#include "person.h"
#include "player.h"
#include "engineer.h"
#include "civileng.h"


/*
//    Inheritance from access specifers
int main(){
    Player p1("Planta", "Shaba", "Football");
    
    std::cout << "My result   = " << p1 << std::endl;

}
*/


/*
// Default agr Constructors with inheritances 
int main(){
    Civileng cep1; /// Default Printing.
}
*/


// Custom Constructors with inheritances
int main(){

    Engineer ep1("James", "Nana", "Road Engineer");  // Custom Printing.
    Civileng cep1("Planta", "Nana", "Road Engineer", "Flooring");  // Custom Printing.

    cep1.civil_engineer_info();
    ep1.engineer_info();
    // std::cout << cep1.Person::get_first_name() << std::endl;
    // std::cout << cep1.get_first_name() << std::endl;
}



/*
// Inheriting Full Constructor from  class "Person" to "Engineer"
int main(){

    Engineer ep1("Planta", "Nana");  // Custom Printing.

    ep1.engineer_info();
}
*/