#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person{

    friend std::ostream& operator<<(std::ostream& out, const Person& person){
        out << "Person [" << person.first_name << " " << person.last_name << "]";
        return out;
    };

    public :
        Person() = default;
        Person(std::string& name_param, std::string& last_name_param)
            : first_name(name_param), last_name(last_name_param)
            {}
        ~Person() = default;

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

#endif