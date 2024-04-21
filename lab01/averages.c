#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check whether the sum of digits is even or odd
bool sum_up_to_even(int n) {
    // In case n is negative, convert it to positive
    int N = abs(n);
    int sum = 0;
    
    // Create a while loop to extract digits and calculate sum
    while (N > 0) {
        // Extract the digits
        int d = N % 10;
        // Add the digits
        sum += d;
        // Reduce the number N
        N /= 10;
    }
    
    // If sum is even, return true, otherwise return false
    return (sum % 2 == 0);
}

int main() {
    int num;
    int c = 1;
    float sum_even = 0, sum_odd = 0;
    int count_even = 0, count_odd = 0;
    
    // A do-while loop to get input from the user until 0 is entered
    do {
        // Get the input from the user based on the count c
        if (c == 1)
            printf("Please enter the %dst integer: ", c);
        else if (c == 2)
            printf("Please enter the %dnd integer: ", c);
        else if (c == 3)
            printf("Please enter the %drd integer: ", c);
        else
            printf("Please enter the %dth integer: ", c);

        // Read the input integer
        scanf("%d", &num);

        // Check if the input is not zero
        if (num != 0) {
            // Call the sum_up_to_even() method
            if (sum_up_to_even(num)) {
                // Sum the numbers whose digits sum up to even
                sum_even += num;
                // Count the numbers whose digits sum up to even
                count_even++;
            } else {
                // Sum the numbers whose digits sum up to odd
                sum_odd += num;
                // Count the numbers whose digits sum up to odd
                count_odd++;
            }
        }

        // Increment the count
        c++;
    } while (num != 0);  // Continue the loop until 0 is entered

    printf("\n");

    // Calculate the averages
    float avg_even = (count_even != 0) ? (sum_even / count_even) : 0;
    float avg_odd = (count_odd != 0) ? (sum_odd / count_odd) : 0;

    // Print the averages if there are numbers
    if (count_even != 0)
        printf("Average of inputs whose digits sum up to an even number: %0.2f\n", avg_even);
    if (count_odd != 0)
        printf("Average of inputs whose digits sum up to an odd number: %0.2f\n", avg_odd);

    // Print a message if only one input is given
    if (c == 2)
        printf("There is no average to compute");
}
