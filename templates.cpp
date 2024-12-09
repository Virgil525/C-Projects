#include <iostream>
#include <string>

template<typename T, int N>
class Array{
    private:
        T m_Array[N];
    public:
        int getSize() const { return N; }
};


template <typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}


int main() {
    Print(5);
    Print("PpP");
    Print<int>(6.9f);

    Array<int, 5> array;
    std::cout << array.getSize() << std::endl;

    return 0;
}