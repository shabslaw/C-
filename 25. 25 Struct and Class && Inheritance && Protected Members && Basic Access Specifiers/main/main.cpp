#include <iostream>
#include "person.h"
#include "player.h"

// STRUCT : Members are Public by default
struct Cat{
    int num{0};
};

// CLASS : Members are Private by default
class Dog{
    int num{0};
};



/*
int main(){
    
    // Inheritance
    
    Player p1("Basketball");
    p1.set_first_name("Tayo");
    p1.set_last_name("Brown");
    std::cout << "Player : " << p1 << std::endl;


};
*/

/*
int main(){

    // Protected Members
    Player p2("Football", "Planta", "Netflix");

    std::cout << "Protected Member : " << p2 << std::endl;

    return 0;
};
*/


int main(){

    /*
    // *****      Basic class access Specifier

    // PUBLIC  : Anything that is public, private, protected will remain disame.

    class Player : public Person{
        std::cout << " Anything that is public, private, protected will remain disame. " << std::endl;
    }


    // PROTECTED  : Anything that is public & protected will be converted to "protected" why private will remain disame.

    class Player : protected Person{
        std::cout << " Anything that is public & protected will be converted to "protected" why private will remain disame. " << std::endl;
    }


    // PRIVATE  : Anything that is public, private, protected will all be "Private".

    class Player : private Person{
        std::cout << " Anything that is public, private, protected will all be "Private". " << std::endl;
    }

    */

    std::cout << "Basic class access Specifier : " << std::endl;

    return 0;
};
 