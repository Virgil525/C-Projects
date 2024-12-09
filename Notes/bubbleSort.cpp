#include <iostream>

void bubbleSort(int array[], int size);

int main(){
    int array[]= {2,3,5,10,1,4,7,9,8,6};
    int size = sizeof(array) / sizeof(array[0]);
    std::cout << "original array: " << array << '\n';
    for (int element : array){
        std::cout << element << '\n';
    }
    bubbleSort(array,size);
    std::cout << "sorted array: " << array << '\n';
    for (int element : array){
        std::cout << element << '\n';
    }

}
void bubbleSort(int array[], int size){
    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}