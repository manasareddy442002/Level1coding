#include <stdio.h>

void findSmallestLargestDigits(int n, int numbers[]) {
    int i, j;
    int smallest = 9;
    int largest = 0;
    int valid = 1;

    for (i = 0; i < n; i++) {
        int currentNumber = numbers[i];

        // Find the smallest and largest digits in the current number
        while (currentNumber > 0) {
            int digit = currentNumber % 10;

            if (digit < smallest) {
                smallest = digit;
            }

            if (digit > largest) {
                largest = digit;
            }

            currentNumber /= 10;
        }
    }

    // Check if the numbers are valid
    for (i = 0; i < n; i++) {
        int currentNumber = numbers[i];

        while (currentNumber > 0) {
            int digit = currentNumber % 10;

            if (digit != smallest && digit != largest) {
                valid = 0;
                break;
            }

            currentNumber /= 10;
        }
    }

    // Print the results
    if (!valid) {
        printf("Not Valid\n");
    } else {
        printf("Smallest Digit: %d\n", smallest);
        printf("Largest Digit: %d\n", largest);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int numbers[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &numbers[i]);
    }

    findSmallestLargestDigits(n, numbers);

    return 0;
}



