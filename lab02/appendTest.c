#include <stdio.h>
#include <string.h>

/*
Return the result of appending the characters in s2 to s1.
Assumption: enough space has been allocated for s1 to store the extra
characters.
*/
char* append(char s1[], int s1_size, char s2[]) {
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    int k;

    for (k = 0; k < s2len; k++) {
        if (s1len + k < s1_size - 1) { // Check if there is enough space in s1
            s1[k + s1len] = s2[k];
        } else {
            // Handle the case where there is not enough space in s1
            break;
        }
    }

    s1[k + s1len] = '\0'; // Null-terminate the resulting string
    return s1;
}

int main() {
    char str1[20]; // Increased size to accommodate longer strings
    char str2[20]; // Increased size to accommodate longer strings
    
    while (1) {
        printf("str1 = ");
        if (!fgets(str1, sizeof(str1), stdin)) {
            return 0;
        }

        // Remove the newline character from the input
        str1[strcspn(str1, "\n")] = '\0';

        printf("str2 = ");
        if (!fgets(str2, sizeof(str2), stdin)) {
            return 0;
        }

        // Remove the newline character from the input
        str2[strcspn(str2, "\n")] = '\0';

        printf("The result of appending str2 to str1 is %s.\n", append(str1, sizeof(str1), str2));

        // Reset the strings for the next input
        str1[0] = '\0';
        str2[0] = '\0';
    }

    return 0;
}
