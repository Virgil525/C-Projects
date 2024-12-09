#include <iostream>
#include <string>

using String = std::string;

class Entity{
    private:
        String m_Name;
    public:
        Entity() 
        : m_Name("Unknown") {}
        Entity(const String& name) : m_Name(name) {}

        const String& GetName() const { return m_Name; }
};

Entity* CreateEntity(String name){
    Entity* entity = new Entity(name);
    return entity;
}

int main(){
    // Creating the object on the stack
    // Fastest way to instantiate object, use whenever can
    Entity entity("Moloch");
    std:: cout << entity.GetName() << std::endl;

    // Allocate on the heap
    // The reason you need to allocate the object on the heap can
    // be the object simply being too big
    // or the object goes out of the scope and gets destoryed on the stack
    Entity* entity1;
    // everything in the scope will be destoryed when the scope is over {}
    /*
    {
        Entity* entity1 = new Entity("Moloch");
    }
    */
    entity1 = CreateEntity("Moloch");
    std:: cout << entity1->GetName() << std::endl;

    // The new operator is the same as calling malloc() then call the constructor
    Entity* e = new Entity();
    // this only does the memory allocation and does not call the constructor:
    // You should avoid using malloc in C++
    /*
    Entity* e1 = (Entity*)malloc(sizeof(Entity));
    */

    // You have to use delete when using new
    // delete calls the c function free() which free the memory allocated by malloc()
    delete e;
    delete entity1;
    return 0;
}