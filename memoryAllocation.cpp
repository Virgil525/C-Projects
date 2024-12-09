#include <iostream>
#include <string>
#include <memory>

struct Vec2 {
    float x, y, z;
    Vec2 () : x(10.0f), y(9.65f), z(12.44f)  { }
    void Print(){
        std::cout << x << ", " << y << ", " << z << std::endl;
    }
};

int main(){
    int value = 5;
    int array[5] = { 1, 2, 3, 4 ,5 };
    Vec2 vector;

    int* hValue = new int;
    *hValue = 5;
    int* hArray = new int[5];
    hArray[0] = 4;
    hArray[1] = 4;
    hArray[2] = 4;
    hArray[3] = 4;
    hArray[4] = 4;
    Vec2* hVec2 = new Vec2();

    std::unique_ptr psVec2 = std::make_unique<Vec2>();
    std::shared_ptr psVec2S = std::make_shared<Vec2>();
    psVec2S->Print();
    
    delete hValue;
    delete[] hArray;
    delete hVec2;

    return 0;
}