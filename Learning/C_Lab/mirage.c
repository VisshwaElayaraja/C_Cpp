
#include <stdio.h>
#include <stdlib.h>

struct pHSensorLogs {
    int size;
    double* pH_readings;
};

void input_initial_reading(struct pHSensorLogs* ptr) {
    for (int i = 0; i < ptr->size; i++) {
        printf("Enter Sensor Reading #%d:  ", i+1);
        scanf("%lf", &(ptr->pH_readings[i]));
    }
}

void display_readings(struct pHSensorLogs* ptr) {
    printf("=== pH Sensor Logs === \n");
    for (int i = 0; i < ptr->size; i++) {
        printf(" #%d : %.3lf \n", i+1, ptr->pH_readings[i]);
    }
}

void loop_reading_input(struct pHSensorLogs* ptr) {
    char proceed;
    printf("Log more readings? (y/n):  ");
    scanf(" %c", &proceed);

    while (proceed == 'y') {
        int size_update;
        printf("Enter number of readings to log (extra):  ");
        scanf("%d", &size_update);

        ptr->pH_readings = (double*) realloc(ptr->pH_readings, (ptr->size + size_update) * sizeof(double));
        for (int i = ptr->size; i < (ptr->size + size_update); i++) {
            printf("Enter Sensor Reading #%d:  ", i+1);
            scanf("%lf", &(ptr->pH_readings[i]));
        }
    
        ptr->size += size_update;
        printf("Log more readings? (y/n):  ");
        scanf(" %c", &proceed);
    }

    display_readings(ptr);
}

int main() {
    struct pHSensorLogs sl;

    printf("Enter number of readings to log:  ");
    scanf("%d", &(sl.size));

    sl.pH_readings = (double*) malloc(sl.size * sizeof(double));
    if (sl.pH_readings == NULL) {
        printf("Critical Error! OS out of RAM... \n");
        return 1;
    }

    input_initial_reading(&sl);
    display_readings(&sl);
    loop_reading_input(&sl);

    free(sl.pH_readings);
    sl.pH_readings = NULL;
    
    return 0;
}