#include <iostream>
#include <cstring>
#include <string>


class Humans{
    private :
        std::string name {};
        std::string gender {};
        double age {};

    public :
        // Getter
        auto get_name(){
            return name;
        }

        auto get_gender(){
            return gender;
        }

        auto get_age(){
            return age;
        }
        
        const auto show(){
            std::cout << "Name : " << name << ", Gender : " << gender << ", Age : " << age << std::endl;
        }


        // Setter
        Humans() = default;

        Humans(std::string p_name, std::string p_gender, double p_age){
            name = p_name;
            gender = p_gender;
            age = p_age;
        }

};

int main(){
    std::cout << "Setters and Getters result" << std::endl;
    std::cout << std::endl;

    
    Humans person1("Tayo", "M", 23);
    std::cout << "Get Person Name : " << person1.get_name() << std::endl;
    std::cout << "Get Person Gender : " << person1.get_gender() << std::endl;
    
    std::cout << std::endl;

    // person1.show();

    return 0;
}
 