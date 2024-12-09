#include <iostream>
#include <vector>
#include <string>
#include <cmath>

typedef std::vector<std::pair<std::string, int>> pairlist_t;

// These are the same, using is more commonly used
typedef std::string text;
using text = std::string;

namespace circle {
    const double pi = 3.14159265358979; 
};

double getHypotenuse() {
    char answer;
    double a,b;
    std::cout << "want to get Hypotenuse?";
    std::cin >> answer;
    if (answer == 'n'){
        return false;
    }
    else if (answer == 'y'){
        std::cout << "enter size A: ";
        std::cin >> a;
        std::cout << "enter size B: ";
        std::cin >> b;
        return sqrt(pow(a,2)+pow(b,2));
    }else{ 
        return 69.69;
    }

}

int main(){
    using std::cout;
    pairlist_t myPair;
    double radius = 10;
    double circumference = 2 * circle::pi * radius;

    // implicit cast (automatic)
    int a = 3.14;
    // explicit cast (Precede value with new data type)
    double b = (int)3.14;

    text myName = "pp";

    cout << circumference << "cm" << '\n';
    text name;
    cout << "whats your name?";
    std::cin >> name;
    cout << name;

    cout << "whats your full name?";
    text fullName;
    // the std::ws will prevent the extra newline at the end of the previous cin
    // left in the buffer to get caught
    std::getline(std::cin >> std::ws, fullName);
    cout << fullName;

    int int1 = 4;
    int int2 = 5;
    int int3 = 7;
    cout << std::max(int1,int2) << std::min(int2,int3) << std::endl;

    int int4 = pow(2,3);
    int int5 = sqrt(9);
    int int6 = abs(-5);
    int int7 = round(3.14);
    int int8 = ceil(3.14);
    int int9 = floor(3.14);

    double answer = getHypotenuse();
    cout << answer;

    return 0;
}

