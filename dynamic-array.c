#include "dynamic-array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/*
 * Creates an object which holds a dynamic array, number of
 * elements in the array, and the current size. Size and number of
 * elements can be used to reallocate memory if needed.
 */
bool create_arr(DynamicArray *arr, int size) {
    arr->size = size;
    arr->num_items = 0;
    arr->items_Ptr = (int *) malloc(size * sizeof(int));
    if(arr->items_Ptr == NULL) {
        printf("Could not allocate memory.\n");
        return false;
    }
    return true;
}

/*
 * Add item to the end of the array. Resize if necessary
 * Only overwrite the pointer if reallocation succeeds 
 */
bool add_item(DynamicArray *arr, int item) {
    printf("adding %d - at %d of %d\n", item, arr->num_items, arr->size );
    if(arr->num_items >= arr->size) {
        // dynamically grow array
        arr->size *= 2;
        int *temp = (int *) realloc(arr->items_Ptr, arr->size * sizeof(int));
        if( temp == NULL) {
            printf("Could not reallocate memory\n");
            return false;
        }
        arr->items_Ptr = temp;
    }
    arr->items_Ptr[arr->num_items++] = item;
    return true;
}

/*
 * All items to the right of index will be shifted to the left.
 * The last element will still exist, but the array structure
 * will not be aware of it anymore
 */
bool delete_item(DynamicArray *arr, int index) {
    if(arr->num_items == 0 || index < 0 || index >= arr->num_items)
        return false;

    for(int i = index; i < arr->num_items-1; i++)
        arr->items_Ptr[i] = arr->items_Ptr[i+1];

    arr->num_items--;
    return true;
}

/*
 * Deallocate the memory. Set pointer to NULL to avoid
 * accidental usage
 */
void free_arr(DynamicArray *arr) {
    free(arr->items_Ptr);
    arr->items_Ptr = NULL;
}

/*
 * go through list and print each element.
 */
void print_arr(DynamicArray *arr) {
    for(int i = 0; i < arr->num_items; i++) 
        printf("[%d]=>%d\n",i,arr->items_Ptr[i]);
}