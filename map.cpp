#include <iostream>
#include <vector>

#include <map>
#include <unordered_map>

// TRY TO USE UNORDERED_MAP WHENEVER IF YOU DON'T CARE ABOUT ORDER, ITS TYPICALLY FASTER 

struct CityRecord{
    CityRecord() = default;
    CityRecord(std::string city, uint64_t population, double Latitude, double Longtitude)
        : Name(city), Population(population), Latitude(Latitude), Longtitude(Longtitude){}
    std::string Name;
    uint64_t Population;
    double Latitude, Longtitude;

    // if used as the key to an ordered map, you will need to overload the < operator to make it work
    bool operator<(const CityRecord& other) const{
        return Population < other.Population;
    }
};

// hash function for unordered map to hash the key
namespace std{
template<>
struct hash<CityRecord>
{
    size_t operator()(const CityRecord& key){
        return hash<std::string>()(key.Name);
    }
};

};

int main(){
    std::vector<CityRecord> cities;
    cities.emplace_back("New York", 8000000, 2.4, 9.4);
    cities.emplace_back("London", 8000000, 2.4, 9.4);
    cities.emplace_back("Sydney", 8000000, 2.4, 9.4);
    cities.emplace_back("Moscow", 8000000, 2.4, 9.4);
    cities.emplace_back("Berlin", 999999, 6.6, 9.5);

    for(const auto& city : cities){
        if(city.Name == "Berlin"){
            std::cout << city.Population;
            break;
        }
    }

    std::map<std::string, CityRecord> CityMap;
    CityMap["New York"] = CityRecord("New York", 8000000, 2.4, 9.4);
    CityMap["London"] = CityRecord("London", 8000000, 2.4, 9.4);
    CityMap["Sydney"] = CityRecord("Sydney", 8000000, 2.4, 9.4);
    CityMap["Moscow"] = CityRecord("Moscow", 8000000, 2.4, 9.4);
    CityMap["Berlin"] = CityRecord("Berlin", 999999, 6.6, 9.5);

    CityRecord& moscowData = CityMap["Moscow"];
    std::cout << moscowData.Population << std::endl;

    std::unordered_map<std::string, CityRecord> Citymap2;
    Citymap2["New York"] = CityRecord("New York", 8000000, 2.4, 9.4);
    Citymap2["London"] = CityRecord("London", 8000000, 2.4, 9.4);
    Citymap2["Sydney"] = CityRecord("Sydney", 8000000, 2.4, 9.4);
    Citymap2["Moscow"] = CityRecord("Moscow", 8000000, 2.4, 9.4);
    Citymap2["Berlin"] = CityRecord("Berlin", 999999, 6.6, 9.5);

    CityRecord& New_YorkData = CityMap["New York"];
    std::cout << New_YorkData.Population << std::endl;

    std::map<CityRecord, uint32_t> founded;
    //founded[CityRecord("New York", 8000000, 2.4, 9.4)] = 1769;

    //                                this [] here will insert the lement when it doesn't exist,
    //                                so you can do assignment like this
    CityRecord& berlinDatae = CityMap["Berlin"];
    berlinDatae.Name = "Berlin";

    // instead of doing this
    // which avoids one copy
    CityRecord berlinDatae2;
    berlinDatae2.Name = "Berlin";
    CityMap["Berlin"] = berlinDatae;

    // in other words, when you actually want to read data form the map
    // YOU HAVE TO USE THE .at() method, because there is no const version of [] operator
    const auto& cities2 = CityMap;
    // CityRecord& someCity = cities['berlin']; This would not work
    CityRecord& SydneyData = CityMap.at("Sydney");

    // on the other hand, the data has to be there when using .at()
    // to find if the data is there, use the .find() method
    if(CityMap.find("Sydney") != CityMap.end())
        const CityRecord& SydneyData = CityMap.at("Sydney");

    // iterate thorugh the entire map, you normally woudln't do this
    // using structured binding in c++17+
    for (auto&[name, city] : CityMap){
        std::cout << name << "\n" << "Population: \n" << city.Population << "\n";
        founded[city] = 0;
    }

    // remove an element form the map
    CityMap.erase("London");

    return 0;

}