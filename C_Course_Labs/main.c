#include <stdio.h>

void calibrate_sensor_reading(double* ptr_val) {
    *ptr_val = *ptr_val + 2.17;
}

int main() {

    // int sensor_value = 212;
    // int* pointer = &sensor_value;
    // printf("value inside [sensor_value]: %d\n", sensor_value);
    // printf("Physical RAM Address: %p\n", (void*)&sensor_value);
    // printf("Address stored in pointer: %p\n", (void*)pointer);
    // printf("Value fetched thro' value dereference: %d\n", *pointer);

    double sensor_reading = 22.56;
    printf("Before Calibration: %.2lf\n", sensor_reading);
    calibrate_sensor_reading(&sensor_reading);
    printf("After Calibration: %.2lf\n", sensor_reading);

    
    return 0;
}
