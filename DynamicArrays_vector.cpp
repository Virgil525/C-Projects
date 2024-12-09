#include <iostream>
#include <vector>
#include <string>

struct Vertex{
    float x,y,z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z){}
    Vertex(const Vertex& v) : x(v.x), y(v.y), z(v.z) { std::cout << "copied\n"; }
};

std::ostream& operator <<(std::ostream& stream, Vertex v){
    stream << v.x << ", " << v.y << ", " << v.z << std::endl;
    return stream;
}

// pass by reference to avoid copying!
void Function(const std::vector<Vertex>& vertices);

int main(){
    std::vector<Vertex> vList;

    // Optimization 1
    // This will avoid resizing since 2 slots are reserved
    // So copy constructors will not be called for resizing the vector
    vList.reserve(2);
    // Optimization 2
    // Use emplace_back instead of push_back to have the objects
    // be constructed in place in the actual vector memory
    // so no constructing in main stack and copy to memory
    vList.emplace_back(1,2,3);
    vList.emplace_back(4,5,6);
    //vList.push_back(Vertex(1,2,3));
    //vList.push_back(Vertex(4,5,6));

    for(int i = 0; i < vList.size(); i++){
        std::cout << vList[i];
    }

    vList.erase(vList.begin() + 1);

    // use reference here to avoid copying the objects
    for(const Vertex& v : vList){
        std::cout << v;
    }

    vList.clear();

    // use reference here to avoid copying the objects
    for(const Vertex& v : vList){
        std::cout << v;
    }

    return 0;
}