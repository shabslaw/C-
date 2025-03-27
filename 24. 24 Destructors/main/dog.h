#include <iostream>
#include <string_view>

class Dog{
    private :
        std::string dog_name;
        std::string dog_breed;
        int * dog_age{};

    public :
        Dog();

        Dog(std::string_view name_param, std::string_view breed_param, int age_param);

        ~Dog();

        void barck();



        /*
        //  ****   CHAINED CALLS WITH POINTERS :


        Dog* set_name(const std::string& dog_name){
            // dog_name = dog_name; ?? Error
            this->dog_name = dog_name;
            return this;
        }
        
        Dog* set_dog_breed(const std::string& breed){
            this->dog_breed = breed;
            return this;  // for use in chained calls
        }
        
        Dog* set_dog_age(int age){
            if(this->dog_age){
                *(this->dog_age) = age;
            }
            return this;
        }

        
        //  ****  CHAINED CALLS WITH REFERENCES  :


        Dog& set_name(const std::string& dog_name){
            // dog_name = dog_name; ?? Error
            this->dog_name = dog_name;
            return *this;
        }
        
        Dog& set_dog_breed(const std::string& breed){
            this->dog_breed = breed;
            return *this;  // for use in chained calls
        }
        
        Dog& set_dog_age(int age){
            if(this->dog_age){
                *(this->dog_age) = age;
            }
            return *this;
        }
        */
};