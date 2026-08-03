
#include <stdio.h>
#include <stdlib.h>


struct Sensor {
    int sensor_count;
};


int main() {
    struct Sensor S;

    printf("Enter number of sensor readings: ");
    scanf("%d", &(S.sensor_count));

    float* temperature_readings = (float*) malloc (S.sensor_count * sizeof(float));
    if (temperature_readings == NULL) {
        printf("Critical Error! OS out of RAM... ");
        return 1;
    }
    
    for (int i = 0; i < S.sensor_count; i++) {
        if (i % 2 == 0) {
            temperature_readings[i] = 15.0f + i;
        } else if (i % 2 == 1) {
            temperature_readings[i] = 15.0f - i;
        }
    }

    printf("=== TEMPERATURE LOGS === \n");
    for (int i = 0; i < S.sensor_count; i++) {
        printf("Sensor #%d:  %.1f C. \n", i+1, temperature_readings[i]);
    }

    free(temperature_readings);
    temperature_readings = NULL;

    return 0;
}