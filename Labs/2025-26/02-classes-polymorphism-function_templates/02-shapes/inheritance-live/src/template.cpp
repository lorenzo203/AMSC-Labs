#include<iostream>

struct Rectangle{
    double width;
    double heigth;
    Rectangle(double w, double h):width(w),heigth(h){}
    double area() const{return width*heigth;}
    void print() const{
        std::cout << "Rectangle area= " << area() << "\n";
    }
};

struct Square{
    double side;
    explicit Square(double s):side (s){}
    double area() const{return side*side;}
    void print() const{
        std::cout << "Square area = " << area() << "\n";
    }
};

template<typename Shape> 
void show(const Shape& s){
    s.print();
}

int main(){
    Square sq(3.0);
    Rectangle r(1.5,2.0);
    show(sq);
    show(r);
    return 0;
}