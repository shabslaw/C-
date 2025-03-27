#ifndef OVAL_H
#define OVAL_H

#include <iostream>
#include <string>
#include "shape.h"

class Oval : public Shape {
    private :
        double m_x_radious{0.0};
        double m_y_radious{0.0};

    public :
        Oval() = default;
        
        Oval(double x_radious, double y_radious ,const std::string& description){
            m_x_radious = x_radious;
            m_y_radious = y_radious;
            m_description = description;
        }

        virtual ~Oval() = default;


        // Getter
        double get_x_radious() const{
            return m_x_radious;
        }

        /*
        // Static Binding for Polymorphism
        void draw() const{
            std::cout << "Oval::Draw() Called. Drawing " << m_description <<", with X_radious " << m_x_radious <<", and Y_radious : " << m_y_radious << std::endl;
        }
        */

        // Dynamic Binding for Polymorphism
        virtual void draw() const override{
            std::cout << "Oval::Draw() Called. Drawing " << m_description <<", with X_radious " << m_x_radious <<", and Y_radious : " << m_y_radious << std::endl;
        }

};


#endif