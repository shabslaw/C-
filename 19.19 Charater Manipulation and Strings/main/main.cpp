#include <iostream>
#include <cstring>
#include <string>


// CHARACTER MANIPULATION AND STRINGS
int main(){
    // Basic(Better) facilities to handle text data in your C++ programs

    // Character Manipulation.
    // std::isalnum('C');    // check if character is alphanumeric { result is a non-zero or zero }
    // std::isalpha('C');    // check if character is alphabetic { result is a non-zero or zero }
    // std::isblank(' ');    // check if character is blank { result is a non-zero or zero }
    // std::islower('A');    // check if character is lowercase { result is a non-zero or zero }
    // std::isupper('a');    // check if character is uppercase { result is a non-zero or zero }


    char message[] {"My name is Shabs Planta"};
    
    for(auto character : message){
        std::cout << character << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "numbers of 'char' in side 'message array' : " << std::size(message) << std::endl;
    
    
    
    
    
    
    // C-STRING MANUPULATION.

    // std::strlen(message);    // it still works with decayed arrays, pointer, ignores null character.
    // std::strcmp(m1, m2);    // comparing strings, 'clabama' come befor 'blabama' = 1, if 'alabama' does not come befor 'blabama' = -1
    // std::strchr(c-string, target);    // is to search for the first character inside a string, find the first occurence on a character.
    // std::strrchr(c-string, target);    // is to search for the last character inside a string, find the last occurence on a character.

    // std::strcat(string1, string2)      // for concatination, for joining strings.
    // std::strncat(string1, string2, n)      // for concatination n charaters from source to destination, for joining strings.
    // std::strcpy(new_string, string)      // for copying from string to new_string, for copying string.

    
    char message1[] {"My name is Shabs Planta"};
    char message4[] {", I dont smoke weed anymore."};
    const char *message2 = "My name is Shabs Planta ";
    char target {'n'};
    char new_string[40];


    std::cout << std::endl;
    std::cout << "Length of 'Massage' array " << std::strlen(message1) << std::endl;
    std::cout << "Comparing " << std::strcmp(message1, message2) << std::endl;
    std::cout << "Search : " << std::strchr(message2, target) << std::endl;
    std::cout << "Search : " << (std::strrchr(message2, target)) << std::endl;
    std::cout << "Concatenation : " << (std::strcat(message1, message4)) << std::endl;
    std::cout << "Concatenation : " << (std::strncat(message1, message4, 15)) << std::endl;
    // std::cout << "Concatenation : " << (std::strncat(message1, 15)) << std::endl;
    std::cout << message1 << std::endl;

    std::strcpy(new_string, message4);
    std::cout << new_string << std::endl;

    
    // char* message3 = std::strrchr(message1, target);
    // if(message3) {
    //     std::cout << (message3 + 1) << std::endl;
    // }

    // std::cout << (message3) << std::endl;











    // STD::string

    // declaring and Using std::string
    std::string full_name;
    full_name = "Qwan Planta";
    std::string planet {"Earth. where the sky is white"}; // initialize with string literals
    std::string new_planet {planet, 0, 6};
    std::string Prefered_planet{planet};  // initialize with other existing string
    std::string s_message {"Hello there", 5};  // initialize with part of a string literal. contains Hello.
    std::string weird_message {4, 'e'};  // initialize with multiple copys of a char. contains eeee.
    std::string greetings {"Hello World!"};  
    std::string saying_hello{ greetings,6,5 }; // initialize with part of an existing std::string  // starting at index 6, taking 5 characters.  // will contain World!.



    std::cout << std::endl;
    std::cout << "Full_name : " << full_name << std::endl;
    std::cout << "Planet : " << planet << std::endl;
    std::cout << "prefered_Planet : " << new_planet << std::endl;
    std::cout << "Message : " << s_message << std::endl;
    std::cout << "Weird Message : " << weird_message << std::endl;
    std::cout << "Greetings : " << greetings << std::endl;
    std::cout << "Greet : " << saying_hello << std::endl;
    // std::cout << "Full_name : " << full_name << std::endl;



    return 0;
}
 