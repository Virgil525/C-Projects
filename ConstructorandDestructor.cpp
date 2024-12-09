#include <iostream>

class Entity{
    float X,Y;
    public:

        void Move(float xa, float ya){
            X += xa;
            Y += ya;
        };

        Entity(){
            X = 0.0f;
            Y = 0.0f;
            std::cout << "Created Entity!" << std::endl;
        }

        Entity(float x, float y){
            X = x;
            Y = y;
            std::cout << "Created Entity with parameters!" << std::endl;
        }

        void Print(){
            std::cout << X << ", " << Y << std::endl;
        }

        ~Entity(){
            std::cout << "Destroyed Entity!" << std::endl;
        }

};

class Player : public Entity{
    public:
        const char* name;

};

int main(){
    Entity e(5.5f, 10.0f);
    Entity e2;
    e.Print();
    e2.Print();

    Player p1;
    

    return 0;
}