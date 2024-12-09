#include <iostream>
#include <fstream>
#include <optional>
#include <sstream>

std::optional<std::string> ReadFileAsString(const std::string& filepath){
    std::ifstream stream(filepath);
    if (stream){
        //read file
        std::stringstream buffer;
        buffer << stream.rdbuf();

        std::string result = buffer.str();
        return result;
    }
    return {};
}

int main(){
    auto data = ReadFileAsString("data.txt");
    std::string value = data.value_or("no pp");
    if(data){
        std::cout << "File read successfully!\n";
    }
    else{
        std::cout << "File cannot be opened\n";
    }

    std::string& string = *data;
    std::string& string2 = data.value();
    std::cout << string << string2;
    return 0;
}