#include <iostream>
#include <string>

void PrintEntity(Entity* e);
void PrintEntity2(const Entity& e);

class Entity{
    private:
        int x, y;
    public:
        Entity(int x, int y){
            this->x = x;
            this->y = y;
        }

        // this in a non const function is a class pointer
        int setX(){
            Entity* e = this;

            PrintEntity(this);
            PrintEntity2(*this);

            Entity& e = *this;
        }
        // this in a const function is a const class pointer
        int getX() const{
            const Entity* e = this;
            const Entity& e = *this;
        }
};

void PrintEntity(Entity* e){
    // print stuff
}
void PrintEntity2(const Entity& e){
    // print stuff
}

int main(){

    return 0;
}