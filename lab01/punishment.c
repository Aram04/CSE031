#include <stdio.h>

int main() {
    int numLines, typoLine;
// numLines and typoLine, are declared to store the number of lines for the punishment and the line number for the typo
// Get the number of lines for the punishment from the user
    printf("Enter the number of lines for the punishment: ");
    if (scanf("%d", &numLines) != 1 || numLines <= 0) {
        printf("You entered an incorrect value for the number of lines!\n");
        return 1; // Exit with an error code
    }
// Scanf to read an integer value from the user's input.
// Checks if the input is a valid positive integer (numLines > 0)
// If input is incorrect (not a positive integer), it displays an error message 

    // Get the line number for the typo from the user
    printf("Enter the line for which we want to make a typo: ");
    if (scanf("%d", &typoLine) != 1 || typoLine <= 0 || typoLine > numLines) {
        printf("You entered an incorrect value for the line typo!\n");
        return 1; // Exit with an error code
    }

    printf("\n");

// For loop to iterate from 1 to numLines to print the punishment lines.

// Inside the loop, it checks if the current line number (i) matches the user-specified typoLine. If they match, it prints typo
// Otherwise, it prints without typo
    // Display the punishment lines
    for (int i = 1; i <= numLines; i++) {
        if (i == typoLine) {
            printf("Cading wiht is C avesone!   \n");
        } else {
            printf("Coding with C is awesome! \n");
        }
    }

    return 0; // Exit successfully
}
