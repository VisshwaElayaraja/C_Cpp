
#include <stdio.h>
#include <string.h>

struct Strings {
    char device_name[20];
    char location[20];
    char log_entry[80];
};

void obtain_user_input(struct Strings* ptr) {
    printf("Enter Device Name:  ");
    fgets(ptr->device_name, sizeof(ptr->device_name), stdin);
    ptr->device_name[strcspn(ptr->device_name, "\n")] = '\0';

    printf("Enter Location:  ");
    fgets(ptr->location, sizeof(ptr->location), stdin);
    ptr->location[strcspn(ptr->location, "\n")] = '\0';
}

void structure_log_entry(struct Strings* ptr) {
    strncpy(ptr->log_entry, "Device : ", sizeof(ptr->log_entry)-1);
    ptr->log_entry[sizeof(ptr->log_entry)-1] = '\0';

    strncat(ptr->log_entry, ptr->device_name, sizeof(ptr->log_entry) - strlen(ptr->log_entry) - 1);
    strncat(ptr->log_entry, " | Location : ", sizeof(ptr->log_entry) - strlen(ptr->log_entry) - 1);
    strncat(ptr->log_entry, ptr->location, sizeof(ptr->log_entry) - strlen(ptr->log_entry) - 1);
}

int main() {
    struct Strings s;

    obtain_user_input(&s);
    structure_log_entry(&s);

    printf("Log Entry:  %s. \n", s.log_entry);
    printf("Length of Entry:  %zu. \n", strlen(s.log_entry));

    return 0;
}
