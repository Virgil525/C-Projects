#include <iostream>

class Log {
    public:
        enum Level {
            LevelError = 0, LevelWarning, LevelInfo
        };
    private:
        Level m_logLevel = LevelInfo;
    public:
        Log(){
            
        }
        void setLevel(Level level){
            m_logLevel = level;
        }
        void Warn(const char* message){
            if (m_logLevel >= LevelWarning)
                std::cout << "[Warning]: "<<message << std::endl;
        }
        void Info(const char* message){
            if (m_logLevel >= LevelInfo)
                std::cout << "[Info]: "<<message << std::endl;
        }
        void Error(const char* message){
            if (m_logLevel >= LevelError)
                std::cout << "[Error]: "<<message << std::endl;
        }
};

int main(){
    Log log;
    log.setLevel(Log::LevelWarning);
    log.Warn("Hello, this is a warning!\n");
    log.setLevel(Log::LevelInfo);
    log.Info("This is some information :)\n");
    log.setLevel(Log::LevelError);
    log.Error("This is an error.\n");
    std::cin.get();
    

    return 0;
}