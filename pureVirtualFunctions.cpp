// Interface
#include <iostream>
#include <string>

typedef std::string String;

// pure virtual function or interface - forces subclass to implement it
// subclasses not having the function implemented will not be able to instantiate.
class Printable {
    public:
        virtual String getClassName() = 0;
};

class Entity : public Printable{
    public:
        virtual String GetName() {return "Entity";}
        String getClassName() override {return "Entity";}
};

class Player : public Entity {
    private:
        String m_Name;
    public:
        Player(const String& name) 
            : m_Name( name ){}
        
        String GetName() override { return m_Name; }
        String getClassName() override {return "Player";}
};

void PrintName(Entity* e){
    std::cout << e->GetName() << std::endl;
}

void Print(Printable* obj){
    std::cout << obj->getClassName() << std::endl;
}

int main(){
    Entity* e = new Entity();
    Print(e);
    Player* p = new Player("pp");
    Print(p);

    std::cin.get();
    return 0;
}