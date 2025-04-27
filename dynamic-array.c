#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Array of ints that holds the size of allocated memory, the number of items stored 
 * and a pointer to the allocated memory. 
 * 
 * Todo: make this typeless
*/
typedef struct {
    int size;
    int num_items;
    int *items_Ptr;
} DynamicArray;

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
*/
void add(DynamicArray *arr, int item) {
    if(arr->num_items >= arr->size) {
        // dynamically grow array
        printf("Resizing from %d to %d\n",arr->size, arr->size*2);
        arr->size *= 2;
    }
    arr->items_Ptr[arr->num_items++] = item;
}

/*
 * All items to the right of index will be shifted to the left.
 * The last element will still exist, but the array structure
 * will not be aware of it anymore
*/
bool delete(DynamicArray *arr, int index) {
    if(arr->num_items == 0 || index >= arr->size)
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

int main() {
    const int SIZE = 4;
    int *nums_ptr;
    DynamicArray array;
    create_arr(&array,SIZE);
    for(int i = 0; i < 10; i++)
        add(&array,i*3);
    print_arr(&array);
    free_arr(&array);
    return 0;
}