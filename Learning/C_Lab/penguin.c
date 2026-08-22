
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void print_list(struct Node* start_node) {
    struct Node* current_node = start_node;
    int count = 1;
    while (current_node != NULL) {
        printf("Data #%d : %d \n", count, current_node->data);
        current_node = current_node->next;
        count++;
    }
}

void append_node(struct Node* head, int new_val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_val;
    new_node->next = NULL;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void free_list(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* Head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* Tail = (struct Node*) malloc(sizeof(struct Node));

    Head->data = 50;
    Head->next = Tail;

    Tail->data = 100;
    Tail->next = NULL;

    int new_node_data;
    printf("Enter data value for new node:  ");
    scanf("%d", &new_node_data);
    append_node(Head, new_node_data);

    print_list(Head);
    free_list(Head);

    return 0;
}
