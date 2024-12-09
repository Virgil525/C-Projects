#include <iostream>
#include <string>

typedef std::string String;

class Entity {
    private:
        String m_Name;
        int m_Age;
    public:
        Entity() 
        : m_Name("Unknown"), m_Age(-1) {}
        Entity(const String& name)
        : m_Name(name), m_Age(-1) {}
        Entity(const int age)
        : m_Name("Unknown"), m_Age(age) {}
        explicit Entity(const String& name, int age)
        : m_Name(name), m_Age(age) {}

        const String& GetName() const {
            return m_Name;
        }
        const int GetAge() const {
            return m_Age;
        }
};

void PrintEntity(const Entity& entity){
    std::cout << entity.GetName() << "Age: " << entity.GetAge() << std::endl;
}

int main(){

    // This works because it's doing an implicit conversion
    // where it looks for constructor taking the datatype and
    // constructe an object out of it.
    String name = "Moloch";
    Entity a = name;
    Entity b = 22;
    PrintEntity(a);

    // Same reason
    PrintEntity(23);
    // This doesn't work because its a char* and not a std::string
    // so two conversions are needed and it can only do 1 implicitly
    // PrintEntity("ppbobo");
    // to make it work:
    PrintEntity(String("ppbobo"));
    // or
    PrintEntity(Entity("ppbobo"));
    // As long as only one implicit conversion is done.

    // Explicit is used when you want your constructor to be explicitly called.
    // Differently, explicit constructors must be called to perform the constructions.
    // So it forces the coding format
    Entity c = ("hh",1);
    PrintEntity(c);
    // or cast it to the class
    PrintEntity((Entity)c);

    return 0;
}