#include <iostream>

class Entity {
    public:
        Entity(){
            std::cout << "Created" << std::endl;
        }
        ~Entity() {
            std::cout << "Destoryed" << std::endl;
        }

};


class ScopedPtr {
    private:
        Entity* m_Ptr;
    public:
        ScopedPtr(Entity* ptr) : m_Ptr(ptr){}
        ~ScopedPtr() { delete m_Ptr; }
};

int main(){

    ScopedPtr e = new Entity();
    
    return 0;
}