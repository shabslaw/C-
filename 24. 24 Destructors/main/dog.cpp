#include <iostream>
#include <string_view>
#include "dog.h"


Dog::Dog(){
    dog_name = "none";
    dog_breed = "none";
    dog_age = new int;  // Dynamic Memory allocation  = Heap Memory
    *dog_age = {0};

    std::cout << "Dog Name : " << dog_name << ", Constructed at : " << this << std::endl;
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param){
    dog_name = name_param;
    dog_breed = breed_param;
    dog_age = new int;
    *dog_age = age_param;

    std::cout << "Dog Name : " << dog_name << ", Constructed at : " << this << std::endl;

};

Dog::~Dog(){
    delete dog_age;
    std::cout << "Dog Destructor called for "  << dog_name << ", Constructed at : " << this << std::endl;
}

void Dog::barck(){
    std::cout << "Dog Name : " << dog_name << ", Dog Breed : " << dog_breed << ", Dog Name : " << *dog_age << "Years old." << std::endl;
};