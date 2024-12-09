#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>


// lambda reference page: https://en.cppreference.com/w/cpp/language/lambda

void forEach(const std::vector<int>& values, const std::function<void(int)>& func){
    for(int val : values){
        func(val);
    }
}

int main(){

    std::vector<int> values = {1,2,3,4,5};
    auto lambda = [](int val){ std::cout << "Value is: " << val << std::endl; };

    int a = 6;
    auto lambda2 = [a](int val){ std::cout << "Value is: " << a << std::endl; };
    auto lambda3 = [=](int val){ std::cout << "Value is: " << a << std::endl; };
    auto lambda4 = [&](int val){ std::cout << "Value is: " << a << std::endl; };
    auto lambda5 = [a](int val) mutable { std::cout << "Value is: " << a << std::endl; };
    forEach(values, lambda);
    forEach(values, lambda2);

    auto it = std::find_if(values.begin(),values.end(), [](int value){ return value > 3; });
    std::cout << *it << std::endl;

    return 0;
}