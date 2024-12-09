#include <iostream>
#include <string>

typedef std::string String;

class Entity{
    public:
        virtual String GetName(){ return "Entity"; }
};

class Player : public Entity {
    private:
        String m_Name;
    public:
        Player(const String& name) 
            : m_Name( name ){}
        
        String GetName() override { return m_Name; }
};

void PrintName(Entity* e){
    std::cout << e->GetName() << std::endl;
}

int main(){
    Entity* e = new Entity();
    PrintName(e);
    std::cout << e->GetName() << std::endl;

    Player* p = new Player("pp");
    PrintName(p);
    std::cout << p->GetName() << std::endl;

    std::cin.get();
    return 0;
}