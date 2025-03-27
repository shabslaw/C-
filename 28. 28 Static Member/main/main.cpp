#include <iostream>

#include "shape.h"
#include "ellipse.h"


int main(){
    /*
        std::cout << std::endl;
        std::cout << "STATIC MEMBER" << std::endl;
        std::cout << std::endl;

        Shape shape1("shape1");
        std::cout << "Static count : " << Shape::m_count << std::endl;

        Shape shape2("shape2");
        std::cout << "Static count : " << Shape::m_count << std::endl;

        Shape shape3;
        std::cout << "Static count : " << Shape::m_count << std::endl;


        Ellipse ellipse1(2.2, 2.3, "ellipse1");
        std::cout << "Static count : " << Shape::m_count << std::endl;
        std::cout << "Ellipse count : " << Ellipse::m_count << std::endl;
        
        
        std::cout << " _____________________________________________________ " << std::endl;
        Shape* shapes[]{&shape1,&ellipse1};
        
        for(Shape* s : shapes){
            std::cout << s->get_count() << std::endl;
        }
    */




    // FINAL : is use to stop override downward.

    /*
        Intresting Facts:
        - Final Lone Class : you won't be able to inhereat the Class
        - Introduced useless Virtual method : you can still access your virtual methods
        - Can override in a final class
        - Introduce virtual final methods
        - 
    

    
        void run() const override final{
            std::cout << " The restricts on how people override in derived classes " << std::endl;
        }
        // OR

        class cat final : public Feline{
            std::cout << " The Cat restricts further sub-classing downstream to stop override " << std::endl;
        }
    */





    // Virtual Function and Default arguments : they are best avoided.

    /*
        - Default arguments are handled at complie time
        - Virtual function are called at run time with polymorphism
        - If you use default arguments with virtual functions, you might get weird(erroneous), result with Polymorphism.
    */



    // Virtual Destructors  :  all you need for the polymorphism to destroy its derived classes why destroing its ~ HEAP Object ~ is to add "virtual" to every destructor method


    /*
    // Dynamic Cast :  is only going to work with POLYMORPHISM
        // basic pointer initizing.
        Shape* new_shape_ptr = new Ellipse(2.1, 3.2, "ellipse1");  // heap memory

        // Casting pointer initizing.
        Ellipse* ellipse_ptr = dynamic_cast<Ellipse*>(new_shape_ptr);
        
        if(ellipse_ptr){
            ellipse_ptr->draw();
        } else {
            std::cout << " Couldn't cast to Ellipse Pointer, Sorry! " << std::endl;
        }
        std::cout << "-----------------------------------------------" << std::endl;
        // basic references initizing.
        Ellipse ellipse2(2.1, 3.2, "ellipse1");  // heap memory
        Shape &shape_ref = ellipse2;

        // Casting references initizing.
        Ellipse &ellipse_ref{dynamic_cast<Ellipse&>(shape_ref)};
        ellipse_ref.draw();
        
        // Turning the references into pointer, then doing the casting.
        Ellipse* ellipse_ref1{dynamic_cast<Ellipse*>(&shape_ref)};
        if(ellipse_ref1){
            ellipse_ref1->draw();
        } else {
            std::cout << " Couldn't cast to Ellipse Pointer From Reference, Sorry! " << std::endl;
        }
    */





    // ###  Pure virtual Functions and abstract classes : if a class as at list one pure virtual function, its now an abstract class.

    /*
        // Pure virtual functions..
        virtual double perimeter() const = 0;  // inside the Base Class
        virtual double surface() const = 0;

        virtual double surface() const override {
            return (m_width * m_height);       //  Triangle Derived class 
        };

        Shape* shape = new Shape();  // Error : SHape is an abstract class, can't create and Object of it.
        
        const Shape* shape_triangle1 = new Triangle(1.2, 2.1, "shape_triangle1");
        double triangle1 = shape_triangle1->surface();
        
        std::cout << "Surface of the Triangle is : " << triangle1 << std::endl;

        
        const Shape* shape_circle1 = new Circle(1.2, "shape_circle1");
        double circle1 = shape_circle1->surface();
        
        std::cout << "Surface of the Circle is : " << triangle1 << std::endl;
    */





    // Abstract Classes as Interface
    /*
        - An abstract class with only pure virtual functions and no member variable can be used to model what is called an interface in Object Oriented Programming.
        - An interface is a specification of something that will be fully implemented ina derived class, but the specification itself resides in the abstract class.

        friend std::ostream& operator<<(std::ostream& out, const StreamInsertTable& operand){
            operand.strem_insert(out);
        };                                                           // inside Base class that as Pure virtual function.

        virtual double stream_insert(std::ostream& out) const = 0;  // inside the Base Class

        // Derived class 
        virtual double surface(std::ostream& out) const override {
            out >> m_width * m_height ;       //  Triangle Derived class 
        };

    */


    // TEMPLATE Specializiation :
    /*
        template <typename T> T maximum(T a, T b){
            return (a < b) ? a : b;
        };   // To work with Int , double

        // OR 
        template <>
        const char* maximum<const char*>(const char* a, const char* b);  // To work with C-String , char
    */


    return 0;
};

 