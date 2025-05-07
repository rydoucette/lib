#include "dynamic-stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Creates a stack object which holds a dynamic stack, number of elements in the stack
 * and the current size. Size annd number elements can be used to reallocate memmory if 
 * needed.
 */
bool create_stack(DynamicStack *stack, int size) {
    stack->num_items = 0;
    stack->size = size;
    stack->items = (int *) malloc(size * sizeof(int));
    if(stack->items == NULL) {
        printf("Could not allocate memory.\n");
        return false;
    }
    return true;
}

/*
 * Free stack from memory
 */
void delete_stack(DynamicStack *stack) {
    free(stack->items);
}

/*
 *  Add element to the top of the stack
 */
bool push(DynamicStack *stack, int item) {
    if(stack->num_items >= stack->size) {
        stack->size *= 2;
        int *temp = (int *) realloc(stack->items, stack->size * sizeof(int));
        if(temp == NULL) {
            printf("Could not reallocate memory\n");
            return false;
        }
        stack->items = temp;
    }
    stack->items[stack->num_items++] = item;
    return true;
}

/*
 * Check if the stack is empty
 */
bool is_empty(DynamicStack *stack) {
    return stack->num_items == 0;
}

/*
 * Pop off element from the top of the stack, saves it to a passed by reference variable
 * Returns true on success, false if the stack is empty
 */
bool pop(DynamicStack *stack, int *val) {
    if(is_empty(stack)) {
        printf("CANNOT POP OFF AN EMPTY STACK\n");
        return false;
    }
    *val = stack->items[--stack->num_items];
    return true;
}

/*
 * Read element on top of the stack, saves it to a passed by reference variable
 * Returns true on success, false if the stack is empty
 */
bool peek(DynamicStack *stack, int *val) {
    if(is_empty(stack)) {
        printf("CANNOT READ OFF AN EMPTY STACK\n");
        return false;
    }
    *val = stack->items[stack->num_items-1];
    return true;
}