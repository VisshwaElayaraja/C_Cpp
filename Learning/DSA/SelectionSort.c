#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void SelectionSort (int* list, size_t length) {
    if (length < 2) return;

    for (size_t i = 0; i < length-1; i++) {
        size_t min_index = i;
        for (size_t j = i+1; j < length; j++) {
            if (list[j] < list[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = list[min_index];
            list[min_index] = list[i];
            list[i] = temp;
        }
    }
}

int main () {
    size_t length = 5;
    int* list = (int*) malloc(length * sizeof(int));
    if (list == NULL) return 1;
    memcpy(list, (int[]){2, 8, 3, 21, 1}, length * sizeof(int));

    SelectionSort(list, length);

    printf("Sorted Array: \n");
    for (size_t k = 0; k < length; k++) {
        printf("%d ", list[k]);
    }

    free(list);
    return 0;
}