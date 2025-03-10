#include <stdio.h>  // Standard input-output library

#define HISTORY_SIZE 5  // Maximum history storage

// Global array to store calculation history
char history[HISTORY_SIZE][50];  
int history_count = 0;  // Keeps track of history entries

// Function to perform calculations
void calculate(char operation, double num1, double num2, double *result) {
    switch (operation) {
        case '+':
            *result = num1 + num2;
            break;
        case '-':
            *result = num1 - num2;
            break;
        case '*':
            *result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                *result = num1 / num2;
            else {
                printf("Error: Division by zero is not allowed.\n");
                return;
            }
            break;
        case '%':  // Modulo operation for whole numbers only
            if ((int)num1 == num1 && (int)num2 == num2 && num2 != 0) {
                *result = (int)num1 % (int)num2;
            } else {
                printf("Error: Modulo is only valid for whole numbers.\n");
                return;
            }
            break;
        default:
            printf("Invalid operation. Please try again.\n");
            return;
    }

    // Store result in history (basic storage, no file)
    if (history_count < HISTORY_SIZE) {
        // Converting the result to an integer if it is a whole number
        if (*result == (int)(*result)) {
            sprintf(history[history_count], "%d %c %d = %d", (int)num1, operation, (int)num2, (int)(*result));
        } else {
            sprintf(history[history_count], "%.2lf %c %.2lf = %.2lf", num1, operation, num2, *result);
        }
        history_count++;
    }
}

// Function to display history
void displayHistory() {
    printf("\nCalculation History:\n");
    if (history_count == 0) {
        printf("No calculations yet.\n");
    } else {
        for (int i = 0; i < history_count; i++) {
            printf("%d. %s\n", i + 1, history[i]);
        }
    }
}

int main() {
    char operation;
    double num1, num2, result;
    char choice;
    int continue_program = 1;  // Variable to control loop

    printf("Welcome to the All-in-One Calculator!\n");

    // Using while loop to allow multiple calculations
    while (continue_program) {
        // Taking user input
        printf("\nEnter first number: ");
        scanf("%lf", &num1);

        printf("Enter an operator (+, -, *, /, %): ");
        scanf(" %c", &operation);  // Space before %c to consume newline

        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Calling function to perform calculation
        calculate(operation, num1, num2, &result);

        // Display result if no error occurred
        if ((operation != '/' || num2 != 0) && (operation != '%' || (int)num2 != 0)) {
            // Print integer result if the result is a whole number
            if (result == (int)result) {
                printf("Result: %d\n", (int)result);
            } else {
                printf("Result: %.2lf\n", result);
            }
        }

        // Asking user if they want to view history
        printf("\nDo you want to see previous calculations? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            displayHistory();
        }

        // Asking user if they want to continue
        printf("\nDo you want to perform another calculation? (1 for Yes, 0 for No): ");
        scanf("%d", &continue_program);  // Using an integer instead of a string
    }

    printf("Goodbye!\n");

    return 0;
}
