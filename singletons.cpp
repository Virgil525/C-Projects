#include <iostream>

class Singleton{
private:
    Singleton() {

    }
    static Singleton s_Instance;
public:
    // disable copy constructor
    Singleton(const Singleton&) = delete;
    static Singleton& Get(){
        return s_Instance;
    }
    void Function(){}
};

class Random{
private:
    Random() {}
    static Random s_Instance;
    float m_RandomGenerator = 0.5f;
    float InternalFloat() { return m_RandomGenerator; }
public:
    // disable copy constructor
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

    // disable moving and move constructor
    Random(Random&&) = delete;
    Random& operator = (Random&&) = delete;

    static float Float() { return Get().InternalFloat(); }
    float FloatNS() { return Get().InternalFloat(); }
    static Random& Get(){ 
            static Random s_Instance;
            return s_Instance; 
        }
    void Function(){}
};

Singleton Singleton::s_Instance;

int main(){
    Singleton::Get().Function();

    float number = Random::Get().FloatNS();

    auto& random = Random::Get();
    random.FloatNS();

    float num = Random::Float();
    return 0;
}