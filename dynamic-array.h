// dynamic_array.h
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

/*
 * Array of ints that holds the size of allocated memory, the number of items stored 
 * and a pointer to the allocated memory. 
 */
typedef struct {
    int size;
    int num_items;
    int *items_Ptr;
} DynamicArray;

// Function declarations
bool create_arr(DynamicArray *arr, int size);
bool add_item(DynamicArray *arr, int item);
bool delete_item(DynamicArray *arr, int index);
void free_arr(DynamicArray *arr);
void print_arr(DynamicArray *arr);

#endif // DYNAMIC_ARRAY_H