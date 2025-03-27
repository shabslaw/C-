#ifndef CYLINDER_H     // Cylinder Guide.
#define CYLINDER_H

#include "costains.h"


class Cylinder{
    private :
        double base_radious {1.0};
        double height {1.0};


    public :
        Cylinder() = default;

        Cylinder(double base_param, double height_param);

        // Getter
        double get_base_radious();

        double get_height();

        double volume();

        // Setter
        void set_base_radious(double param);

        void set_height(double param);

};


#endif