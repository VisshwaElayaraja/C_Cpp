#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void obtain_list_values(int* list_ptr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("Enter Value for Index '%zu': ", i);
        scanf("%d", &(list_ptr[i]));
    }
}

void InsertionSort(int* list_ptr, size_t len) {
    if (len < 2) {
        return;
    } // NITHIN TOLD.

    for (int i = 1; i < (int)len; i++) {
        for (int j = i; j > 0; j--) {
            if (list_ptr[j-1] > list_ptr[j]) {
                int temp = list_ptr[j-1];
                list_ptr[j-1] = list_ptr[j];
                list_ptr[j] = temp;
            } else {
                break;
            }
        }
    }
}

int main() {
    size_t length;
    printf("Enter Length of List:  ");
    scanf("%zu", &length);

    int* list = (int*) malloc(length * sizeof(int));
    if (list == NULL) return 1;

    obtain_list_values(list, length);

    InsertionSort(list, length);

    printf("Sorted Array: \n");
    for (size_t k = 0; k < length; k++) {
        printf("%d ", list[k]);
    }

    free(list);
    return 0;
}