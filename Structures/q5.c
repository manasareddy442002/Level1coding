#include <stdio.h>
#include <string.h>

// Structure to represent a person
struct Person {
    char name[50];
    int age;
};

// Function to swap the fields of two structures using pointers
void swapStructures(struct Person* p1, struct Person* p2) {
    struct Person temp;
    strcpy(temp.name, p1->name);
    temp.age = p1->age;

    strcpy(p1->name, p2->name);
    p1->age = p2->age;

    strcpy(p2->name, temp.name);
    p2->age = temp.age;
}

int main() {
    struct Person person1, person2;

    printf("Enter details for Person 1:\n");
    printf("Name: ");
    scanf("%s", person1.name);
    printf("Age: ");
    scanf("%d", &person1.age);

    printf("\nEnter details for Person 2:\n");
    printf("Name: ");
    scanf("%s", person2.name);
    printf("Age: ");
    scanf("%d", &person2.age);

    printf("\n--- Before Swapping ---\n");
    printf("Person 1: Name: %s, Age: %d\n", person1.name, person1.age);
    printf("Person 2: Name: %s, Age: %d\n", person2.name, person2.age);

    // Swap the fields of the two structures
    swapStructures(&person1, &person2);

    printf("\n--- After Swapping ---\n");
    printf("Person 1: Name: %s, Age: %d\n", person1.name, person1.age);
    printf("Person 2: Name: %s, Age: %d\n", person2.name, person2.age);

    return 0;
}
