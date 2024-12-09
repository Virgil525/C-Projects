#include <iostream>
#include <memory>

struct AllocationMetrics{
    uint32_t TotalAllocated =0;
    uint32_t TotalFreed =0;

    uint32_t CurrentUsage() {return TotalAllocated - TotalFreed;}
};

static AllocationMetrics s_AllocationMetrics;

//place break point to see where is allocating memory
void* operator new(size_t size){
    std::cout << "Allocating " << size << " bytes\n";
    s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
}

//place break point to see where is freeing memory
void operator delete(void* memory, size_t size){
    s_AllocationMetrics.TotalFreed -= size;
    std::cout << "Freeing " << size << " bytes\n";
    free(memory);
}

struct Object{
    int x,y,z;
};

static void PrintMemoryUsage(){
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}
int main(){
    std::unique_ptr<Object> obj = std::make_unique<Object>();
    return 0;
}