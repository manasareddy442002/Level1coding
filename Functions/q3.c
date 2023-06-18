#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;

    // Convert the number to string for easier manipulation
    char str[5];
    sprintf(str, "%d", num);

    for (int i = 0; i < 4; i++) {
        int temp = 0;
        int multiplier = 1;

        // Construct the number by excluding the current digit
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                temp += (str[j] - '0') * multiplier;
                multiplier *= 10;
            }
        }

        if (temp > largest) {
            largest = temp;
        }
    }

    return largest;
}

int main() {
    int num;

    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largest = findLargestNumber(num);
    printf("Largest number by deleting a single digit: %d\n", largest);

    return 0;
}
