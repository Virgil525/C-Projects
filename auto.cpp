#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


auto PrintName() -> char* {
    char* pp = "pp";
    return pp;
}

class Device {};
class DeviceManager{
    private:
        std::unordered_map<std::string, std::vector<Device*>> m_Devices;
    public:
        const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const{
            return m_Devices;
        }
};

int main(){
    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");
    strings.push_back("DragonFruit");
    strings.push_back("Pear");

    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++){
        std::cout << *it << std::endl;
    }

    for (auto it = strings.begin(); it != strings.end(); it++){
        std::cout << *it << std::endl;
    }

    DeviceManager dm;
    const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();
    typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMapT;
    using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
    DeviceMap dm1 = dm.GetDevices();
    DeviceMapT dm2 = dm.GetDevices();

    const auto& dm3 = dm.GetDevices();

    char* pp = PrintName();
    

    return 0;
}