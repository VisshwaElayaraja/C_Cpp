#include <stdio.h>

int main() {
    // float voltage = 2.1;

    // if (voltage < 3.0) {
    //     printf(("CRIT. Battery Low. Shutting down."));
    // } else if (voltage == 3.3f) {
    //     printf("Optimal Power.");
    // } else {
    //     printf("Too much power.");
    // }
    // printf("\n");


    // for (int i = 1; i <= 3; i++) {
    //     printf("Pinging Cloud Server. [Attempt: %d]\n", i);
    // }

    // int battery = 100;
    // int cycle = 1;
    // while (battery >= 70) {
    //     printf("Cycle %d: Device running... Battery at %d.\n", cycle, battery);
    //     battery -= 10;
    //     cycle += 1;
    // }
    // printf("Battery Low.");

    float battery = 3.3f;
    int temp = 35;
    if (temp > 30 && battery == 3.3f) {
        printf("ALERT. Overheating.\n");
    } else {
        printf("STATUS: Safe.\n");
    }
    for (int i = 1; i <= 3; i++) {
        printf("Pinging Cloud Server... {Attempt %d}.\n", i);
    }

    return 0;

}
