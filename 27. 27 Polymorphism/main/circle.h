#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include "oval.h"

class Circle : public Oval {
    public :
        Circle() = default;
        
        Circle(double radious, const std::string& description)
            : Oval(radious, radious, description)
        {
        }

        virtual ~Circle() = default;

        /*
        // Static Binding for Polymorphism
        void draw() const{
            std::cout << "Circle::Draw() Called. Drawing " << m_description <<", with radious : " << get_x_radious() << std::endl;
        }
        */

        // Dynamic Binding for Polymorphism
        virtual void draw() const override{
            std::cout << "Circle::Draw() Called. Drawing " << m_description <<", with radious : " << get_x_radious() << std::endl;
        }

};


#endif