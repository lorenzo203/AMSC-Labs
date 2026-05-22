#include<vector>
#include<iostream>
#include<memory>
#include"shape.h"

int main(){
    std::vector<std::shared_ptr<Shape>> shapes_vector;
    //std::shared_ptd... use make_shared instead
    shapes_vector.push_back(std::make_shared<Circle>(1.0));
    shapes_vector.push_back(std::make_shared<Rectangle>(3.0,1.0));

    for (const auto & s : shapes_vector) //creates a constant reference to the type in shapes_vector and iterate on that
//remove const in case there is no need to modify
        std::cout << s-> getArea() << ",   " << s -> getName() << std::endl;
    return 0;
}
