#include <iostream>

// Dynamic Casting is specifically used in inheretance heiarchy 
// using dynamic casting on a class can be useful to check if a class is the class you think it is
// Dynamic casting incure a cost though so performance wise, if you want to write fast code, avoid it

class Entity{
    // dynmaic casting is only enabled if the object has a v table
    // can be achieved via makign a virtual function
    public:
        virtual void PrintName() {}
};

class Player : public Entity{
};

class Enemy : public Entity{
};

int main()
{
    Player* player = new Player();
    Entity* e = player;
    // this will result in error
    //Player* p = e;

    Entity* e1 = new Enemy();
    //This is dangerous
    Player* p1 = (Player*)e1;

    Player* p1 = dynamic_cast<Player*>(e);
}