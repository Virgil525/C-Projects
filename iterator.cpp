#include <iostream>
#include <vector>
#include <unordered_map>

int main(){
    std::vector<int> values = {1,2,3,4,5};
    /*
    for (int elem : values){
        std::cout << elem << std::endl;
    }

    for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++){
        std::cout << *it << std::endl;
    }
    */
    std::unordered_map<std::string, int> map;
    map["pp"] = 5;
    map["hh"] = 6;

    using ScoreMap = std::unordered_map<std::string, int>;
    for(ScoreMap::const_iterator it = map.begin(); it != map.end(); it++){
        auto& key = it->first;
        auto& value = it->second;
        std::cout << key << " = " << value << std::endl;
    }

    for( auto kv : map ){
        std::cout << kv.first << " = " << kv.second << std::endl;
    }

    // C++ 17 structure binding
    for( auto [key, value] : map ){
        std::cout << key << " = " << value << std::endl;
    }

}