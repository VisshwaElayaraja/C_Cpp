
#include <stdio.h>
#include <strings.h>


struct IoTDevice {
    char device_1[30];
    char device_2[30];
    char master_log[100];
};


void input_devices(struct IoTDevice* ptr) {
    printf("Enter Name of Device 1 :  ");
    fgets(ptr->device_1, sizeof(ptr->device_1), stdin);
    ptr->device_1[strcspn(ptr->device_1, "\n")] = '\0';

    printf("Enter Name of Device 2 :  ");
    fgets(ptr->device_2, sizeof(ptr->device_2), stdin);
    ptr->device_2[strcspn(ptr->device_2, "\n")] = '\0';
}

void check_emergency_command(struct IoTDevice* ptr) {
    if (strcmp(ptr->device_1, "RESET") == 0) {
        printf("ALERT: Emergency Reset Triggered on Node A! \n");
    }
}

void construct_master_log(struct IoTDevice* ptr) {
    strncpy(ptr->master_log, "Active Nodes: ", sizeof(ptr->master_log)-1);
    ptr->master_log[sizeof(ptr->master_log)-1] = '\0';

    strncat(ptr->master_log, ptr->device_1, sizeof(ptr->master_log)-strlen(ptr->master_log)-1);
    strncat(ptr->master_log, " AND ", sizeof(ptr->master_log)-strlen(ptr->master_log)-1);
    strncat(ptr->master_log, ptr->device_2, sizeof(ptr->master_log)-strlen(ptr->master_log)-1);
}


int main() {
    struct IoTDevice itd;

    input_devices(&itd);
    check_emergency_command(&itd);
    construct_master_log(&itd);

    printf("Master Log : %s. \n", itd.master_log);
    printf("Length : %zu. \n", strlen(itd.master_log));

    return 0;
}
