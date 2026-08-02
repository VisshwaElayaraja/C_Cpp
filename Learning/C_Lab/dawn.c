#include <stdio.h>

struct DataBlock {
    char first_name[16];
    char last_name[16];
    int age;
    char gender;    // 'M' (or) 'F'
    int weight;     // KG
};

void obtain_data(struct DataBlock* block_ptr) {
    printf("Enter your first name: ");
    scanf("%15s", block_ptr->first_name);
    printf("Enter your last name: ");
    scanf("%15s", block_ptr->last_name);       
    printf("Enter your age: ");
    scanf("%d", &(block_ptr->age));
    printf("Enter your gender (M / F): ");
    scanf(" %c", &(block_ptr->gender));
    printf("Enter your weight (kg): ");
    scanf(" %d", &(block_ptr->weight));
    printf("\n");
}

void display_data(struct DataBlock* ptr) {
    printf("First Name: %s\n", ptr->first_name);
    printf("Last Name: %s\n", ptr->last_name);
    printf("Age: %d\n", ptr->age);
    printf("Gender: %c\n", ptr->gender);
    printf("Weight: %d\n", ptr->weight);
}

int main() {
    struct DataBlock db;
    obtain_data(&db);
    display_data(&db);
}
