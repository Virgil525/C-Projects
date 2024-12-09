#include <iostream>
#include <math.h>

class Animal{
    public:
        bool alive = true;
    void eat(){
        std::cout << "This animal is eating!\n";
    }
};

class Dog : public Animal{
    public:
        void bark(){
            std::cout << "Woof";
        }
};

class Cat : public Animal{
    public:
        void meow(){
            std::cout << "Meow";
        }
};

class Shape{
    public:
        double area;
        double volume;
};
class Cube : public Shape{
    public:
        double side;
    Cube(double side){
        this->side = side;
        this->area = side * side * 6;
        this->volume = pow(side, 3);
    }
};
class Sphere : public Shape{
    public:
        double radius;
    Sphere(double radius){
        this->radius = radius;
        this->area = 4* 3.141592653589793 * pow(radius,2);
        this->volume = (4/3.0)*3.141592653589793 * pow(radius,3);
    }
};

int main(){
    Dog dog;

    Cube cube1(10);
    std::cout<< "Area: "<< cube1.area << " cms " << '\n';
    std::cout<< "Volume: "<< cube1.volume << " cm^2s " << '\n';

    Sphere sphere1(5);
    std::cout<< "Area: "<< sphere1.area << " cms " << '\n';
    std::cout<< "Volume: "<< sphere1.volume << " cm^2s " << '\n';

    return 0;
}