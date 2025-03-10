#include <stdio.h>  // Allows us to use printf and scanf

int main() {
    char choice;  // To store 'y' (yes) or 'n' (no)
    
    printf("Welcome to the Simple Calculator! 😊\n");

    // Loop to repeat calculations
    while (1) {  
        double num1, num2, result;  // Numbers and answer
        char operation;  // +, -, *, /

        // Ask for first number
        printf("\nEnter first number: ");
        scanf("%lf", &num1);

        // Ask for operation
        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &operation);  // Space before %c to avoid errors

        // Ask for second number
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Use switch for operation selection
        switch (operation) {
            case '+':  // Addition
                result = num1 + num2;
                printf("Answer: %.2lf\n", result);
                break;

            case '-':  // Subtraction
                result = num1 - num2;
                printf("Answer: %.2lf\n", result);
                break;

            case '*':  // Multiplication
                result = num1 * num2;
                printf("Answer: %.2lf\n", result);
                break;

            case '/':  // Division
                if (num2 == 0) {  // Prevent division by 0
                    printf("Oops! You cannot divide by zero. 😢\n");
                } else {
                    result = num1 / num2;
                    printf("Answer: %.2lf\n", result);
                }
                break;

            default:  // If user enters an invalid operation
                printf("Oops! That's not a valid operation. 😕\n");
        }

        // Ask if they want to calculate again
        printf("\nDo you want to do another calculation? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {  // If they say 'no'
            printf("Okay! Bye-bye! 👋😊\n");
            break;  // Stop the loop
        }
    }

    return 0;  // End the program
}
