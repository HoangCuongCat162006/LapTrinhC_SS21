#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int age;
} Student;

int main() {
    Student students[100];
    FILE *file;
    int i = 0;
    char line[256];

    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file students.txt.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL && i < 100) {
        sscanf(line, "%d, %99[^,], %d", &students[i].id, students[i].name, &students[i].age);
        i++;
    }

    printf("Thong tin sinh vien da duoc doc tu file:\n");

    for (int j = 0; j < i; j++) {
        printf("Sinh vien %d: ID = %d, Ten = %s, Tuoi = %d\n", j + 1, students[j].id, students[j].name, students[j].age);
    }

    fclose(file);

    return 0;
}

