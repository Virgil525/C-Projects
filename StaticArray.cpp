#include <iostream>
#include <array>

template<size_t N>
void PrintArray(const std::array<int, N>& array){
    for (const auto& element : array){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void PrintArray2(const std::array<int, 5>& array){
    for(int i = 0; i < array.size(); i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


int main(){
    std::array<int, 5> data = {1,2,3,4,5};
    data[0] = 2;
    data[4] = 1;
    
    PrintArray(data);
    PrintArray2(data);
    
    int dataOld[5];
    dataOld[0] = 0;

    return 0;
}