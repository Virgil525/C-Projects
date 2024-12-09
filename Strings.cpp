#include <iostream>
#include <string>
#include <cstring>

typedef std::string String;

void PrintString(const String& string){
    std::cout << string << std::endl;
}
//String literals are stored in a read only section of the memory
//Thus editing the string content DECLARED WITH CONST CHAR POINTER
//is not allowed even you don't declare as a const
/*
For instance
char* name = "Something";
name[2] = 'y';
This is iLeagal!!!

If you want to modify the sting, you can make it into an array then the code above would work:
char name[] = "Something";
name[2] = 'y';
*/

int main(){
    String name = String("pp ") + "jojo";
    // check if something is contained in the string, std::string::npos is illegal position for a string
    bool contains = name.find("jo") != std::string::npos;   
    PrintString(name);
    std::cout << contains;

    // \0 is the null terminator in a const char array
    // strings are basically const char arrays
    const char name2[7] = "String";
    std::cout << strlen(name2) << std::endl;
    // the reason this 6 char long string requires allocating 7 char
    // is because the string need a null terminator at the end
    // its denoted by \0 in ASCII or you can use the numeric value 0 directly
    // However, the strlen() function will only return 3 in this case since
    // there is a null terminator in it.
    const char name3[8] = "Str\0ing";
    std::cout << strlen(name3) << std::endl;

    // char is a 1 byte type, however, there are other ones in C++
    // you can apeened u8 in front of the string to really enforce that
    const char* n0 = u8"Moloch";
    const char* n = "Moloch";
    // This is a wide character string
    // The capital L appended to the front of the string is required
    // wide character is 2byte per character type normally, but its compiler determined.
    const wchar_t* n1 = L"Moloch";
    // Some other types
    // char16 is a 2byte per character type
    const char16_t* n2 = u"Moloch";
    // char32 is a 4byte per character type
    const char32_t* n3 = U"Moloch";

    // String literals functions
    using namespace std::string_literals;
    String name4 = "String";
    // Normally if you want to append to the string, you can do += or
    // use a constructor like this 
    String name5 = String("String") + "jojo";
    // Since C++ 14, there is something in the string literals library that makes
    // this quite ez, the s at the end of the string is actually a function that
    // returns a standard string
    String name6 = "String"s + "jojo";

    // Another character you can prepend to the string is the upper case R
    // You also have to have the perentacies inside
    // the upper R means to ignore escape characters, very useful for multiline
    // strings or writing paragraphs
    const char* name7 = R"(Moloch
    is
    pp
    jojo)";
    // This is the same as
    const char* name8 = "Moloch\n"
        "is\n"
        "pp\n"
        "jojo";
    

    return 0;

}