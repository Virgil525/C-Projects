#include <iostream>

template<typename T>
class Vector{
public:
    Vector(){
        ReAlloc(2);
    }
    Vector(size_t size){
        ReAlloc(size);
    }
    ~Vector(){
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void push_back(const T& elem){
        if (m_Size >= m_Capacity){
            ReAlloc(m_Capacity * 2);
        }
        m_Data[m_Size] = elem;
        m_Size++;
    }
    void push_back(T&& elem){
        if (m_Size >= m_Capacity){
            ReAlloc(m_Capacity * 2);
        }
        m_Data[m_Size] = std::move(elem);
        m_Size++;
    }

    template<typename... Args>
    T& emplace_back(Args&&... args){
        if (m_Size >= m_Capacity){
            ReAlloc(m_Capacity * 2);
        }

        // create the Ts in the intended memory directly
        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    T& operator[](size_t index){
        return m_Data[index];
    }
    const T& operator[](size_t index) const {
        return m_Data[index];
    }

    void PopBack(){
        if(m_Size > 0){
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void Clear(){
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();
        // or just while there is element, call popback
        m_Size = 0;
    }

    size_t size() const { return m_Size; }
    size_t capacity() const { return m_Capacity; }
private:
    void ReAlloc(size_t newCapacity){
        // 1. allocate a new block of memory
        // 2. copy/move old elements into new block
        // 3. delete
        T* newMem = (T*)::operator new(newCapacity* sizeof(T));

        //m_Size = (newCapacity < m_Size) ? newCapacity : m_Size; 
        for (size_t i = 0; i < m_Size; i++){
            new(&newMem[i]) T(std::move(m_Data[i]));
            m_Data[i].~T();
        }

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newMem;
        m_Capacity = newCapacity;
    }


private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};

struct Vector3{
    float x= 0.0f, y = 0.0f, z = 0.0f;
    int* m_MemoryBlock = nullptr;

    Vector3(){
        m_MemoryBlock = new int[5];
    }
    Vector3(float scalar) : x(scalar), y(scalar), z(scalar){
        m_MemoryBlock = new int[5];
    }
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {
        m_MemoryBlock = new int[5];
    }
    Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z){
        std::cout << "copied vector 3\n";
    }
    Vector3& operator=(const Vector3& other) = delete;
    /*
    cpy constructor
    Vector3& operator=(const Vector3& other){
        std::cout << "copied vector 3\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    */
    Vector3& operator=(Vector3&& other) noexcept {
        std::cout << "moved vector 3\n";
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        x = std::move(other.x);
        y = std::move(other.y);
        z = std::move(other.z);
        other.x = 0;
        other.y = 0;
        other.z = 0;
        return *this;
    }
    Vector3(Vector3&& other) : x(std::move(other.x)), y(std::move(other.y)), z(std::move(other.z)){
        std::cout << "moved vector 3\n";
        m_MemoryBlock = other.m_MemoryBlock;
        other.m_MemoryBlock = nullptr;
        other.x = 0;
        other.y = 0;
        other.z = 0;
    }
    ~Vector3(){
        std::cout << "Destroyed Vec3\n";
        delete[] m_MemoryBlock;
    }
};

template<typename T>
void PrintVector(const Vector<T>& vecs){
    for(size_t i = 0; i < vecs.size(); i++)
    {
        std::cout << "Element number: " << i+1 << " -->" << vecs[i] << std::endl; 
    }
    std::cout << "---------------------------------\n";
}
template<>
void PrintVector(const Vector<Vector3>& vecs){
    for(size_t i = 0; i < vecs.size(); i++)
    {
        std::cout << "Element number: " << i+1 << " --> x:" << vecs[i].x << " y: " << vecs[i].y << " z: " << vecs[i].z << std::endl; 
    }
    std::cout << "---------------------------------\n";
}

int main(){
    Vector<int> vec;
    vec.push_back(3);
    PrintVector(vec);
    /*
    Vector<std::string> vec;
    vec.push_back("ppp");
    vec.push_back("qqq");
    vec.push_back("Vector");
    vec[1] = "ppssp";
    PrintVector(vec);
    Vector<std::string> vec2(6);
    std::cout << "Size: " << vec2.size() << " Capacity: "<< vec2.capacity() << std::endl;

    Vector<Vector3> vec3s;
    vec3s.push_back(Vector3(1.0f));
    vec3s.push_back(Vector3(2,3,4));
    vec3s.push_back(Vector3());
    PrintVector(vec3s);
    vec3s.emplace_back(4,5,6);
    vec3s.emplace_back(6.9f);
    vec3s.emplace_back();
    PrintVector(vec3s);
    vec3s.Clear();
    PrintVector(vec3s);

    */
    return 0;
}