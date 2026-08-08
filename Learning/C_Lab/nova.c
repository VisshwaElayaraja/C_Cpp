
#include <stdio.h>
#include <string.h>

int main() {
    char secret_pass[20] = "OMR2026";
    char user_input[20];

    printf("Enter Password:  ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = '\0';

    if (strcmp(user_input, secret_pass) == 0) {
        printf("Access Granted. Welcome... \n");
    } else {
        printf("Access Denied. Imposter... \n");
    }

    printf("User input: %s \n", user_input);
    printf("Length of user input: %zu \n", strlen(user_input));

    return 0;
}