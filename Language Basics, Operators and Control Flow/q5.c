#include <stdio.h>

int bit_operations(int num, int oper_type) {
    switch (oper_type) {
        case 1:
            num |= 1;  // Set 1st bit
            break;
        case 2:
            num &= ~(1 << 31);  // Clear 31st bit
            break;
        case 3:
            num ^= (1 << 16);  // Toggle 16th bit
            break;
        default:
            printf("Error: Invalid operation type.\n");
            break;
    }
    return num;
}

int main() {
    int number, operation_type, result;

    printf("Enter an integer (32 bits): ");
    scanf("%d", &number);

    printf("Enter operation type (1, 2, or 3): ");
    scanf("%d", &operation_type);

    result = bit_operations(number, operation_type);

    printf("Result: %d\n", result);

    return 0;
}
