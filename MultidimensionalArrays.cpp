#include <iostream>
#include <vector>
#include <array>

void bubbleSort(std::vector<int>& ints){
    for(int i = 0; i < ints.size() - 1; i++){
        for(int j = 0; j < ints.size() - i -1; j++){
            if (ints[j] > ints[j+1]){
                int temp = ints[j];
                ints[j] = ints[j+1];
                ints[j+1] = temp;
            }
        }
    }
}


int main(){
    // 2d array
    int** a2d = new int*[50];

    for( int i = 0; i < 50; i++ )
        a2d[i] = new int[50];

    for(int i =0; i < 50; i++)
        delete[] a2d[i];
    delete[] a2d;

    // 3d array
    int*** a3d = new int**[50];
    for(int i = 0; i < 50; i++){
        a3d[i] = new int*[50];
        for(int j = 0; j <50; j++){
            a3d[i][j] = new int[50];
        }
    }

    for(int i = 0; i < 50; i++){
        for(int j = 0; j <50; j++){
            delete[] a3d[i][j];
        }
        delete[] a3d[i];
    }
    delete[] a3d;

    // store in 1d array is the fastest
    int* a2d2 = new int[25];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            a2d2[i * 5 + j] = 2;
        }
    }
    delete[] a2d2;


    std::vector<std::vector<int>> arr(50, std::vector<int>(50));
    arr[1][2] = 0;
    std::array<std::array<int,50>,50> arr2;
    arr2[1][2] = 0;
    
    
    

    return 0;
}