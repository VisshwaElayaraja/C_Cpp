#include <stdio.h>

void change_sensor_id(int* ptr) {
    *ptr = 999;
}

int main() {
    int sensor_id = 101;
    printf("Value before Change: %d\n", sensor_id);
    change_sensor_id(&sensor_id);
    printf("Value after Change: %d\n", sensor_id);
}