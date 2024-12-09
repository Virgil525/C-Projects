#include <iostream>
#include <string>

typedef std::string String;

/*
This is a sample of class initialization with constructors
*/
class Entity{
    private:
        String m_Name;
    public:
        Entity() {
            m_Name = "Unknown";
        }
        Entity(const String& name){
            m_Name = name;
        }
        const String& GetName() const { return m_Name; }
};

// This is initializing using a member initializer list
class Entity1{
    private:
        String m_Name;
        int m_Score;
    public:
    // list the variables in order! it will be initialized with respect to how
    // the class members are actually defined
        Entity1() 
        : m_Name("Unknown"), m_Score(0) {}

        Entity1(const String& name)
        : m_Name(name), m_Score(0){/* member classes initialzed here will acutally
        be initialized twice, but it won't happen when you are initializing it 
        in a member intializing list! so use the list when you can.
        */}
        const String& GetName() const { return m_Name; }
};

int main(){
    Entity e0;
    std::cout << e0.GetName() << std::endl;

    Entity e1("Moloch");
    std::cout << e1.GetName() << std::endl;

    return 0;
}