#include <stdio.h>

struct ClimateNode {
    int node_id;
    float temperature;
    char fan_status;    // 'O' for On. 'X' for Off.
};


void calibrate_temperature(struct ClimateNode* node_pointer) {
    node_pointer->temperature -= 2.0f;
}

void automate_fan_with_temperature(struct ClimateNode* node_pointer) {
    if (node_pointer->temperature > 30.0f) {
        node_pointer->fan_status = 'O';
    } else {
        node_pointer->fan_status = 'X';
    }    
}


int main() {
    printf("===== GREEN HOUSE SYSTEM INITIALIZED ===== \n");

    struct ClimateNode cn;
    cn.fan_status = 'X';
    
    int cycles;
    int* cycle_ptr = &cycles;

    printf("Enter number of reading cycles: ");
    scanf("%d", &cycles);

    for (int i = 1; i <= *cycle_ptr; i++) {
        printf("\nEnter Sensor Data: [CYCLE %d]\n", i);

        printf("  Node ID: ");
        scanf("%d", &(cn.node_id));
        printf("  Temperature [In Celsius]: ");
        scanf("%f", &(cn.temperature));
        
        calibrate_temperature(&cn);
        automate_fan_with_temperature(&cn);

        printf("Fan Status: %c\n", cn.fan_status);
    }

    printf("\n===== Uploading Reading Data to Server ===== \n");
    for (int i = 1 ; i <= 3; i++) {
        printf("Pinging to Server... Attempt %d. \n", i);
    }
    
    return 0;
}
