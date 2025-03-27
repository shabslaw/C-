#include <iostream>
#include <memory>

#include "shape.h"
#include "oval.h"
#include "circle.h"



// ***   POLYMORPHISM
// POLYMORPHISM  :  Managing derived objects in memory though base pointers or references and getting the right method called on the base pointer or reference.

// 1. Static Binding with POINTER :  The compiler just look at the pointer type to decide with draw() version to call. it sees Shape* and calls Shape::draw(). this is static binding in action!
// 1. Static Binding with REFERENCES : The compiler just looks at the refernce type to decide with draw() version to call. it sees Shape& and call Shape::draw(). This is static binding in action!


// 2. Dynamic Binding && Polymorphism is only going to work if it's method/member_funtion is set to Virtual.

void draw_shape(Shape* shape_ptr){
    shape_ptr->draw();  //  Calls the right method for the right Object Passed in (Using Pointer here)
};

void draw_shape_R(const Shape& shape){
    shape.draw();  //  Calls the right method for the right Object Passed in (Using Pointer here)
}


int main(){
    std::cout << "### Polymorphism" << std::endl;
    std::cout << std::endl;
    
    Shape shape1("shape1");
    Oval oval1(3.2, 9.4, "oval1");
    Circle circle1(40, "circle1");

    /*
    // STATIC BINDING with POINTER
    std::cout << std::endl;
    std::cout << "Calling methods through Pointer : Static Binding" << std::endl;
    std::cout << std::endl;


    Shape *shape_ptr = & shape1;
    shape_ptr->draw(); // We would wish for Shape::Draw() to be called

    shape_ptr = &oval1;
    shape_ptr->draw(); // We would wish for Oval::Draw() to be called

    shape_ptr = &circle1;
    shape_ptr->draw(); // We would wish for Circle::Draw() to be called

    
    // STATIC BINDING with REFERENCES
    std::cout << std::endl;
    std::cout << "Calling methods through reference : Static Binding" << std::endl;
    std::cout << std::endl;
    
    
    Shape& shape_ref = shape1;
    shape_ref.draw(); // We would wish for Shape::Draw() to be called
    
    Shape& shape_ref1 = oval1;
    shape_ref1.draw(); // We would wish for Oval::Draw() to be called
    
    Shape& shape_ref2 = circle1;
    shape_ref2.draw(); // We would wish for Circle::Draw() to be called
    
    
    // DRAWING SHAPES
    std::cout << std::endl;
    std::cout << "Calling DRAWING SHAPES : Static Binding POINTERS and REFERENCES" << std::endl;
    std::cout << std::endl;

    // pointer
    draw_shape(&shape1);
    draw_shape(&oval1);
    draw_shape(&circle1);

    std::cout << "*** ------------------------------------------------------- ***" << std::endl;
    
    // references
    draw_shape_R(shape1);
    draw_shape_R(oval1);
    draw_shape_R(circle1);
    





    //  POLYMORPHISM why?
    std::cout << std::endl;
    std::cout << "Shapes stored in collections" << std::endl;
    std::cout << std::endl;
    
    Circle circle_collection[]{circle1, Circle(2.4,"circle2"), Circle(2.1,"circle3"), Circle(2.5,"circle4"), Circle(3.5,"circle5")};
    Oval oval_collection[]{oval1, Oval(2.4,3.0,"circle2"), Oval(2.1,3.0,"circle3"), Oval(2.5,3.0,"circle4"), Oval(3.5,3.1,"circle5")};
    
    for(const auto& c : circle_collection){
        c.draw();
    }
    
    std::cout << "*** ------------------------------------------------------- ***" << std::endl;

    for(const auto& o : oval_collection){
        o.draw();
    }


    std::cout << std::endl;
    std::cout << "What we really want" << std::endl;
    std::cout << std::endl;

    Shape* shape_collection[]{&circle1, &oval1, &shape1};

    for(Shape* shape_ptr : shape_collection){
        shape_ptr->draw();
    }



    // SIZE OF STATIC Binding && DYNAMIC Binding
    std::cout << std::endl;
    std::cout << "SIZE OF STATIC Binding && DYNAMIC Binding" << std::endl;
    std::cout << std::endl;

    std::cout << "sizeof(Shape) :" << sizeof(Shape) << std::endl;  // Dynamic = 40, Static = 32
    std::cout << "sizeof(Oval) :" << sizeof(Oval) << std::endl;     //  Dynamic = 56, Static = 48
    std::cout << "sizeof(Circle) :" << sizeof(Circle) << std::endl;  //  Dynamic = 56, Static = 48
    
    // Slicing
    std::cout << std::endl;
    std::cout << "Slicing in C++" << std::endl;
    std::cout << std::endl;

    Shape shape_slic = circle1;
    Oval shape_slic1 = circle1;
    draw_shape(&shape_slic);
    draw_shape(&shape_slic1);
    
    
    // Slicing
    std::cout << std::endl;
    std::cout << "POLYMORPHIC Objects stored in Collections" << std::endl;
    std::cout << std::endl;
    
    Shape* shape_collection1[]{&circle1, &oval1, &shape1};   // Storing with Pointer work, Because it uses POLYMORPHISM to store the data inside the array.
    
    for(Shape* shape_ptr : shape_collection1){
        shape_ptr->draw();
    }
    
    std::cout << "*** -------------------------------------------- ***" << std::endl;
    
    std::shared_ptr<Shape> shape_collection2[]{std::make_shared<Circle>(30, "circle3"), std::make_shared<Oval>(2.2, 3.3, "oval3"), std::make_shared<Shape>("shape3")};   //  Storing with Smart Pointer work, because a SMART POINTER is a rapper on top of a regular POINTER in C++.
    
    for(auto& smart_ptr : shape_collection2){
        smart_ptr->draw();
    }
    
    
    // OVERRIDE
    std::cout << std::endl;
    std::cout << "OVERRIDE Specification" << std::endl;
    std::cout << std::endl;
    
    // Overloading Overriding and Hideing
    std::cout << std::endl;
    std::cout << "Overloading Overriding and Hideing" << std::endl;
    std::cout << std::endl;
    */

    
    // STATIC MEMBER
    std::cout << std::endl;
    std::cout << "STATIC Member" << std::endl;
    std::cout << std::endl;

    Shape* shape_collection[] {&shape1,&oval1,&circle1};
    
    for(Shape* c : shape_collection){
        c->draw();
    }
    
    
    


    std::cout << std::endl;
    std::cout << "Done!" << std::endl;
    return 0;
}
 