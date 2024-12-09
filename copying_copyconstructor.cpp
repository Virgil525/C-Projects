#include <iostream>
#include <string>
#include <cstring>

// AVOID UNNECESSARY COPYING TO AVOID RESOURCE WASTE
// ALWAYS PASS YOUR OBJECT BY const reference

struct Vector2 {
    float x, y;
};

class String {
    private:
        char* m_Buffer;
        unsigned int m_Size;
    public:
        String(const char* string){
            m_Size = strlen(string);
            // plus one for the null terminator;
            // can also use strcpy() which includes the null termination character;
            m_Buffer = new char[m_Size + 1];
            // This is the same as making the copies using a for loop and populate the buffer
            // memcpy takes the memory destination first, then the origin and the length
            memcpy(m_Buffer, string, m_Size);
            // add Null terminator;
            m_Buffer[m_Size] = 0;
        }

        // Copy constructor signiture
        String(const String& other) 
        : m_Size(other.m_Size){
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
        }

       // IF YOU DONT WANT TO ALLOW COPYING OF THE CLASS, YOU CAN SET IT TO EQUAL delete
       // This is exactly How unique pointers does that
       //String(const String& other) = delete;

        char* get_Buffer(){
            return m_Buffer;
        }
        char& operator[](unsigned int i){
            return m_Buffer[i];
        }
        friend std::ostream& operator << (std::ostream& stream, const String& string);
        ~String(){
            delete[] m_Buffer;
        }
};

// pass by reference here is because we dont want to make extra copies of 
// strings when calling the PrintString() function
void PrintString(const String& string){
    std::cout << string << std::endl;
}

std::ostream& operator << (std::ostream& stream, const String& string) {
    stream << string.m_Buffer << std::endl;
    return stream;
}

// When you use the assignment operator, you are always making copies
// You are essentially calling the copy constructor

int main(){
    // This creates a copy of a
    int a = 2;
    int b = a;

    // Same thing when its done to a class/struct
    Vector2 vec = {1,2};
    Vector2 vec2 = vec;

    // Copying pointer does not copy the underlying class, they all point to the same memory
    // address
    Vector2* vecP = new Vector2();
    Vector2* vecPc = vecP;
    delete vecP, vecPc;

    // Home made strings copying
    // Make the assignement operator to do a deep copy instead of a shallow copy
    // where the new object's m_Buffer has its own memory address instead of sharing with
    // the one it copied from;
    // This is achieved easily by a COPY CONSTRUCTOR!
    String str = "Moloch";
    String str2 = str;
    str2[3] = 'a';
    std::cout << str << std::endl;
    std::cout << str2 << std::endl;

    return 0;
}