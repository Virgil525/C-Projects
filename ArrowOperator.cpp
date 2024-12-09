#include <iostream>

class Entity {
    public:
        void Print() const {std::cout << "Hello world! " << std::endl;}
};

class ScopedPtr{
    private:
        Entity* m_Obj;
    public:
        explicit ScopedPtr(Entity* const entity)
        : m_Obj(entity) {}

        // overload the arrow to access the underlying object
        Entity* operator -> (){
            return m_Obj;
        }
        const Entity* operator -> () const{
            return m_Obj;
        }

        ~ScopedPtr()
        {
            delete m_Obj;
        }
};

struct Vector3
{
    float x, y, z;
};


int main(){
    Entity e;
    e.Print();

    // The default use of the arrow operator
    // dereference then access member
    // same as (*ptr).Print();
    Entity* ptr = &e;
    ptr->Print();

    // Overloading use case for arrow operator, smart pointer
    ScopedPtr ptr1(new Entity);
    ptr1->Print();

    // Another use of the arrow operator
    // get the offset of certain value in memory
    // int offset = (int)&((Vector3*)nullptr)->x;
    //std::cout << offset;
    return 0;
}