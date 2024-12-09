#include <iostream>
#include <memory>
#include <chrono>
#include <array>

class Timer{
    public:
        Timer(){
            m_StartTimePoint = std::chrono::high_resolution_clock::now();
        }
        ~Timer(){
            Stop();
        }

        void Stop(){
            auto EndTimePoint = std::chrono::high_resolution_clock::now();
            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();
            auto duration = end - start;
            double ms = duration * 0.001;

            std::cout<< duration << "us( " << ms << "ms )\n";
        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;

};

int main(){
    int value = 0;
    if(1){
            Timer timer;
        for (int i =0; i < 1000000; i++)
            value += 2;
    }

    // unconventional results here dky
    struct Vec2{
        float a,b;
    };
    std::cout << "Make Shared\n";
    if(1){
        Timer timer1;
        std::array<std::shared_ptr<Vec2>, 1000> arr;
        for (int i = 0; i < 1000; i++){
            arr[i] = std::make_shared<Vec2>();
        }
    }
    std::cout << "new Shared\n";
    if(1){
        Timer timer2;
        std::array<std::shared_ptr<Vec2>, 1000> arr2;
        for (int i = 0; i < 1000; i++){
            arr2[i] = std::shared_ptr<Vec2>(new Vec2());
        }
    }
    std::cout << "new Vec2\n";
    if(1){
        Timer timer3;
        std::array<Vec2*, 1000> arr3;
        for (int i = 0; i < 1000; i++){
            arr3[i] = new Vec2();
        }
    }
    std::cout << "Make Unique\n";
    if(1){
        Timer timer4;
        std::array<std::unique_ptr<Vec2>, 1000> arr4;
        for (int i = 0; i < 1000; i++){
            arr4[i] = std::make_unique<Vec2>();
        }
    }


    std::cout << value << std::endl;

    return 0;
}