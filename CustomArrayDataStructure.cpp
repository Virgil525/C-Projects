#include <iostream>
#include <array>
#include <cstring>

template<typename T, size_t S>
class Array{
public:
    constexpr size_t size() const { return S; }

    T& operator[](size_t index){ 
            if(!(index < S)){
                __debugbreak();
            }
            return m_Data[index]; 
        }
    const T& operator[](size_t index) const { return m_Data[index]; }

    T* Data() {return m_Data;}
    const T* Data() const {return m_Data;}

private:
    T m_Data[S];
};

int main(){
    /*General static array stuff
    int array[5];

    int size = 5;
    int* heapArray = new int[size];
    delete[] heapArray;

    std::array<int, 5> templateArray;
    */

    Array<int, 5> data;
    static_assert(data.size()<10, "Size is too large!");
    for( size_t i = 0 ; i < data.size(); i++ ){
        data[i] = 0; 
    }
    for( size_t i = 0 ; i < data.size(); i++ ){
        std::cout << data[i] << std::endl;
    }
    memset(data.Data(), 0, data.size() * sizeof(int));
    for( size_t i = 0 ; i < data.size(); i++ ){
        std::cout << data[i] << std::endl;
    }
    
    Array<std::string, 2> strings;
    strings[0] = "pp";
    strings[1] = "bb";
    for( size_t i = 0 ; i < strings.size(); i++ ){
        std::cout << strings[i] << std::endl;
    }


    return 0;
}