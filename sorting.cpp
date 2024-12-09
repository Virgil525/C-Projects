#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <functional>

int main(){
    std::array<int, 5> arr = {5,3,1,2,4};
    std::vector<int> vec = {4,2,1,3,5};

    std::sort(arr.begin(), arr.end());
    std::sort(vec.begin(), vec.end());

    for(int i =0; i <5; i++){
        std::cout << "arr: " << arr[i] << ", vec: " << vec[i] << std::endl;
    }

    std::cout << "\n";
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    std::sort(vec.begin(), vec.end(), std::less<int>());

    for(int i =0; i <5; i++){
        std::cout << "arr: " << arr[i] << ", vec: " << vec[i] << std::endl;
    }

    std::cout << "\n";
    std::sort(arr.begin(), arr.end(), [](int a, int b){ return a > b; });
    std::sort(vec.begin(), vec.end(), [](int a, int b){ return a < b; });

    for(int i =0; i <5; i++){
        std::cout << "arr: " << arr[i] << ", vec: " << vec[i] << std::endl;
    }

    return 0;
}