#include <iostream>
#include <thread>

static bool s_Finished = false;

void doWork(){
    using namespace std::literals::chrono_literals;
    std::cout << "Start thread id=" << std::this_thread::get_id() << std::endl;
    while(!s_Finished){
        std::cout << "working\n";
        std::this_thread::sleep_for(0.5s);
    }
}

int main(){
    std::thread worker(doWork);
    std::cout << "Thread initialized, entering new thread";
    
    std::cin.get();
    s_Finished = true;
    worker.join();
    std::cout << "Thread finished";
    
    return 0;
}