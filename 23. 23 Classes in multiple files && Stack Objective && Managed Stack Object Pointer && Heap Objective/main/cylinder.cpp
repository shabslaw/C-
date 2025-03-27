#include "cylinder.h"


Cylinder::Cylinder(double base_param, double height_param){
    base_radious = base_param;
    height = height_param;
};


// Getters

double Cylinder::get_base_radious(){
    return base_radious;
};

double Cylinder::get_height(){
    return height;
};

double Cylinder::volume(){
    return PI * base_radious * base_radious * height;
};


// Setters 

void Cylinder::set_base_radious(double param){
    base_radious = param;
};

void Cylinder::set_height(double param){
    height = param;
};