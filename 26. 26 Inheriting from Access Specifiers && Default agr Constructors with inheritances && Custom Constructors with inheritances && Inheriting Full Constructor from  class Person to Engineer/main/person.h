#ifndef PERSON_H
#define PERSON_H

#include <string_view>
#include <iostream>

class Person{

    // friend std::ostream& operator<<(std::ostream& out, const Person& person){
    //     out << "Person [" << person.first_name << " " << person.last_name << "]";
    //     return out;
    // };

    public :
        Person(){
            std::cout <<  "Default construtor called for Person Called... " << std::endl;
        };

        Person(std::string_view name_param, std::string_view last_name_param)
            : first_name(name_param), last_name(last_name_param)
            {
                std::cout <<  "Custom construtor called for Person Called... " << std::endl;
        };
        
        // Inheriting COPYING an all ready initializer
        Person(const Person& source)
            : first_name{source.first_name}, last_name{source.last_name}
            {
                std::cout <<  "Copy construtor Called... " << std::endl;
        };

        ~Person(){
            std::cout <<  "Destrutor called for Person Called... " << std::endl;

        };

        // Getters
        std::string get_first_name() const { return first_name;}

        std::string get_last_name() const { return last_name;}
        // Setters
        void set_first_name(std::string fn){
            first_name = fn;
        }
        void set_last_name(std::string ln){
            last_name = ln;
        }

    // private :
    protected :
        std::string first_name{"Mysterious"};
        std::string last_name{"Person"};
};


// HOW TO SET UP A "COPY" CONSTRUCTOR.
/*
Person(const Person& source)
    : first_name{source.first_name}, last_name{source.last_name}
{
    std::cout <<  "Copy construtor Called... " << std::endl;
}
*/

#endif