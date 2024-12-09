#include <iostream>

void bubbleSort(int array[], int size);

int main(){
    int array[] = {1,3,2,9,8,5,6,7,10,4};
    int size = sizeof(array)/sizeof(array[0]);
    
    for (int i =0;i<size;i++){
        std::cout << array[i];
    }
    bubbleSort(array, size);
    for (int i =0;i<size;i++){
        std::cout << array[i];
    }

    return 0;
}


void bubbleSort(int array[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j =0; j < size-i-1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}