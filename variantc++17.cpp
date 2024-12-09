#include <iostream>
#include <variant>

enum class ErrorCode{
    None = 0, NotFound = 1, Present = 2
};

std::variant<std::string, int> ReadFileAsString(){
    // instead of using optional you can use variant and maybe a enum
    // class to return the satus of the actually retrieval;

}

int main(){
    // variant actually creates a struct or class for you that stores the data inside
    // So not like union which will take up the memeory space of the larger type
    // variant will take up the memory space of the sum of the types
    // variants are more type safe so you should use them over union unless doing ultimate
    // optimization
    std::variant<std::string, int> data;
    data = "pp";
    data = 2;

    // in this case, returns 1, for int as the active type
    data.index();

    // this retuns a ptr, if not the type sepcified, will return nullptr 
    if(auto* value = std::get_if<std::string>(&data))
    {
        std::string& v = *value;
    }


    std::cout << std::get<int>(data) << std::endl;

    return 0;
}