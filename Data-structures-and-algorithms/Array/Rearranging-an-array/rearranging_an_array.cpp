#include <iostream>
#include "rearraging_an_array.h"

int main() {
    int capacity = 10; // Initial capacity
    int* p_array = new int[capacity];
    int n = 0, array_value = 0;
    // Create an auxiliary array for rearranged numbers
    int* p_aux_array = new int[n];
    int even_index = 0, odd_index = 0;

    std::cout << "Enter values (only positive values), and enter -1 to stop: " << std::endl;
    while (array_value >= 0) {
        std::cout << n + 1 << ". value: ";
        std::cin >> array_value;

        if (array_value >= 0) {
            if (n == capacity) {
                resize_array(p_array, capacity); // Resize the array if needed
            }
            p_array[n++] = array_value;
        }
    }

    odd_index = n / 2;

    for (int i = 0; i < n; i++) {
        if (p_array[i] % 2 == 0) {
            p_aux_array[even_index++] = p_array[i];
        } else {
            p_aux_array[odd_index++] = p_array[i];
        }
    }

    // Print the original array
    std::cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << p_array[i] << " ";
    }
    std::cout << std::endl;

    // Print the rearranged array
    std::cout << "Rearranged Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << p_aux_array[i] << " ";
    }
    std::cout << std::endl;

    // Release the memory
    release_memory(p_array);
    release_memory(p_aux_array);

    return 0;
}

void resize_array(int*& arr, int& capacity) {
    int* temp = new int[capacity * 2]; // Create a new array with double the capacity
    for (int i = 0; i < capacity; ++i) {
        temp[i] = arr[i]; // Copy elements to the new array
    }
    delete[] arr; // Free the old array
    arr = temp; // Update the pointer to point to the new array
    capacity *= 2; // Update the capacity
}

void release_memory(int*& arr) {
    delete[] arr;
}