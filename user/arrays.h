#ifndef ARRAYS_H
#define ARRAYS_H

// Array printing function
void print_array(int* arr, int size);

// Insertion sort for integer arrays
void sort_int_array(int* arr, int size);

// Only for arrays instatiated with malloc/
void delete_at_index(int** arr, int index, int size);

void add_at_index(int** arr, int value, int index, int size);

int binary_search(int* arr, int target, int size);

int* array_union(int* arr1, int* arr2, int size);

int* array_intersection(int* arr1, int* arr2, int size1, int size2, int *new_size);


#endif
