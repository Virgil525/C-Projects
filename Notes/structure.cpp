#include <iostream>

struct student{
    std::string name;
    double gpa;
    bool enrolled = true;
};
typedef struct student Student;
struct cars{
    std::string model;
    int year;
    std::string color;
};
typedef struct cars Cars;

void printCar1(Cars &car);
void printCar2(Cars *car);

/// struct is pass by value!

int main(){
    Student a;
    a.name = "Spongebob";
    a.gpa = 3.2;
    a.enrolled = false;

    std::cout << a.name <<'\n';
    std::cout << a.enrolled <<'\n';
    std::cout << a.gpa <<'\n';

    Cars car1;
    Cars car2;

    car1.model = "Ghost";
    car1.year = 2022;
    car1.color = "black";

    car2.model = "Wraith";
    car2.year = 2020;
    car2.color = "white";   

    printCar1(car1);
    printCar2(&car2);
    std::cout << car1.color;
    
    return 0;
}

void printCar1(Cars &car){
    std::cout << car.model << '\n';
    std::cout << car.year << '\n';
    std::cout << car.color << '\n';
    car.color = "white";
}
void printCar2(Cars *car){
    std::cout << car->model << '\n';
    std::cout << car->year << '\n';
    std::cout << car->color << '\n';
}
