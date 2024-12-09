#include <iostream>
#include <string>

// ALWAYS MARK YOUR FUNCTION AS CONST IF THEY ARE NOT SUPPOSED TO MODIFIY THE CLASS
class Entity{
    private:
        int m_X, m_Y;
        // mutable makes this variable able to be changed in a const function like getX() below
        // useful for debugging when you need some const function to modify certain variables in the class
        mutable int var;
    public:
    // putting const after a method name only works in a class
    // This const means the method will not be able to modify the actual class
    // This makes sense to be used in a getter
    // If only have this version, it won't be able to be used by the PrintEntity function
    // which takes a const reference
        int GetX(){
            return m_X;
        }
        int GetX() const{
            var = 10;
            return m_X;
        }
        void SetX(int x){
            m_X = x;
        }
};

// if m_X is a pointer, you can make getter const by following the pointer const below
// example:
class Entity2{
    private:
    // if you want to declare pointers in one line, you need to stick a * pointer operator
    // next to each pointer
        int* m_X, *m_Y;
    public:
        const int* const GetX() const{
            return m_X;
        }
};
// 
void PrintEntity(const Entity& e){
    std::cout << e.GetX() << std::endl;
}

int main(){

    const int MAX_NUMBER = 999;

    // the const here means you cannot change the content of the pointer
    const int* a = new int;

    // However, you can still change what this pointer points to
    // casting the address to int* here is for the purpose of breaking the const 
    // restrictions
    a = (int*)&MAX_NUMBER;
    // This will not work
    //*a = 2;

    // const can also be put behind the pointer type
    // by doing this, you can change the contents of the pointer,
    // but you cannot change what it points to.
    int* const b = new int;
    *b = 2;
    // this will not work
    //b = (int*)&MAX_NUMBER;

    // the pointer sign * is the key here to determine where the const lies.
    // for instance,
    int const* c = new int;
    // is the same as
    const int* c = new int;

    // To actually make the pointer constent so you cannot reassign it
    // you have to put the const after the * 
    int* const c = new int;

    // Of course you can do const twice to make it not reassignable and
    // the content cannot be cahnged
    const int* const d = new int;
    
    return 0;
}

/*
For people having trouble remembering the order in which const keyword is to be used, here's a quick tip.
You have to read it backward, like the compiler does. For instance : 

-const int * A; ==> "A is a pointer to an int that is constant."
(or, depending on how you prefer to write it)
int const* A; ==> "A is a pointer to a const int"
but both are the same as explained in the video.

-int * const A; ==> "A is a const pointer to an int."
-const int* const A; ==> "A is a const pointer to an int that is constant".

EDIT : 
As mentionned by simo simo in the comments bellow, const int * A does not mean that A actually points to a const variable. It just means that the compiler will not allow you to modify the pointed value through A.

for instance : 
int val = 10;
int const * a = &val;
*a = 30; //this will NOT compile, you're not allowed to modify "val" through "a".
val = 30; //this will compile. 

Same with : 

int val = 10;
int val2 = 30;
const int * const A = &val; 

A = &val2; //will NOT compile : you can't modify what A points to.
*A = 30; //will NOT compile : you can't modify val through A

val = 30; //this will compile, val is not constant
*/