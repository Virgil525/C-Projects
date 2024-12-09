#include <iostream>
#include <array>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>

int main(){
    srand(time(NULL));

    std::list<int> lint;
    lint.emplace_back(3);
    lint.emplace_back(4);
    lint.emplace_back(5);
    lint.emplace_front(2);
    lint.emplace_front(1);

    for(auto item : lint){
        std::cout << item << " ";
    }

    std::deque<int> container;
    container.emplace_back(3);
    container.emplace_front(2);
    container.emplace_back(4);
    container.emplace_back(5);
    container.emplace_front(1);
    container.insert(++container.begin(),12);

    for(auto item : container){
        std::cout << item << " ";
    }

    std::cout << "-0--------------------------" << std::endl;
    

    // set stores unique values 
    std::set<int> containerSet;
    
    containerSet.insert(rand()%6+1);
    containerSet.insert(rand()%6+1);
    containerSet.insert(rand()%6+1);
    containerSet.insert(rand()%6+1);
    containerSet.insert(rand()%6+1);
    containerSet.insert(rand()%6+1);
    for(auto item : containerSet){
        std::cout << item << " ";
    }
    
    auto results = containerSet.find(2);
    std::string result = results != containerSet.end() ? "found" : "not found"; 
    std::cout << result;
    std::cout << "\n"  << " " << containerSet.size();

    return 0;
}