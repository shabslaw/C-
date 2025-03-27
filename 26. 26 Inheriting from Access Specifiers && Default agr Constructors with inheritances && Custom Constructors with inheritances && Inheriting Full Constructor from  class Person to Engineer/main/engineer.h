#ifndef ENGINEER_H
#define ENGINEER_H

#include <string_view>
#include <iostream>
#include "person.h"


class Engineer : public Person{

    // using Person::Person;  // Inheriting Full Constructor.

    // friend std::ostream& operator<<(std::ostream& out, const Engineer& engineer){
    //     out << "Person [" << engineer.first_name << " " << engineer.last_name << "]";
    //     return out;
    // };

    public :
        
        Engineer(){
            std::cout << "Default construtor called for Engineer Called... " << std::endl;
        };

        Engineer(std::string_view name_param, std::string_view last_name_param, std::string_view engin_param)
            : Person(name_param, last_name_param), t_engineer(engin_param)
            {
                std::cout << "Custom construtor called for Engineer Called... " << std::endl;
        };
        
        // Inheriting COPYING an all ready initializer
        Engineer(const Engineer& source)
            : Person(source), t_engineer{source.t_engineer}
            {
                std::cout <<  "Copy construtor Called... " << std::endl;
        };

        
        ~Engineer(){
            std::cout << "Destrutor called for Engineer Called... " << std::endl;
        };


        // Getters
        std::string get_t_engineer() const { return t_engineer;}

        void engineer_info(){
            std::cout << " Engineer Information  [ Full Names : " << first_name << " " << last_name << ",  Engineer Type : " << t_engineer << " ]" << std::endl;
            std::cout << " Person First Name : " << Person::first_name << std::endl;
        }

        // Setters
        void set_t_engineer(std::string fn){
            t_engineer = fn;
        }

    // private :
    protected :
        std::string t_engineer{"MyE"};
};

// HOW TO SET UP A "COPY" CONSTRUCTOR.
/*
Engineer(const Engineer& source)
    : Person(source), t_engineer{source.t_engineer}
{
    std::cout <<  "Copy construtor Called... " << std::endl;
}
*/

#endif