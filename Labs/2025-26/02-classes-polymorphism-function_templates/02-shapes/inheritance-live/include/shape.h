#ifndef SHAPES_H
#define SHAPES_H

#include <cmath>

class Shape 
{
    public: 
        Shape() = default;

        virtual ~Shape () = default;

        virtual double getArea() = 0;

        constexpr virtual const char *getName() = 0;
};

class Circle : public Shape
{
    private: 
        const double radius;
    public:
        Circle (const double);
        virtual ~Circle () override = default;
        double getArea() override {return (M_PI*radius*radius);}
        constexpr virtual const char *getName() override {return "Circle";}
};

class Rectangle : public Shape
{
    private:
        const double heigth;
        const double width;
    public:
        Rectangle (const double, const double);
        virtual ~Rectangle () override = default;
        double getArea() override {return (width*heigth);}
        constexpr virtual const char *getName() override {return "Rectangle";}
};

#endif
