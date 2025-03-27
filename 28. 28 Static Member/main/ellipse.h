#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream>
#include <string>
#include "shape.h"


class Ellipse : public Shape {
    private :
        double m_x_radious{0};
        double m_y_radious{0};

    public :
        Ellipse();

        Ellipse(double x_radious, double y_radious, std::string_view description);

        virtual ~Ellipse();

        void draw() const{
            std::cout << "Shape::draw() called for " << m_description << std::endl;
        }

        virtual int get_count() const override{
            return m_count;
        }

        static int m_count;
};



#endif