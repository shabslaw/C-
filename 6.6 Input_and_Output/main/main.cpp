#include <iostream>

// Input & Output

int main(){

    /*

    // std::cout => printing data to the console(terminal)
    int num {12};
    std::cout << "Hello World! my number is " << num << std::endl;

    // std::cerr => printing error to the terminal
    std::cerr << "std::cerr output : Something went wrong" << std::endl;

    // std::clog => printing a log message to the console
    std::clog << "std::clog output: This is a log message" << std::endl;



    // std::cin => reading data from the terminal
    // Reading Data In ( inputing data )
    int age;
    std::string name;

    std::cout << "Whats your name : " ;
    std::cin >>  name;

    std::cout << "Whats your age : " ;
    std::cin >>  age;

    std::cout << "Hello " << name << "! you are " << age << " years old" << std::endl;
    
    
    // Chaining Data In  ( Inputing Multiple Datas )
    int new_age;
    std::string new_name;

    std::cout << "please type in your name and age, seperate it with a space : " ;
    std::cin >>  new_name >> new_age;

    std::cout << "Hello " << new_name << "! you are " << new_age << " years old" << std::endl;


    */

    // Reading Data with Space ( inputing data )
    int full_age;
    std::string full_name;

    std::cout << "Whats your full name and age : " << std::endl;
    std::getline(std::cin,full_name);

    std::cout << "Whats your age : " << std::endl;
    std::cin >>  full_age;

    std::cout << "Hello " << full_name << "! you are " << full_age << " years old" << std::endl;

    return 0;
}
 