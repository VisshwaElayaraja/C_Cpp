
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SensorNode {
    int node_id;
    char device_name[30];
    char location[30];
    char log_entry[100];
    struct SensorNode* next;
};


void register_node(struct SensorNode* node_ptr, int node_id) {
    node_ptr->node_id = node_id;
    printf("Enter Device Name:  ");
    fgets(node_ptr->device_name, sizeof(node_ptr->device_name), stdin);
    node_ptr->device_name[strcspn(node_ptr->device_name, "\n")] = '\0';
    printf("Enter Device Location:  ");
    fgets(node_ptr->location, sizeof(node_ptr->location), stdin);
    node_ptr->location[strcspn(node_ptr->location, "\n")] = '\0';

    if (strncmp(node_ptr->device_name, "RESET", sizeof(node_ptr->device_name)-1) == 0) {
        printf("Warning. Device Entry RESET. \n");
    }

    strncpy(node_ptr->log_entry, "Device: ", sizeof(node_ptr->log_entry)-1);
    node_ptr->log_entry[sizeof(node_ptr->log_entry)-1] = '\0';
    strncat(node_ptr->log_entry, node_ptr->device_name, sizeof(node_ptr->log_entry)-strlen(node_ptr->log_entry)-1);
    strncat(node_ptr->log_entry, " || Location: ", sizeof(node_ptr->log_entry)-strlen(node_ptr->log_entry)-1);
    strncat(node_ptr->log_entry, node_ptr->location, sizeof(node_ptr->log_entry)-strlen(node_ptr->log_entry)-1);
}

void append_node(struct SensorNode* head_ptr, int node_id) {
    struct SensorNode* new_node = (struct SensorNode*) malloc(sizeof(struct SensorNode));
    if (new_node == NULL) {
        printf("Critical. Out of RAM. \n");
    } else {
        register_node(new_node, node_id);
        new_node->next = NULL;
    
        struct SensorNode* temp = head_ptr;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display_hub_logs(struct SensorNode* head_ptr) {
    struct SensorNode* temp = head_ptr;
    while (temp != NULL) {
        printf("Node ID : #%d -> %s \n", temp->node_id, temp->log_entry);
        printf("Log Length : %zu \n", strlen(temp->log_entry));
        temp = temp->next;
    }
}

void free_hub(struct SensorNode* head_ptr) {
    struct SensorNode* temp;
    while(head_ptr != NULL) {
        temp = head_ptr;
        head_ptr = head_ptr->next;
        free(temp);
    }
}


int main() {
    struct SensorNode* Head = (struct SensorNode*) malloc(sizeof(struct SensorNode));
    if (Head == NULL) {
        printf("Critical. Out of RAM. \n");
        return 1;
    } 
    Head->next = NULL;
    register_node(Head, 101);

    append_node(Head, 102);
    display_hub_logs(Head);
    
    free_hub(Head);
}
