#include <iostream>
#include <sstream>

class Hashtable{
public:
    struct Entry{
        std::string Data;
        std::string Status = "Never used";
    };
    static const int Size = 26;
public:
    Hashtable() = default;

    void Add(const std::string entryString){
        bool exists = Find(entryString);
        if (!exists){
            int insertIndex = FindAvilableIndex(entryString);
            m_Entries[insertIndex].Data = entryString;
            m_Entries[insertIndex].Status = "occupied";
        }
    }
    void Delete(const std::string& entryString){
        int index = 0;
        bool exists = Find(entryString, &index);
        if (exists){
            m_Entries[index].Status = "tombstone";
            m_Entries[index].Data = "";
        }    
    }

    void Print() const {
        for(int i = 0; i < Size; i++){
            if(m_Entries[i].Status == "occupied")
                std::cout << m_Entries[i].Data << " ";
        }
        /*for (int i = 0; i < Size; i++){
            std::cout << m_Entries[i].Data << " (" << m_Entries[i].Status << ")" << std::endl;
        }*/
    }

private:
    int GetIndex(const std::string& entryString) const {
        return entryString.back() - 'a';
    }

    bool Find(const std::string& entryString, int* outIndex = nullptr) const {
        int index = GetIndex(entryString);
        while(true){
            if(m_Entries[index].Data == entryString){
                if (outIndex)
                    *outIndex = index;
                return true;
            }
            if(m_Entries[index].Status == "Never used")
                return false;
            index = (index + 1) % Size;
        }
    }

    int FindAvilableIndex(const std::string& entryString) const {
        int index = GetIndex(entryString);
        while(true){
            if(m_Entries[index].Status == "Never used" || m_Entries[index].Status == "tombstone")
                return index;
            index = (index + 1) % Size;
        }
    }
private:
    Entry m_Entries[Size];
};

int main() {

    std::string input;
    getline(std::cin, input);

    Hashtable hashtable;

    std::stringstream ss(input);
    while(ss.good()){
        std::string token;
        ss >> token;

        std::string entryString = token.substr(1);
        if(token[0] == 'A'){
            hashtable.Add(entryString);
            
        }
        else if(token[0] == 'D'){
            hashtable.Delete(entryString);
        }
    }

    hashtable.Print();
    return 0;
}