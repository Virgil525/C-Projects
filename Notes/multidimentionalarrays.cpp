#include <iostream>

int main(){

    std::string cars[][3] = {{"3Series","5Series","7Series"},
                            {"CClass","EClass","SClass"},
                            {"A4","A6","A8"}};  

    int rows = sizeof(cars)/sizeof(cars[0]);
    int cols = sizeof(cars[0])/sizeof(cars[0][0]);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++){
            std::cout << cars[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}