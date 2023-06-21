#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    char* token;
    char* rest = strdup(input);
    int i = 0;

    while ((token = strtok_r(rest, " ", &rest)) != NULL && i < size) {
        switch (i % 3) {
            case 0:
                students[i / 3].rollno = atoi(token);
                break;
            case 1:
                strncpy(students[i / 3].name, token, sizeof(students[i / 3].name));
                break;
            case 2:
                students[i / 3].marks = atof(token);
                break;
        }
        i++;
    }

    free(rest);
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Clear the newline character from the input buffer

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    char input[100];
    printf("Enter the student details:\n");
    fgets(input, sizeof(input), stdin);

    // Remove the trailing newline character from the input
    input[strcspn(input, "\n")] = '\0';

    parseString(input, students, size);

    printf("Student details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);
    return 0;
}
