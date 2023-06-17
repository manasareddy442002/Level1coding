#include <stdio.h>

void printExponent(double x) {
    unsigned long long* ptr = (unsigned long long*)&x;
    unsigned long long exponent = (*ptr & 0x7FF0000000000000) >> 52;

    printf("Exponent in hexadecimal: 0x%llX\n", exponent);
    
    // Convert exponent to binary
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%ld",(exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
