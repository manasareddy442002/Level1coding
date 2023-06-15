#include <stdio.h>
int main() {
    int rollNo, physics, maths, chemistry;
    char name[50];

    printf("Enter Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter Name: ");
    scanf("%s", name);

    printf("Enter Marks for Physics: ");
    scanf("%d", &physics);

    printf("Enter Marks for Maths: ");
    scanf("%d", &maths);

    printf("Enter Marks for Chemistry: ");
    scanf("%d", &chemistry);

    int total = physics + maths + chemistry;
    float percentage = (total / 300.0) * 100;

    
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %d\n", physics);
    printf("Maths Marks: %d\n", maths);
    printf("Chemistry Marks: %d\n", chemistry);
    printf("Total Marks: %d\n", total);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
