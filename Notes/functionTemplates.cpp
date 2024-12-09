#include <iostream>

template <typename T, typename U>

auto max(T x, U y){
    return (x>y)? x:y ;
}

int main(){
    std::cout << max(2,1);
    std::cout << max(2.1 , 3.2);
    std::cout << max('1' , '2');
    std::cout << max(1 , 2.6);

    return 0;
}