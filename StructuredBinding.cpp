#include<iostream>
#include<tuple>

struct Person{
    std::string name;
    int age;
};


std::tuple<std::string, int> CreatePerson(){
    return {"pp",24};
}

Person CreatePersonByStruct(){
    Person p = {"pp", 24};
    return p;
}

int main(){
    // old ways to return multiple values
    std::tuple<std::string, int> person = CreatePerson();
    std::string& name = std::get<0>(person);
    int age = std::get<1>(person);

    std::string name2;
    int age2;
    std::tie(name2,age2) = CreatePerson();

    Person p = CreatePersonByStruct(); 

    // structured binding in c++ 17
    auto[name3,age3] = CreatePerson();
    std::cout << name3 << age3;

    
    auto x = []() { return std::pair<std::string, std::string>("pp", "ppp"); };

    auto [a, b] = x();
        
    return 0;
}