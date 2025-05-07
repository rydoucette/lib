// dynamic_stack.h
#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <stdbool.h>

typedef struct {
    int size;
    int num_items;
    int *items;
} DynamicStack;

bool create_stack(DynamicStack *stack, int size);
void delete_stack(DynamicStack *stack);
bool push(DynamicStack *stack, int item);
bool is_empty(DynamicStack *stack);
bool pop(DynamicStack *stack, int *val);
bool peek(DynamicStack *stack, int *val);

#endif