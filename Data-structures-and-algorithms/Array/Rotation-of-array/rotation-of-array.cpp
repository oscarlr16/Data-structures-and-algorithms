#include "rotation-of-array.h"
#include <iostream>

void release_memory(int* arr);

int main(){

    int array[] = {0,1,2,3,4,5,6};
    int number_of_elements = sizeof(array) / sizeof(array[0]);
    int displacement_number = 10;

    std::cout << "Original array: ";
    for(int i = 0; i < number_of_elements; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Left rotation:  ";
    int* aux_array_1 = left_rotate(array, displacement_number, number_of_elements);
    for(int i = 0; i < number_of_elements; i++){
        std::cout << aux_array_1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Right rotation: ";
    int* aux_array_2 = right_rotate(array, displacement_number, number_of_elements);
    for(int i = 0; i < number_of_elements; i++){
        std::cout << aux_array_2[i] << " ";
    }
    std::cout << std::endl;
    
    release_memory(aux_array_1);
    release_memory(aux_array_2);

    return 0;
}

int* left_rotate(int arr[], int displacement_number, int number_of_elements){
    displacement_number = displacement_number % number_of_elements;
    int* new_array = new int[number_of_elements];

    for (int i = 0; i < number_of_elements; i++) {
        new_array[i] = arr[(i + displacement_number) % number_of_elements];
    }

    return new_array;
}

int* right_rotate(int arr[], int displacement_number, int number_of_elements){
    displacement_number = displacement_number % number_of_elements;
    int* new_array = new int[number_of_elements];

    for (int i = 0; i < number_of_elements; i++) {
        new_array[i] = arr[(i + (number_of_elements - displacement_number)) % number_of_elements];
    } 

    return new_array;
}


void release_memory(int* arr) {
    delete[] arr;
}