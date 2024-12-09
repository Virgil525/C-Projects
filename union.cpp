#include <iostream>

struct vector2{
    float x,y;

};
struct vector4{
    // this is a 16 byte structure
    // and two ways to interprete the memory
    union{
        struct{
            float x,y,z,w;
        };
        struct{
            vector2 a,b;
        };
    };
};

void printVector2(vector2& vec){
    std::cout<< vec.x << ", " << vec.y << std::endl;
}

int main(){
    // union is a way to type punning
    // this gives two different ways to address the same memory
    union {
        float a;
        int b;
    };

    vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
    printVector2(vector.a);
    // this is the same as vector.b.x
    vector.z = 69.420f;
    printVector2(vector.b);

    return 0;
}