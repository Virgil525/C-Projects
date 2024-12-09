#include <iostream>
#include <string>
#include <vector>
#include <functional>

namespace apple { namespace functions {
    void Print(const char* str){
        std::cout << str << std::endl;
    }
}
}

namespace DoSomething{
    void PrintInt(int i){
        std::cout << i << std::endl;
    }

    void DoSomething(std::vector<int>& ints, const std::function<void(int& i)>& func){
        for (int elem : ints){
            func(elem);
        }
    }
}
int main(){
    std::vector<int> vec1 = {1,2,3,4,5};
    auto x = [&](int&){ std::cout << "xxxx";};
    DoSomething::DoSomething(vec1, DoSomething::PrintInt);
    DoSomething::DoSomething(vec1, x);

    namespace f = apple::functions;
    f::Print("ooooo");

    return 0;
}