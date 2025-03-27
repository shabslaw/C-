#include "ellipse.h"


int Ellipse::m_count = 0;

Ellipse::Ellipse()
    : Ellipse(0.0,0.0, "NoDescription")
{};

Ellipse::Ellipse(double x_radious, double y_radious, std::string_view description)
    : Shape(description), m_x_radious{x_radious}, m_y_radious{y_radious}
{
    m_count++;
};

Ellipse::~Ellipse(){
    m_count--;
};
