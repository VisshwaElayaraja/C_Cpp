#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BubbleSort(int* list_ptr, size_t length) {
    if (length < 2) return;

    for (size_t i = 0; i < length-1; i++) {
        int swap_count = 0;
        for (size_t j = 0; j < length-1-i; j++) {
            if (list_ptr[j+1] < list_ptr[j]) {
                int temp = list_ptr[j];
                list_ptr[j] = list_ptr[j+1];
                list_ptr[j+1] = temp;
                swap_count++;            
            }
        }
        printf("Cycle: %zu \n", i);
        printf("    Swaps: %d \n", swap_count);
        if (swap_count == 0) break;
    }
}

int main() {
    size_t len = 5;
    int* list = (int*) malloc(len * sizeof(int));
    if (list == NULL) return 1;
    memcpy(list, (int[]){2, 8, 3, 21, 1}, len * sizeof(int));

    BubbleSort(list, len);

    printf("Sorted Array: \n");
    for (size_t k = 0; k < len; k++) {
        printf("%d ", list[k]);
    }

    free(list);
    return 0;

}
