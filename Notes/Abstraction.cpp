#include <iostream>

typedef std::string String;

class Stove{
    public:
        int getTemperature(){
            return temperature;
        }
        void setTemperature(int temperature){
            if(temperature < 0) this->temperature = 0;
            else this->temperature = temperature;
        }
        Stove(){}
        Stove(int temperature){
            this->setTemperature(temperature);
        }
    private:
        int temperature = 0;
};


int main(){
    Stove stove;
    Stove stove2(66);
    std::cout << stove2.getTemperature();

    std::cout << stove.getTemperature();
    stove.setTemperature(-6);
    std::cout << stove.getTemperature();
    stove.setTemperature(35);
    std::cout << stove.getTemperature();
    return 0;
}