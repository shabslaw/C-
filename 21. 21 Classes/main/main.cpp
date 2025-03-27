#include <iostream>


// CLASSES
const double PI{3.1415926535897932384626433832795};
        
class Cylinder{
    public :
        double base_radious{};
        double height{};

    public :
        double volume(){
            return PI * base_radious * base_radious * height;
        }
};


// CONSTRACTOR
class CCylinder{
    // behaviours 
    public :
        CCylinder(){
            base_radious = 2.0;
            height = 7.0;
        };
        
        CCylinder(double radious_param, double height_param){
            base_radious = radious_param;
            height = height_param;
        };
        
        double volume(){
            return PI * base_radious * base_radious * height;
        };


    // Decleared Initialied
    private :
        double base_radious{};
        double height{};
        
};



// DEFAULT CONSTRACTORS
class CCCylinder{
    // Decleared Initialied
    private :
        double base_radious{1};
        double height{1};
        

    // behaviours 
    public :
        CCCylinder() = default;
        
        CCCylinder(double radious_param, double height_param){
            base_radious = radious_param;
            height = height_param;
        };
        
        double volume(){
            return PI * base_radious * base_radious * height;
        };

};



// Objects
int main(){


    Cylinder cylinder1;

    std::cout << "base radious : " << cylinder1.base_radious << ", Height : " << cylinder1.height << std::endl;
    std::cout << std::endl;
    
    cylinder1.base_radious = 32;
    cylinder1.height = 96;
    
    std::cout << "base radious : " << cylinder1.base_radious << ", Height : " << cylinder1.height << std::endl;
    std::cout << "Full cylinder : " << cylinder1.volume() << std::endl;
    std::cout << std::endl;



    CCylinder ccylinder1;
    CCylinder ccylinder2(5, 17);

    
    std::cout << "Volume CC : " << ccylinder2.volume() << std::endl;
    std::cout << std::endl;

    CCCylinder cccylinder1;

    
    std::cout << "Volume CCC : " << cccylinder1.volume() << std::endl;
    std::cout << std::endl;

    
    return 0;
}
 