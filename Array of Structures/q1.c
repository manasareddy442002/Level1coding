#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    char* token;
    int i = 0;

    // Parse the input string
    token = strtok((char*)input, " ");
    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';

        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Consume the newline character

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    printf("Enter the student details (rollno name marks): ");
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character from the input
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    parseString(input, students, size);

    // Print the array of structures
    for (int i = 0; i < size; i++) {
        printf("Student %d: Roll No: %d, Name: %s, Marks: %.2f\n", i + 1, students[i].rollno, students[i].name,
               students[i].marks);
    }

    free(students); // Don't forget to deallocate the memory

    return 0;
}
