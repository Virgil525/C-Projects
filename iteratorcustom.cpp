#include <iostream>
#include <algorithm>
#include <cstddef>

// Vector Iterator
template<typename T>
class VectorIterator {
public:
    using ValueType = T;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

    VectorIterator(PointerType ptr) : m_Ptr(ptr) {}

    VectorIterator& operator++() {
        m_Ptr++;
        return *this;
    }

    VectorIterator operator++(int) {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    VectorIterator& operator--() {
        m_Ptr--;
        return *this;
    }

    VectorIterator operator--(int) {
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index) {
        return *(m_Ptr + index);
    }

    PointerType operator->() {
        return m_Ptr;
    }

    ReferenceType operator*() {
        return *m_Ptr;
    }

    bool operator==(const VectorIterator& other) const {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const VectorIterator& other) const {
        return m_Ptr != other.m_Ptr;
    }

private:
    PointerType m_Ptr;
};

// Vector Class
template<typename T>
class Vector {
public:
    using ValueType = T;
    using Iterator = VectorIterator<T>;

    Vector() {
        // Allocate 2 elements
        ReAlloc(2);
    }

    ~Vector() {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void push_back(const T& elem) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity * 2);

        m_Data[m_Size] = elem;
        m_Size++;
    }

    void push_back(T&& elem) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity * 2);

        m_Data[m_Size] = std::move(elem);
        m_Size++;
    }

    template<typename... Args>
    T& emplace_back(Args&&... args) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity * 2);

        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    T& operator[](size_t index) {
        return m_Data[index];
    }

    const T& operator[](size_t index) const {
        return m_Data[index];
    }

    void PopBack() {
        if (m_Size > 0) {
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    Iterator begin() {
        return Iterator(m_Data);
    }

    Iterator end() {
        return Iterator(m_Data + m_Size);
    }

    void Clear() {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        m_Size = 0;
    }

    size_t size() const {
        return m_Size;
    }

    size_t capacity() const {
        return m_Capacity;
    }

private:
    void ReAlloc(size_t newCapacity) {
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; i++)
            new(&newBlock[i]) T(std::move(m_Data[i]));

        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();

        ::operator delete(m_Data);
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};

int main() {
    Vector<int> vec;
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.emplace_back(6);
    vec.push_back(7);

    std::cout << std::endl;

    for (auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}
