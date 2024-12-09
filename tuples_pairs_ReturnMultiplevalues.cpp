// This is in the OpenGL Series
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// needed for tuple
#include <tuple>

// one way of doing it. via pinter
/*
static void parseShader(const std::string& filepath, std::string* outVERTEXSource, std::string* outFRAGMENTSource) {
    std::ifstream stream(filepath);

    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else {
            ss[(int)type] << line <<  '\n';
        }
    }

    if(outVERTEXSource)
        *outVERTEXSource = ss[0].str();

    if(outFRAGMENTSource)
        *outFRAGMENTSource = ss[1].str();
}

int main(){
    std::string vs;
    std::string fs;
    std::string fPath = ".\\basic.shader";

    parseShader(fPath, &vs, &fs);

    std::cout << vs << std::endl;
    std::cout << fs << std::endl;
    return 0;
}
*/

// via tuple
static std::tuple<std::string, std::string> parseShader(const std::string& filepath) {
    std::ifstream stream(filepath);

    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else {
            ss[(int)type] << line <<  '\n';
        }
    }

    std::string vs = ss[0].str();
    std::string fs = ss[1].str();

    // return std::make_pair(vs,fs);
    return std::make_tuple(vs,fs);
}

int main(){
    std::string fPath = ".\\basic.shader";

    auto source = parseShader(fPath);
    std::string vs = std::get<0>(source);
    std::string fs = std::get<1>(source);

    // if returned a pair can just use this
    // std::string vsP = source.first;
    // std::string fsP = source.second;

    std::cout << vs << std::endl;
    std::cout << fs << std::endl;
    return 0;
}