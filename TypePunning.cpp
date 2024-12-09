#include <iostream>

struct Entity{
    int x, y;
};

int main(){
    int a = 50;
    double b = a;
    Entity e = {1,2};

    // Please dont code like this :D
    // e.x
    int* x = (int*)&e;
    // e.y
    int y = *(int*)((char*)&e + 4);

    std::cout<< "x: " << *x << " y: " << y;

    return 0;
}