#include <iostream>

typedef std::string String;

class Human{
    public:
        String name = "TempName";
        String occupation = "TempJob";
        int age = 0;

        void eat(){
            std::cout << name <<" is eating\n";
        }
        void drink(){
            std::cout << name <<" is drinking\n";
        }
        void sleep(){
            std::cout << name <<" is sleeping\n";
        }
        void showAge(){
            std::cout << name <<"'s age is: " << age << std::endl;
        }

        Human(){}
        Human(String name, int age){
            this->name = name;
            this->age = age;
        }
        Human(String name, int age, String occupation){
            this->name = name;
            this->age = age;
            this->occupation = occupation;
        }
};

int main(){
    Human pp("pp",666);
    Human hh("hh",777, "queen");
    pp.occupation = "Lord Commander of HUAHUA empire";
    pp.drink();
    pp.showAge();

    hh.showAge();
    hh.drink();

    Human qq;
    qq.showAge();
    

    return 0;
}