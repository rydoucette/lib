#include <stdio.h>
#include "dynamic-array.h"

int main() {
    DynamicArray array;
    if (!create_arr(&array, 4))
        return 1;

    for (int i = 0; i < 6; i++) {
        if (!add_item(&array, i * 2)) {
            printf("Failed to add item\n");
            free_arr(&array);
            return 1;
        }
    }

    print_arr(&array);

    printf("Deleting a[2]=>%d\n",array.items_Ptr[2]);
    delete_item(&array, 2);
    print_arr(&array);

    free_arr(&array);
    return 0;
}