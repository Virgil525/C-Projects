#include <iostream>
#include <string>

// add PR_DEBUG to the preprocessor first
// A good real world use case, define certain code with debug mode that are 
// not going to be run in release mode
//#ifdef PR_DEBUG
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG(x)
#else
#define LOG(x)
#endif
 
#define MAIN int main(){\
    LOG("Hello");\
    return 0;\
}

MAIN