#include <iostream>
#include <cstring>

class String{
public:
    String() = default;
    String(const char* string){
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size + 1];
        memcpy(m_Data, string, m_Size);
        m_Data[m_Size] = '\0';
    }

    // move constructor
    String(String&& other) noexcept 
    : m_Data(other.m_Data), m_Size(other.m_Size){
        other.m_Data = nullptr;
        other.m_Size = 0;
        printf("Moved!\n");
    }

    // copy constructor
    String(const String& other){
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size + 1];
        memcpy(m_Data, other.m_Data, m_Size + 1);
    }

    // copy assignment operator
    String& operator = (const String& other){
        if(this != &other){
            delete[] m_Data;

            m_Size = other.m_Size;
            m_Data = new char[m_Size + 1];
            memcpy(m_Data, other.m_Data, m_Size + 1);
            printf("Copied!\n");
        }
        return *this;
    }

    // move assignment operator
    String& operator = (String&& other) noexcept{
        if(this != &other){
            delete[] m_Data;

            m_Data = other.m_Data;
            m_Size = other.m_Size;

            other.m_Data = nullptr;
            other.m_Size = 0;
            printf("Moved!\n");
        }
        return *this;
    }

    void Print(){
        for(uint32_t i = 0; i < m_Size; i++){
            printf("%c",m_Data[i]);
        }
        printf("\n");
    }

    ~String(){
        std::cout << "Destoryed!\n";
        delete[] m_Data;
    }
private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity{
public:
    Entity(const String& name) : m_Name(name){
        std::cout << "Entity created with String copy constructor";
    }
    Entity(String&& name) : m_Name(std::move(name)){
        std::cout << "Entity created with String move constructor";
    }
    void PrintName(){
        m_Name.Print();
    }

private:
    String m_Name;
};

int main(){
    String p("pp");
    Entity entity("ppp");
    Entity entity2(p);
    entity.PrintName();
    Entity entity3 = std::move(entity);
    entity3.PrintName();

    String s = "Hello";
    String s2 = s;
    String dest = std::move(s);
    s2 = std::move(dest);
    //String dest = (String&&)s;
    return 0;
}