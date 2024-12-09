#include <iostream>
#include <string>
#include <memory>

// USE SMART POINTERS ALL THE TIME IF POSSIBLE, THEY AUTOMATE MEMORY MANAGEMENT

// smart pointers automate the process of new -> delete
// Scoped ptrs are one way to do the automation, they are also called unique pointers
// Unique ptrs cannot be copied because when the ptr goes out of scope and dies, it will free
// the memory which is also pointed to by the copy, whcih will not be pointing to freed memory

class Entity {
    public:
        Entity(){
            std::cout << "Created! " << std:: endl;
        }  
        ~Entity(){
            std::cout << "Destoryed! " << std:: endl;
        }
        void PrintEntity(){
            std::cout << "Printed! " << std::endl;
        }
};

// Unique ptrs are useful but they cannot be copies, if you need to share the address
// of the object or share the ptr, you run into troubles.
void scope1_Unique_ptr(){
    // unique ptr constructors are explicit, so you cannot do something like entity = new Entity();
    std::unique_ptr<Entity> entity(new Entity());
    // The prefered way to make unique ptr: this is slightly safer and compilers are less likely to
    // throw exceptions
    std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();

    // no copy!
    // std::unique_ptr<Entity> e = entity2;
    entity->PrintEntity();

    std::cout << "End of scope1" << std::endl;
}

// Shared pointer & reference counting
// The object is destoryed when all the references to it are dead
void scope2_Shared_ptr(){
    // This is how to make a shared pointers, again, dont use new here
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
    // this works for shared pointer;
    std::shared_ptr<Entity> e0 = sharedEntity;
    // The underlying Entity in this case will be deleted when sharedEntity and e0 go out of scope;

    // weak pointer, this does not increase the reference count for the shared pointer
    // so it gets destroyed when all other references are dead
    // This won't keep the object alive but still you can check if its alive and do stuff
    std::weak_ptr<Entity> weakEntity = sharedEntity;
}

int main(){
    scope1_Unique_ptr();
    scope2_Shared_ptr();
    std::cout << "Out of scope1" << std::endl;
    return 0;
}
