#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <future>

static std::mutex s_MeshesMutex;

namespace Mesh {
    class Mesh {
    public:
        static Mesh Load(const std::string& filepath) {
            std::cout << "Loading mesh from " << filepath << std::endl;
            return Mesh();  // Return a Mesh object
        }

        // Other members of Mesh class...
    };
}



static void loadMesh(std::vector<Mesh::Mesh>& meshes, std::string filepath){
    auto mesh = Mesh::Mesh::Load(filepath);
    std::lock_guard<std::mutex> lock(s_MeshesMutex);
    meshes.push_back(mesh);
}

void LoadStuff(){
    std::ifstream stream("data.txt");
    std::vector<std::string> filePaths;
    std::string line;
    while(std::getline(stream, line))
        filePaths.push_back(line);

    for (const auto& file : filePaths)
        m_Meshes.push_back(Mesh::Mesh::Load(file));

    // load files asyncronisly 
    for (const auto& file : filePaths){
        m_Futures.push_back(std::async(std::launch::async, loadMesh, m_Meshshes, file));
    }
}

int main(){

    return 0;
}