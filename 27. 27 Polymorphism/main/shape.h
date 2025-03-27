#ifndef SHAPE_H
#define SHAPE_H

#include <string_view>
#include <string>

class Shape {
    protected :
        std::string m_description{""};

    public :
        Shape() = default;
        
        Shape(const std::string& description)
            : m_description{description}
        {}

        virtual ~Shape() = default;

        /*
        // Static Blinging for Polymorphism
        void draw(){
            std::cout << "Shape::Draw() Called. Drawing " << m_description << std::endl;
        }
        */

        // Dynamic Blinging for Polymorphism  ( "The compiler will blind the type of the pointer we are using to manage how Object" )
        virtual void draw() const{
            std::cout << "Shape::Draw() Called. Drawing " << m_description << std::endl;
        }

        
    };
    /*
    void draw_shape(Shape* shape_ptr){
        shape_ptr->draw();  //  Calls the right method for the right Object Passed in (Using Pointer here)
    }
    
    void draw_shape(const Shape& shape){
        shape.draw();  //  Calls the right method for the right Object Passed in (Using References here)
    }
    */


#endif