#include <stdio.h>

// Structure to represent a complex number
typedef struct {
    int real;
    int imaginary;
} Complex;

// Function to read a complex number
void readComplex(Complex *c) {
    printf("Enter real part: ");
    scanf("%d", &(c->real));
    printf("Enter imaginary part: ");
    scanf("%d", &(c->imaginary));
}

// Function to write a complex number
void writeComplex(Complex c) {
    printf("%d + %di\n", c.real, c.imaginary);
}

// Function to add two complex numbers
Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
    result.imaginary = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
    return result;
}

int main() {
    Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("Enter the second complex number:\n");
    readComplex(&num2);

    printf("\nFirst complex number: ");
    writeComplex(num1);

    printf("Second complex number: ");
    writeComplex(num2);

    sum = addComplex(num1, num2);
    printf("\nSum of the complex numbers: ");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("Product of the complex numbers: ");
    writeComplex(product);

    return 0;
}
