#include <iostream>
#include <string>

typedef std::string String;


class Entity{
    private:
        String m_Name;
        // using mutable here to make const functions capable of changing this variable.
        mutable int m_DebugCount = 0;
    public:
        const String& GetName() const {
            m_DebugCount++;
            return m_Name;
        }
};

int main(){
    int x= 8;
    // This is a lambda
    // = here means its pass by value, use & for reference
    // normally, you wouldn't be able to change x when pass by value
    // mutable can be used to make that possible.
    // How its done is basically a local variable is created to help conduct
    // the task, thus, when the function is finished execution
    // x will not be changed.
    auto f = [=]() mutable{
        x++;
        std::cout<< x << std::endl;
    };
    // Without using mutable
    auto g = [=]() {
        int y = x;
        y++;
        std::cout << y << std::endl;
    };

    f();
    g();
    return 0;
}