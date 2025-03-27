#ifndef CIVILENG_H
#define CIVILENG_H

#include <string>
#include <iostream>
#include "engineer.h"


class Civileng : public Engineer{

    // using Person::Person;  // Inheriting Full Constructor.

    // friend std::ostream& operator<<(std::ostream& out, const Engineer& engineer){
    //     out << "Person [" << engineer.first_name << " " << engineer.last_name << "]";
    //     return out;
    // };

    public :
        
        Civileng(){
            std::cout << "Default construtor called for CivilEngineer Called... " << std::endl;
        };

        Civileng(std::string_view name_param, std::string_view last_name_param, std::string_view engin_param, std::string_view speciality_param)
            : Engineer(name_param, last_name_param, engin_param), civil_engineer(speciality_param)
            {
                std::cout << "Custom construtor called for CivilEngineer Called... " << std::endl;
        };
        
        // Inheriting COPYING an all ready initializer
        Civileng(const Civileng& source)
            : Engineer(source), civil_engineer{source.civil_engineer}
            {
                std::cout <<  "Copy construtor Called... " << std::endl;
        }
        
        
        ~Civileng(){
            std::cout << "Destrutor called for CivilEngineer Called... " << std::endl;
        };

        // Getters
        std::string get_civil_engineer() const { return civil_engineer;}

        void civil_engineer_info(){
            std::cout << " Engineer Information  [ Full Names : " << first_name << " " << last_name << ",  Engineer Type : " << t_engineer << ",  Civil Engineer Type : " << civil_engineer << " ]"<< std::endl;
        }

        // Setters
        void set_civil_engineer(std::string fn){
            civil_engineer = fn;
        }

    // private :
    protected :
        std::string civil_engineer{"sterious"};
};

#endif