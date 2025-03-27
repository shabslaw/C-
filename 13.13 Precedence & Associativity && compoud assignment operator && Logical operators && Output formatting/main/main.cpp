#include <iostream>
#include <iomanip>


// Precedence and Associativity
int main(){

    // Precedence : which operation to do first
    // Associativity : which direction or which order

    std::cout << "My result" << std::endl;




    // ----------------------------------------------------------------------------------------------------

    // Profix and Postfix + and -

    int value {5};

    std::cout << value++ << std::endl;  // Additional postfix 
    std::cout << value << std::endl;
    std::cout << value-- << std::endl;  // sudtractional postfix
    std::cout << value << std::endl;

    value = 5;
    value++ ;     // addition prefix
    std::cout << value << std::endl;

    value-- ;     // subtraction prefix
    std::cout << value << std::endl;





    
    // ----------------------------------------------------------------------------------------------------

    // Compound Assignment Operators

    value = 45;

    // Addition
    value += 5;
    std::cout << "Addition : " << value << std::endl;

    // subtraction
    value -= 5;
    std::cout << "Subtraction : " << value << std::endl;

    // Multiplication
    value *= 5;
    std::cout << "Multiplication : " << value << std::endl;

    // Division
    value /= 10;
    std::cout << "Division : " << value << std::endl;

    // Modulus
    value %= 8;
    std::cout << "Modulus : " << value << std::endl;






    
    // ----------------------------------------------------------------------------------------------------

    // LOGICAL OPERATORS

    // AND = &&
    // OR = ||
    // NOT = !



    
    // ----------------------------------------------------------------------------------------------------

    // OUTPUT FORMARTING

    // std::endl;
    // std::flush;
    // std::left;
    // std::fixed;
    // std::showbase;           is allowing the result the compiler will give to add the number system in front,
    // std::uppercase;
    // std::dec;                is to show number in decimal
    // std::showpos;            is to show possitive numbers, if is a negetive number it will convert it to a positive number.
    // std::oct;                is to show number in octal  <==> to achieve the result OCT will divide the decimal number by 8 and keep the remainder, then reverse the remainder to get the exact answer the terminal will give.
    
    // std::scientific
    // std::showpoint;          it forces the decimal point to show.
    // std::internal;
    // std::right;
    // std::hex;                is to show number in hexemadecimal  <==> to achieve the result hex will divide the decimal number by 16 and keep the remainder, then reverse the remainder to get the exact answer the terminal will give.
    // std::boolalpha;
    // std::setw();
    // std::setfill();
    // std::setprecision();

    std::cout << "Hello";
    std::cout << "World!";

    std::cout << std::endl;

    std::cout << "Hello Nigga!" << std::endl;
    std::cout << "Hello Shabs!" << std::endl;

    std::cout << std::endl;

    std::cout << "Hello\n";
    std::cout << "World\n";

    // std::setw() 
    std::cout << std::setw(25) << "Unforgetable Table : " << std::setw(5) << "Age" << std::endl;
    std::cout << std::setw(25) << "Hello shabs : " <<std::setw(5) << "25" << std::endl;
    
    std::cout << std::right;  // it align ouptup text to the right
    std::cout << std::setw(25) << "Unforgetable Table : " << std::setw(5) << "Age" << std::endl;
    std::cout << std::setw(25) << "Hello shabs1 : " <<std::setw(5) << "25" << std::endl;
    std::cout << std::left;  // it align ouptup text to the left
    std::cout << std::setw(25) << "Unforgetable Table : " << std::setw(5) << "Age" << std::endl;
    std::cout << std::setw(25) << "Hello shab2 : " <<std::setw(5) << "25" << std::endl;
    
    std::cout << std::right;  // it align ouptup text to the right
    std::cout << std::internal;
    std::cout << std::setw(7) << -204 << std::setw(25) << std::endl;
    std::cout << std::setw(7) << -205 <<std::setw(25) << std::endl;
    
    std::cout << std::left;  // it align ouptup text to the left
    std::cout << std::setfill('-');  // the fill character
    std::cout << std::setw(25) << 300 << std::setw(25) << "hello" << std::setw(25) << 304 << "ayo" << std::endl;
    std::cout << std::setw(25) << 205 << std::setw(25) << "ayo" << std::setw(25) << 334 << "ayo" << std::endl;
    
    bool b1 = true;
    bool b2 = false;

    // boolalpha
    std::cout << std::endl; 
    std::cout << std::boolalpha;  // show true / false
    std::cout << "true : " << b1 << std::endl;
    std::cout << "false : " << b2 << std::endl;
    std::cout << std::noboolalpha;  // show 1 / 0 
    std::cout << "true : " << b1 << std::endl;
    std::cout << "false : " << b2 << std::endl;

    // scientific && Fixed
    double numb {1.34e-10};

    std::cout << std::endl;
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);  // double value ( back to default )
    std::cout << "NUMBER : " << numb << std::endl;

    return 0;
}
 