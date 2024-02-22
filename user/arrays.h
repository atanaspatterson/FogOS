#ifndef ARRAYS_H
#define ARRAYS_H

// Array printing function
void print_array(int* arr, int size);

// Insertion sort for integer arrays
void insertion_sort_int(int* arr, int size);

void quick_sort_int(int* arr, int size);

// 
int binary_search(int* arr, int target, int size);

void array_union(int* arr1, int* arr2, int size);

void array_intersection(int* arr1, int* arr2, int size);

void add_at_index(int* arr1, int index, int value, int size);

int* delete_at_index(int* arr1, int index, int size);


#endif
